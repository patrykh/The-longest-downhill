// The-longest-downhill.cpp : Defines the entry point for the console application.
// Wczytywanie danych
// OK - Iloœc wêz³ów <-- na tej podtawie pêtla for do wpisywania listy wez³ów
// wêze³ startowy
// lista wêz³ów
// Graf skierowany, wa¿ony
// Alg Dijkstry z wagami ujemnymi???

//#include "stdafx.h"
#include <iostream>

using namespace std;

struct element_listy
{
	element_listy * next;
	int v, w;
};

void dodaj(int dana, element_listy ** koniec)
{
	element_listy * newElement = new element_listy;
	newElement->v = dana;
	(*koniec)->next = newElement;
	(*koniec) = newElement;
}

void pobierz(element_listy ** koniec)
{
	element_listy * tmp = *koniec;
	cout << "\n" << tmp->v << "\n";
}

void usun(element_listy **poczatek)
{

	element_listy * tmp = *poczatek;
	*poczatek = (*poczatek)->next;

	cout << (*poczatek)->v << "\n";

	delete tmp;
}

int main()
{
	int ilosc_wierzcholkow = 0,
		start = 0,
		ilosc_sasiadow = 0,
		sasiad = 0,
		waga = 0,
		droga = 0,
		j = 0,
		w = 0,
		i = 0;
	bool *visited;

	element_listy **lista_sasiedztwa;
	element_listy *pw, *rw;
	element_listy *Q, *head, *tail;

	cin >> ilosc_wierzcholkow >> start;

	visited = new bool[ilosc_wierzcholkow];
	lista_sasiedztwa = new element_listy *[ilosc_wierzcholkow];

	//Inicjacja tablic dynamicznych
	for (i = 0; i < ilosc_wierzcholkow; i++){
		visited[i] = false;
		lista_sasiedztwa[i] = NULL;
	}

	// Dane wejœciowe
	for (i = 0; i < ilosc_wierzcholkow; i++){
		cin >> ilosc_sasiadow;
		for (j = 0; j < ilosc_sasiadow; j++){
			cin >> sasiad >> waga;
			pw = new element_listy;
			pw->v = sasiad;
			pw->w = waga;
			pw->next = lista_sasiedztwa[i];
			lista_sasiedztwa[i] = pw;
		}
	}

	//wyswietlanie - OK!

	//for (i = 0; i < ilosc_wierzcholkow; ++i){
	//	pw = lista_sasiedztwa[i];
	//	cout << i << ' ';
	//	while (pw){
	//		cout << pw->v;
	//		cout << ' ';
	//		cout << pw->w;
	//		pw = pw->next;
	//		cout << ' ';
	//	}
	//	cout << endl;
	//}

	//BFS

	Q = new element_listy;
	Q->next = NULL;
	Q->v = start;
	head = tail = Q;

	visited[start] = true;

	while (head){
		w = head->v;

		Q = head;
		head = head->next;
		if (!head) tail = NULL;
		delete Q;

		cout << w << ' ';

		for (pw = lista_sasiedztwa[w]; pw; pw = pw->next){
			Q = new element_listy;
			Q->next = NULL;
			Q->v = pw->v;

			if (!tail){
				head = Q;
			}else{
				tail->next = Q;
			}
			tail = Q;
			visited[pw->v] = true;
		}
	}



	// Usuwamy tablice dynamiczne
	for (i = 0; i < ilosc_wierzcholkow; i++)
	{
		pw = lista_sasiedztwa[i];
		while (pw)
		{
			rw = pw;
			pw = pw->next;
			delete rw;
		}
	}

	delete[] lista_sasiedztwa;
	delete[] visited;

	return 0;
}


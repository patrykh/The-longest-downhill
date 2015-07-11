// The-longest-downhill.cpp : Defines the entry point for the console application.
// Wczytywanie danych
// OK - Iloœc wêz³ów <-- na tej podtawie pêtla for do wpisywania listy wez³ów
// wêze³ startowy
// lista wêz³ów
// Graf skierowany, wa¿ony
// Alg Dijkstry z wagami ujemnymi???

#include "stdafx.h"
#include <iostream>

using namespace std;

struct stos
{
	stos * poprzedni;
	int dana;
};

void dodaj(stos ** root, int dana)
{
	stos * S = new stos;

	S->dana = dana;
	S->poprzedni = *root;
	*root = S;
}

void wyswietl(stos *root)
{
	stos * tmp = root;
	while (true){

		cout << tmp->dana << "\n";
		tmp = tmp->poprzedni;
		if (tmp->poprzedni == NULL){
			break;
		}
	}
}

void usun(stos **root)
{
	if (*root){
		stos * tmp = *root;
		*root = (*root)->poprzedni;
		cout << tmp->dana << endl;
		delete tmp;
	}
}

struct element_listy
{
	element_listy * next;
	int v, w;
};

int main()
{
	const int MININT = -2147483647;
	int ilosc_wierzcholkow = 0,
		start = 0,
		ilosc_sasiadow = 0,
		sasiad = 0,
		waga = 0,
		sptr = 0,
		*d,
		*p,
		*S;
	bool *QS;

	element_listy **graf;
	element_listy *pw, *rw;

	cin >> ilosc_wierzcholkow >> start;

	d = new int[ilosc_wierzcholkow];
	p = new int[ilosc_wierzcholkow];
	QS = new bool[ilosc_wierzcholkow];
	graf = new element_listy *[ilosc_wierzcholkow];
	S = new int[ilosc_wierzcholkow];
	
	//Inicjacja tablic dynamicznych
	for (int i = 0; i < ilosc_wierzcholkow; i++){
		d[i] = MININT;
		p[i] = -1;
		QS[i] = false;
		graf[i] = NULL;
	}

	// Dane wejœciowe
	for (int i = 0; i < ilosc_wierzcholkow; i++){
		cin >> ilosc_sasiadow;
		for (int j = 0; j < ilosc_sasiadow; j++){
			cin >> sasiad >> waga;
			pw = new element_listy;
			pw->v = sasiad;
			pw->w = waga;
			pw->next = graf[i];
			graf[i] = pw;
		}
	}
	
	//wyswietlanie
	for (int i = 0; i < ilosc_wierzcholkow; ++i){
		pw = graf[i];
		cout << i << ' ';
		while (pw){
			cout << pw->v;
			cout << ' ';
			cout << pw->w;
			pw = pw->next;
			cout << ' ';
		}
		cout << endl;
	}

	////Tworzenie macierzy
	//int ** A = new int*[ilosc_wierzcholkow];
	//for (int i = 0; i < ilosc_wierzcholkow; i++){
	//	A[i] = new int[ilosc_wierzcholkow];
	//}
	////wypisywanie zerami
	//for (int i = 0; i < ilosc_wierzcholkow; i++){
	//	for (int j = 0; j < ilosc_wierzcholkow; j++){
	//		A[i][j] = 0;
	//	}
	//}
	//for (int m = 0; m < ilosc_wierzcholkow; m++){
	//	cin >> ilosc_sasiadow;
	//	for (int n = 0; n < ilosc_sasiadow; n++){
	//		cin >> sasiad >> waga;
	//		A[m][sasiad] = waga;
	//	}
	//}
	////wyœwietlanie macierzy
	//cout << "-   ";
	//for (int i = 0; i < ilosc_wierzcholkow; i++) cout << i << " ";
	//cout << endl << endl;
	//for (int i = 0; i < ilosc_wierzcholkow; i++){
	//	cout << i << "   ";
	//	for (int j = 0; j < ilosc_wierzcholkow; j++){
	//		cout << A[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	////Czyszczenie pamiêci
	//for (int i = 0; i < ilosc_wierzcholkow; i++) delete[] A[i];
	//delete[] A;

	return 0;
}


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

int main()
{
	int ilosc_wierzcholkow = 0,
		start = 0,
		ilosc_sasiadow = 0,
		sasiad = 0,
		waga = 0;
	
	cin >> ilosc_wierzcholkow >> start;

	//Tworzenie macierzy
	char ** A = new char*[ilosc_wierzcholkow];
	for (int i = 0; i < ilosc_wierzcholkow; i++){
		A[i] = new char[ilosc_wierzcholkow];
	}

	//wypisywanie zerami
	for (int i = 0; i < ilosc_wierzcholkow; i++){
		for (int j = 0; j < ilosc_wierzcholkow; j++){
			A[i][j] = 0;
		}
	}

	//char ??
	//for (int m = 0; m < ilosc_wierzcholkow; m++){
	//	cin >> ilosc_sasiadow;
	//	for (int n = 0; n < ilosc_sasiadow; n++){
	//		cin >> sasiad >> waga;
	//		a[m][sasiad] = '1';
	//	}
	//}

	// INT ?? 
	for (int m = 0; m < ilosc_wierzcholkow; m++){
		cin >> ilosc_sasiadow;
		for (int n = 0; n < ilosc_sasiadow; n++){
			cin >> sasiad >> waga;
			A[m][sasiad] = waga;
		}
	}

	//wyœwietlanie macierzy
	cout << "-   ";
	for (int i = 0; i < ilosc_wierzcholkow; i++) cout << i << " ";
	cout << endl << endl;
	for (int i = 0; i < ilosc_wierzcholkow; i++){
		cout << i << "   ";
		for (int j = 0; j < ilosc_wierzcholkow; j++){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	//Czyszczenie pamiêci
	for (int i = 0; i < ilosc_wierzcholkow; i++) delete[] A[i];
	delete[] A;

	return 0;
}


// The-longest-downhill.cpp : Defines the entry point for the console application.
// Wczytywanie danych
// OK - Ilo�c w�z��w <-- na tej podtawie p�tla for do wpisywania listy wez��w
// w�ze� startowy
// lista w�z��w
// Graf skierowany, wa�ony
// Alg Dijkstry z wagami ujemnymi???

#include "stdafx.h"
#include <iostream>

using namespace std;

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
		j = 0,
		u = 0,
		i = 0,
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
	for (i = 0; i < ilosc_wierzcholkow; i++){
		d[i] = MININT;
		p[i] = -1;
		QS[i] = false;
		graf[i] = NULL;
	}

	// Dane wej�ciowe
	for (i = 0; i < ilosc_wierzcholkow; i++){
		cin >> ilosc_sasiadow;
		for (j = 0; j < ilosc_sasiadow; j++){
			cin >> sasiad >> waga;
			pw = new element_listy;
			pw->v = sasiad;
			pw->w = waga;
			pw->next = graf[i];
			graf[i] = pw;
		}
	}

	////wyswietlanie - OK!
	//for (i = 0; i < ilosc_wierzcholkow; ++i){
	//	pw = graf[i];
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

	d[start] = 0;

	for (i = 0; i < ilosc_wierzcholkow; i++){
		// Szukamy wierzcho�ka w Q o najmniejszym koszcie d
		for (j = 0; QS[j]; j++);
		for (u = j++; j < ilosc_wierzcholkow; j++){
			if (!QS[j] && (d[j] > d[u])) u = j;
		}

		// Znaleziony wierzcho�ek przenosimy do S
		QS[u] = true;

		// Modyfikujemy odpowiednio wszystkich s�siad�w u, kt�rzy s� w Q
		for (pw = graf[u]; pw; pw = pw->next){
			if (!QS[pw->v] && (d[pw->v] < d[u] + pw->w)){ // Druga opcja to por�wnanie wag
				d[pw->v] = d[u] + pw->w;
				p[pw->v] = u;
			}
		}
	}

	// Gotowe, wy�wietlamy wyniki

	//for (i = 0; i < ilosc_wierzcholkow; i++)
	//{
	//	cout << i << ": ";

	//	// �cie�k� przechodzimy od ko�ca ku pocz�tkowi,
	//	// Zapisuj�c na stosie kolejne wierzcho�ki

	//	for (j = i; j > -1; j = p[j]) S[sptr++] = j;

	//	// Wy�wietlamy �cie�k�, pobieraj�c wierzcho�ki ze stosu

	//	while (sptr) cout << S[--sptr] << " ";

	//	// Na ko�cu �cie�ki wypisujemy jej koszt

	//	cout << "$" << d[i] << endl;
	//}

	for (i = 0; i < ilosc_wierzcholkow; i++)
	{
		if (d[i] > d[i + 1]){
			cout << d[i];
		}
	}

	// Usuwamy tablice dynamiczne

	delete[] d;
	delete[] p;
	delete[] QS;
	delete[] S;

	for (i = 0; i < ilosc_wierzcholkow; i++)
	{
		pw = graf[i];
		while (pw)
		{
			rw = pw;
			pw = pw->next;
			delete rw;
		}
	}

	delete[] graf;

	return 0;
}
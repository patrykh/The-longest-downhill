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

struct el_slist
{
	el_slist * next;
	int v, w;
};

struct el_dlist
{
	el_dlist *prev,*next;
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
		j = 0,
		w = 0,
		i = 0,
		u = 0,
		*Vind,
		*droga;
	bool test;

	el_slist **graf, *ps, *rs;
	el_dlist *L, *pd, *rd;

	cin >> ilosc_wierzcholkow >> start;
	
	//Inicjacja tablic dynamicznych
	graf = new el_slist *[ilosc_wierzcholkow];
	droga = new int[ilosc_wierzcholkow];
	Vind = new int[ilosc_wierzcholkow];

	for (i = 0; i < ilosc_wierzcholkow; i++){
		graf[i] = NULL;
		droga[i] = MININT;
		Vind = 0;
	}

	// Dane wejœciowe
	for (i = 0; i < ilosc_wierzcholkow; i++){
		cin >> ilosc_sasiadow;
		for (j = 0; j < ilosc_sasiadow; j++){
			cin >> sasiad >> waga;
			ps = new el_slist;
			ps->v = sasiad;
			ps->w = waga;
			ps->next = graf[i];
			graf[i] = ps;
		}
	}

	//wyswietlanie - OK!
	//cout << "Lista sasiedztwa" << endl;
	//for (i = 0; i < ilosc_wierzcholkow; ++i){
	//	ps = graf[i];
	//	cout << i << ' ';
	//	while (ps){
	//		cout << ps->v;
	//		cout << ' ';
	//		cout << ps->w;
	//		ps = ps->next;
	//		cout << ' ';
	//	}
	//	cout << endl;
	//}
	//cout <<  "Koniec listy s¹siedztwa" << endl;
	//

	
	

	L = NULL;

	for (i = ilosc_wierzcholkow - 1; i >= 0; i--){
		pd = new el_dlist;
		pd->v = i;
		pd->next = L;
		if (pd->next) pd->next->prev = pd;
		pd->prev = NULL;
		L = pd;
	}

	do{
		test = false;

		pd = L;
		while (pd){
			if (Vind[pd->v]){
				pd = pd->next;
			}
			else{
				test = true;
				for (ps = graf[pd->v]; ps; ps = ps->next){
					Vind[ps->v]--;
				}
				cout << pd->v << " ";
				rd = pd;
				pd = pd->next;

				if (rd->next){
					rd->next->prev = rd->prev;
				}
				if (rd->prev){
					rd->prev->next = rd->next;
				}
				else{
					L = pd;
					delete rd;
				}
			}
		}
	} while (test);

	cout << endl << endl;

	// Usuwamy tablice dynamiczne
	for (i = 0; i < ilosc_wierzcholkow; i++)
	{
		ps = graf[i];
		while (ps)
		{
			rs = ps;
			ps = ps->next;
			delete rs;
		}
	}
	delete[] graf;

	pd = L;
	while (pd)
	{
		rd = pd;
		pd = pd->next;
		delete rd;
	}
	

	return 0;
}


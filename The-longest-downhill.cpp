#include <iostream>

using namespace std;

struct el_slist
{
	el_slist * next;
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
		i = 0,

		*droga,
		*poprzednik;

	el_slist **graf, *ps, *rs;

	cin >> ilosc_wierzcholkow >> start;
	
	//Inicjacja tablic dynamicznych
	graf = new el_slist *[ilosc_wierzcholkow];
	droga = new int[ilosc_wierzcholkow];
	poprzednik = new int[ilosc_wierzcholkow];

	for (i = 0; i < ilosc_wierzcholkow; i++){
		graf[i] = NULL;
		droga[i] = MININT;
		poprzednik[i] = -1;
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
	/*cout << "Lista sasiedztwa" << endl;
	for (i = 0; i < ilosc_wierzcholkow; ++i){
		ps = graf[i];
		cout << i << ' ';
		while (ps){
			cout << ps->v;
			cout << ' ';
			cout << ps->w;
			ps = ps->next;
			cout << ' ';
		}
		cout << endl;
	}
	cout <<  "Koniec listy s¹siedztwa" << endl;
	*/

	
	droga[start] = 0;

	//BFS
	el_slist *p, *q, *glowa, *ogon;

	q = new el_slist;
	q->next = NULL;
	q->v = start;
	glowa = ogon = q;

	while (glowa){
		start = glowa->v;

		q = glowa;
		glowa = glowa->next;
		if (!glowa) ogon = NULL;
		delete q;

		for (p = graf[start]; p; p = p->next){
			q = new el_slist;
			q->next = NULL;
			q->v = p->v;
			cout << q->v << " ";
			if (!ogon){
				glowa = q;
			}
			else
			{
				ogon->next = q;
			}
			ogon = q;

			//TUTAJ DOPISAC TABLICE DROGI I POPRZEDNIKÓW
			//if (droga[p->v] < )
			poprzednik[p->v] = start;
			if (droga[p->v] < droga[start] + (p->w))
			droga[p->v] = droga[start] + (p->w);
		}
	}
	cout << "\n";
	for (i = 0; i < ilosc_wierzcholkow; i++){
		//cout << poprzednik[i];
		cout << droga[i] << endl;
	}
		
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

	return 0;
}
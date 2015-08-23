//TRE� ZADANIA
//
//Ja� wybra� si� na wakacje na narty.Dzisiaj wykupi� jeden bilet na zjazd z Bardzo Wysokiej G�ry.
//Poniewa� mo�e zjecha� tylko raz, planuje jak najefektywniej go wykorzysta� i tak zaplanowa� tras�, 
//by by�a jak najd�u�sza.Trasy narciarskie na Bardzo Wysokiej G�rze maj� posta� zjazd�w ��cz�cych polany.
//Ka�dy zjazd mo�e mie� inn� d�ugo��, ale wszystkie prowadz� w d�(nie da si� wr�ci� do polany, 
//kt�r� si� ju� odwiedzi�o).Napisz program, kt�ry dla danej mapy zjazd�w wyznaczy najd�u�szy mo�liwy zjazd.
//
//Wej�cie
//
//Na wej�ciu zostanie podana ilo�� polan, oraz numer polany, do kt�rej Ja� wjecha� wyci�giem(i z kt�rej 
//startuje).Nast�pnie, dla ka�dej polany podana b�dzie ilo�� wychodz�cych z niej zjazd�w, a dla ka�dego 
//zjazdu polana docelowa i d�ugo�� zjazdu.Polany ponumerowane s� liczbami ca�kowitymi z zakresu 0, ..., 10000.
//
//Wyj�cie
//
//Na wyj�ciu nale�y wypisa� d�ugo�� najd�u�szego zjazdu.
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
		j = 0,
		i = 0,
		longest = 0,
		*droga;

	element_listy **graf, *ps, *rs;

	cin >> ilosc_wierzcholkow >> start;
	
	//Inicjacja tablic dynamicznych
	graf = new element_listy *[ilosc_wierzcholkow];
	droga = new int[ilosc_wierzcholkow];
	
	for (i = 0; i < ilosc_wierzcholkow; i++){
		graf[i] = NULL;
		droga[i] = MININT;
	}


	// Dane wej�ciowe
	for (i = 0; i < ilosc_wierzcholkow; i++){
		cin >> ilosc_sasiadow;
		for (j = 0; j < ilosc_sasiadow; j++){
			cin >> sasiad >> waga;
			ps = new element_listy;
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
	cout <<  "Koniec listy s�siedztwa" << endl;
	*/

	
	droga[start] = 0;

	//BFS
	element_listy *p, *q, *glowa, *ogon;

	q = new element_listy;
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
			q = new element_listy;
			q->next = NULL;
			q->v = p->v;
			//cout << q->v << " ";
			if (!ogon){
				glowa = q;
			}
			else
			{
				ogon->next = q;
			}
			ogon = q;

			if (droga[p->v] < droga[start] + (p->w))
			droga[p->v] = droga[start] + (p->w);

		}
	}

	for (i = 0; i < ilosc_wierzcholkow; i++){
		if (longest < droga[i]){
			longest = droga[i];
		}
	}
	cout << longest;

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
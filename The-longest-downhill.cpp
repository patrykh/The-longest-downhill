//TREŒ ZADANIA
//
//Jaœ wybra³ siê na wakacje na narty.Dzisiaj wykupi³ jeden bilet na zjazd z Bardzo Wysokiej Góry.
//Poniewa¿ mo¿e zjechaæ tylko raz, planuje jak najefektywniej go wykorzystaæ i tak zaplanowaæ trasê, 
//by by³a jak najd³u¿sza.Trasy narciarskie na Bardzo Wysokiej Górze maj¹ postaæ zjazdów ³¹cz¹cych polany.
//Ka¿dy zjazd mo¿e mieæ inn¹ d³ugoœæ, ale wszystkie prowadz¹ w dó³(nie da siê wróciæ do polany, 
//któr¹ siê ju¿ odwiedzi³o).Napisz program, który dla danej mapy zjazdów wyznaczy najd³u¿szy mo¿liwy zjazd.
//
//Wejœcie
//
//Na wejœciu zostanie podana iloœæ polan, oraz numer polany, do której Jaœ wjecha³ wyci¹giem(i z której 
//startuje).Nastêpnie, dla ka¿dej polany podana bêdzie iloœæ wychodz¹cych z niej zjazdów, a dla ka¿dego 
//zjazdu polana docelowa i d³ugoœæ zjazdu.Polany ponumerowane s¹ liczbami ca³kowitymi z zakresu 0, ..., 10000.
//
//Wyjœcie
//
//Na wyjœciu nale¿y wypisaæ d³ugoœæ najd³u¿szego zjazdu.
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


	// Dane wejœciowe
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
	cout <<  "Koniec listy s¹siedztwa" << endl;
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
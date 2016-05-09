#include <iostream>
#include <cstdlib> // srand() , rand(), RAND_MAX
#include <time.h> // srand(time(NULL));
#include <cmath>        // std::abs
using namespace std;

/*
Zadanie 13.3: Kto kupi p¹czki?

[...]

Wymagania:
Na wejœciu program pobierze liczbê dni n = 1..10000000, której dotyczy dzia³anie algorytmu.
Funkcja rand wyklucza od 0 do 3 osób w ka¿dym dniu z powodu nieobecnoœci. Ka¿dego wiêc dnia w pracy bêdzie 6..9 pracowników.
Ka¿dego dnia zostanie wybrany jeden pracownik, który kupuje p¹czki dla ka¿dego obecnego (czyli 6..9 p¹czków). Oczywiœcie wybrany pracownik musi byæ tego dnia w pracy.
Program dla ka¿dego pracownika z osobna zlicza, ile kupi³ on p¹czków oraz ile ich zjad³.
Na zakoñczenie program ma podaæ iloœæ p¹czków zjedzonych, iloœæ p¹czków kupionych oraz ró¿nicê miêdzy nimi w nastêpuj¹cej formie:
Name		Eat		Buy		Delta
Monika		158		134		24
Stefan		165		171		-6
Pati		151		140		11
...
W ostatniej linii program wypisze sumê wartoœci bezwzglêdnej zmiennych delta dla wszystkich pracowników: abs(sum(delta)). W powy¿szym przypadku suma wynosi: 24 + 6 + 11 = 41.

*/

/********************************************************************
*
*	zmienne globalne
*
*********************************************************************/

const int PRACOWNICY_MAX = 9;

int pracownicy[9] = {0};	// Id pracownika , 0..8
int zjedzone[9] = {0};		// ile paczkow zjadl pracownik
int kupione[9] = {0};		// ile kupil paczkow
bool czy_jest_w_pracy[9] = {true};// kto jest w pracy
int delta[9] = {0};			// roznica pomiedzy zjedzonymi a kupionymi paczkami danego pracownika

/********************************************************************
*
*	int losujNieobecnych()
*
*********************************************************************/

int losujNieobecnych() 
{
	
	// funkcja losuje ilosc nieobecnych osob: 0..3 osoby
	// majac ilosc osob losuje dla kazdej id nieobecnego pracownika (losowanie bez powtorzen)
	// i zaznacza nieobecnosc w tablicy 'czy_jest_w_pracy[]'
	
	
	int losowanie_nieobecnych[3] = {-1}; // zawiera pozycje ze zbioru pracowników nieobecnych , losowane bez powtorzen

	
	int ilu_nieobecnych = (rand() * (3+1)) / (RAND_MAX + 1);	// ilu bedzie nieobecnych /wartosc od 0 do 3
	cout << "nieobecni w pracy: " << ilu_nieobecnych << endl;
	
	
	
	for (int i=0; i< PRACOWNICY_MAX; i++)
	{
		czy_jest_w_pracy[i] = true;				// wyczysc tablice czy_jest_w_pracy[] z wartosci z poprzedniego losowania
	}	
	
	// -- losuj, ktorzy pracownicy bed¹ nieobecni --
	// ¿eby pomin¹c sytuacjê kiedy np. trzy losowania wskazuj¹ na tego samego pracownika
	// kazde nastepne losowanie z mniejszej (jeszcze niewylosowanej) liczby osob
	
	
	int wylosowany = 0; // 0 to te¿ ID jednego z pracownikow, jak inaczej zadeklarowac tak¹ zmienn¹	/TOASK/
	
	for (int i = 0; i < ilu_nieobecnych; i++)
	{
		wylosowany = (rand() * (PRACOWNICY_MAX-i)) / (RAND_MAX + 1); // losuje kolejno w przedzia³ach (0..8), (0..7), (0..6), (0..5)
		losowanie_nieobecnych[i] = wylosowany;	
	}
	
	
	// -- zaznacz nieobecnych pracownikow w tablicy wg wczesniejszego losowania --
	// poniewa¿ losowanie by³o 'bez powtorzen",
	// w ustalaniu pozycji pomijamy tych pracownikow, ktorzy ju¿ zostali oznaczeni jako nieobecni
	 
	int pozycja_wylosowana = 0;
	int licznik = 0; 
	int id_nieobecny = 0;
	 
	for (int i = 0; i < ilu_nieobecnych; i++)
	{
		
		pozycja_wylosowana = losowanie_nieobecnych[i];
		
		licznik = 0;
		
		
		for ( int pracownik = 0; pracownik < PRACOWNICY_MAX; pracownik++)
		{
			
			if (czy_jest_w_pracy[pracownik] == true) // w liczeniu pomijamy pracownikow zaznaczonych jako nieobecnych
			{
				
				if (licznik == pozycja_wylosowana) 
				{
					id_nieobecny = pracownik;  // zapamietaj pozycje nieobecnego w zmiennej id_pracownik
					break;
				}
				
				licznik++;		
			
			}	

		}
		
		czy_jest_w_pracy[id_nieobecny] = false; // zaznacz kolejnego nieobecnego
	}	
	
	
	// --wypisz wynik losowania--
	
	cout << __FUNCTION__ <<":";
	
	for (int i=0; i< PRACOWNICY_MAX; i++)
	{
		if (czy_jest_w_pracy[i] == true)
		{
			cout << " 1";
		}
		else
		{
			cout << " -";
		}	
	}
	cout << endl;
	
	
	return ilu_nieobecnych; // zwraca ilosc osob nieobecnych, ktore to osoby, to jest zapamietane w tablicy globalnej
}


/********************************************************************
*
*	int losujWagaLn()	
*
*********************************************************************/

int losujWagaLn() 
{
	enum kolumny { kol_id = 0, kol_delta, kol_waga, kol_granica
	};	
	
	
	int tab[4][9] = {0};
	int licznik = 0;
	

	
	// przygotuj tablice wartosci potrzebnych do losowania
	for (int i = 0; i < PRACOWNICY_MAX; i++)
	{
		
		if ( czy_jest_w_pracy[i] == true)
		{
			tab[kol_id][i] 		= i;
			tab[kol_delta][i] 	= delta[i];
			tab[kol_waga][i] 	= 0;	// w dalszej czesci: waga = wartosc^2
			tab[kol_granica][i] 	= 0;
			
			licznik++;	// ile elementow jest w tablicy
		}
		
		
	}

	
	
	int i = 0;
	int temp = 0;
	int len = licznik;	// ile osob jest w pracy i bierze udzial w losowaniu
	
	
	// sortujemy tablice (id, delta) wedlug 'delta' rosnaco ( typ bubbleSort() )
	// sortowanie jest potrzebne, poniewaz im wiêksza delta, 
	// tym wiêksz¹ wagê przypiszemy do osoby posiadaj¹cej tak¹ deltê
	// sortujemy ³¹cznie parê (delta, id) zeby pamiêtac ktore id ma dana delte
	
	for (int k = len-1 ; k > 1 ; k--)		// k - dlugosc nieposortowanej czesci tablicy, zmniejsza siê po ka¿dym przejsciu petli 'while'
	{ 	
		i = 0;	
		while ( i < k )
		{	
			if ( tab[kol_delta][i] > tab[kol_delta][i+1] ) 		// jezeli A > B (przeciwnie ni¿ w posortowanej tablicy)
			{

			
				temp = tab[kol_delta][i];				// sortuj [delta]
				tab[kol_delta][i] = tab[kol_delta][i+1];
				tab[kol_delta][i+1] = temp;
		
				temp = tab[kol_id][i];					// sortuj [id]
				tab[kol_id][i] = tab[kol_id][i+1];
				tab[kol_id][i+1] = temp;			
			
				temp = tab[kol_waga][i];				// sortuj [waga] // nie korzystamy z tej kolumny
				tab[kol_waga][i] = tab[kol_waga][i+1];
				tab[kol_waga][i+1] = temp;			
			
			} 
			
			i++;	
		}	
		//cout << endl << k << endl;
	}

	
	// wypisz posortowana kolumne delta
	cout << "delta (sort.) =   ";
	for (int i = 0; i < licznik; i++)
	{
		
		cout << tab[kol_delta][i] << " ";
			
	}
	cout << endl;
	
	
	// losujemy wartosc z przedzia³lu <1 .. exp(ile osob w pracy = licznik) )
	// ln(losowanie) = przedzial<0,licznik-1> da nam id pracownika kupujacego paczki
	// znacznie wiêksze prawdopodobienstwo wylosowania maj¹ id bliskie prawej czesci przedzialu

	
	double zakres = exp(licznik) -1;
	
		double losowanie = 1 + ((double)rand() / (RAND_MAX+1)) * zakres; // 1 + [liczba losowa <0,1) ] x zakres
		cout << "zakres: " << zakres << ", losowanie: " << losowanie << endl;


	// oblicz kto kupuje, na podstawie wylosowanej wyzej wartosci
	// UWAGA: osoba z najnizsza delt¹ (id=0) ma male szanse na wylosowanie ale > 0
	
	double ktokupuje_id = log(losowanie) / 1;


	cout << "kto dzis kupuje: " <<  tab[kol_id][(int)ktokupuje_id]<< endl << endl;

	return tab[kol_id][(int)ktokupuje_id];

}








/********************************************************************
*
*	int ktoKupujePaczki() ; proste losowanie __bez__ wag
*
*********************************************************************/

int ktoKupujePaczki() 
{
	int ile_osob_w_pracy = 0;
	
	for (int i = 0; i < PRACOWNICY_MAX; i++)
	{
		
		if ( czy_jest_w_pracy[i] == true) ile_osob_w_pracy++;  // dla jakiej liczby osob bedziemy przeprowadzali losowanie
	}
	
	int wynik_losowania = (rand() * (ile_osob_w_pracy)) / (RAND_MAX + 1); // losuje kolejno w przedzia³ach (0..8), (0..7), (0..6), (0..5)
	
	// ktory pracownik zostal wylosowany wg id (kolejnosci pracownikow w tablicy)
	
	
	int id_wylosowany = 0;
	int licznik = 0;
		
		
	for ( int pracownik = 0; pracownik < PRACOWNICY_MAX; pracownik++) // dla kazdego pracownika w tablicy
	{
		
		if (czy_jest_w_pracy[pracownik] == true) // w liczeniu pomijamy pracownikow zaznaczonych jako nieobecnych
		{
			
			if (licznik == wynik_losowania) 
			{
				id_wylosowany = pracownik;  // udostepnij pozycje wylosowanego poza petla for()
				break;
			}
			
			licznik++;		
		
		}	

	}	
	
	return id_wylosowany;
		
}


/********************************************************************
*
*	int dopiszKupionePaczki(int id_pracownika, int ile_kupil)
*
*********************************************************************/

int dopiszKupionePaczki(int id_pracownika, int ile_kupil) 
{
	
	
	kupione[id_pracownika] += ile_kupil;
	

		
}


/********************************************************************
*
*	void dopiszZjedzonePaczki()
*
*********************************************************************/

void dopiszZjedzonePaczki() 
{
	
	
	for (int i = 0; i < PRACOWNICY_MAX; i++)
	{
		
		if ( czy_jest_w_pracy[i] == true) zjedzone[i] +=1;  // kazdy z obecnych dostaje po paczku
	}
		
}


/***************************************************************************
*
*	void wypiszTablice(int * tab, int len)
*
****************************************************************************/

void wypiszTablice(int * tab, int len)
{
	// wypisuje na konsole elementy z tablicy elementow 'int'
	
	for ( int i = 0 ; i < len ; i++)
	{
		
		cout << " " << *(tab+i);
	}

	// zakoncz liniê i dodaj na koncu pusta linie
	cout << endl << endl;
	
}

/***************************************************************************
*
*	int obliczDelty()
*
****************************************************************************/

int obliczDelty()
{
	cout << __FUNCTION__ << "  ";
	
	// oblicza 'delte' - roznice pomiedzy ilosci¹ zjedzonych a zakupionych paczkow 
	// zwraca sumê wszystkich delt pracownikow , liczone jako wartosci bezwzgledne ( abs() )
	
	int suma_delt = 0;
	
	for (int i = 0; i < PRACOWNICY_MAX; i++)
	{
		
		delta[i] = zjedzone[i] - kupione[i];		
		suma_delt = suma_delt + abs( delta[i]); // sumuj wszystkie 'delta' jako wartosci bezwzgledne ( abs() )
	
		cout << delta[i] <<" ";
	
	}
	cout << endl;
	return suma_delt;	// zwraca sumê abs(delta) dla wszystkich pracownikow
}



/*********************************************************
*
*	main
*
*********************************************************/


int main()
{
	/* zmienne*/
	int liczba_dni = 10; // dla ilu dni bedziemy testowali kupowanie paczkow
	int ile_nieobecnych = 0;
	int ile_obecnych = 0;
	int id_ktokupuje = 0;
	int suma_delt = 0;
	
	srand(time(NULL));
	
	liczba_dni = 100000;
	
	for (int i=0; i< liczba_dni; i++)
	{
		cout << endl << " --------NOWY DZIEN ----------" << endl;
		
		ile_nieobecnych = losujNieobecnych();
		
		id_ktokupuje = losujWagaLn(); // losowanie z uwzglednieniem wag zaleznych od 'delta'
								// im wieksze delta tym wieksza waga
								
		//id_ktokupuje = ktoKupujePaczki(); // bez uwzglednienia wag
		
		cout << "ktoKupuje: " << id_ktokupuje << endl;
		
		dopiszZjedzonePaczki();
		
		dopiszKupionePaczki(id_ktokupuje, PRACOWNICY_MAX-ile_nieobecnych);
		
		cout << "zjedzone:    ";
		wypiszTablice(zjedzone, 9);		
		
		cout << "kupione:     ";
		wypiszTablice(kupione, 9);
		
	
		suma_delt = obliczDelty();
		
		
	}
	
	cout << "-------PODSUMOWANIE---------" << endl;
	
	cout << "suma delt: " << suma_delt << endl;
	
	//ile_obecnych = PRACOWNICY_MAX - ile_nieobecnych;
	
		
	
	
	
	
	

	return 0;
}


#include <iostream>
#include <math.h>
using namespace std;

/*
Zadanie 13.5: B�d� winna grosika

Ile razy zdarzy�o Ci si� us�ysze� w sklepie s�ynny tekst: "B�d� winna grosika"? W tym zadaniu zrobimy symulacj� tego zjawiska.

Na pocz�tku dnia masz po 10 monet ka�dego nomina�u: 5 z�, 2 z�, 1 z�, 50 gr, 20 gr, 10 gr, 5 gr, 2 gr, 1 gr.
Do twojego sklepu przychodz� klienci i zawsze p�ac� banknotami. Przez to liczba monet nie zwi�ksza si� podczas dnia. Napisz algorytm, kt�ry oblicza za pomoc� jakich nomina��w wyda� reszt�, aby obs�u�y� jak najwi�ksz� ilo�� klient�w danego dnia. Program dzia�a tak d�ugo, a� nie jest w stanie wyda� reszty z powodu zbyt ma�ej ilo�ci monet. Wydana klientowi reszta musi si� zgadza� co do grosza. Niedozwolone jest wydanie wi�kszej reszty, je�eli zosta�y w kasie monety o wi�kszym nominale ni� potrzebny.

Program musi posiada� funkcj� bool wydajReszte(float ile). Argument funkcji jest sum� reszty do wydania, w zakresie 0.01 .. 9.99 z�. Funkcja zwraca true, je�eli w kasie jest wystarczaj�ca ilo�� monet do wydania reszty. Funkcja zwraca false, je�eli nie jest w stanie wyda� reszty klientowi. Je�eli funkcja nie jest w stanie wyda� reszty, program wypisze na ekranie ilo�� transakcji, kt�re poprawnie obs�u�y�.

Dodatkowo program posiada funkcj� void reset(), dzi�ki kt�rej mo�na przywr�ci� stan kasy z pocz�tku dnia. Oznacza to, �e po wywo�aniu funkcji resetuj�cej w kasie b�dzie po 10 monet ka�dego nomina�u. Funkcja ta b�dzie wykorzystana do przywr�cenia stanu kasy w celu wykonania wielu test�w automatycznych.

Przyk�adowe argumenty wej�ciowe:

8.26 9.01 ... tu jeszcze 20 innych liczb ... 1.00 2.55 7.31

Je�eli 7.31 jest sum�, kt�ra nie mo�e by� wydana, funkcja zwr�ci false, a na ekranie zobaczymy komunikat:

Transakcji: 24

*/

/*********************************************************
*
*	zmienne globalne
*
*********************************************************/

int ilemonet[9] = {10,10,10,10,10,10,10,10,10};	// 10 szt. kazdej z monet: 5 z�, 2 z�, 1 z�, 50 gr, 20 gr, 10 gr, 5 gr, 2 gr, 1 gr
float nominal[9] = { 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
int iletransakcji = 0;


/*********************************************************
*
*	bool wydajReszte(float ile)
*
*********************************************************/

bool wydajReszte(float ile){
	
	int wydaj_szt=0;
	
	for (int i = 0; i < 10; i++)
	{
		if (ilemonet[i] > 0)
		{
			wydaj_szt = ile / nominal[i];
			
			// moze wydac tyle monet ile zostalo monet danego nominalu
			wydaj_szt = min(ilemonet[i], wydaj_szt); 
			
			// zmniejsz dany nominal w kasie o ilosc wydanych sztuk
			ilemonet[i] -= wydaj_szt;
			
			// zaktualizuj kwote do wydania
			ile = ile - wydaj_szt * nominal[i];	// !!! dlaczego nie liczy dokladnie
			
			ile = round(100*ile)/ 100;
			
			printf("wydano %4d monet o nominale %4f pozostalo %4f\n", wydaj_szt, nominal[i], ile );
	
		}
		
		// czy zostala wydana cala reszta
		// TAK = zakoncz wydawanie
		if (ile == 0) break;	
		
	}
	
	// zakoncz funkcje
	if ( ile < 0.01){	// blad zaokragle� / reprezentacji zmiennej float
		iletransakcji += 1;
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************
*
*	void reset()
*
*********************************************************/

void reset(){
	
	// wypelnia wszystkie komorki tablicy przetrzymujacej ilosc monet wartoscia 10 (szt.)
	for (int i = 0 ; i < 10; i++ )
	{
		ilemonet[i] = 10;
	}
}


/*********************************************************
*
*	main
*
*********************************************************/

int main()
{
	float kwota = 0;
	float reszta = 0;
	bool test = true;
	
	while ( test == true)
	{
		cin >> kwota;
		reszta = 10-kwota;
		test = wydajReszte(reszta);
	}
	
	printf("Transakcji: %3d", iletransakcji);
	
	reset();
	
	return 0;
}


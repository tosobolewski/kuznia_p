#include <iostream>
#include <math.h>
using namespace std;

/*
Zadanie 13.5: Bêdê winna grosika

Ile razy zdarzy³o Ci siê us³yszeæ w sklepie s³ynny tekst: "Bêdê winna grosika"? W tym zadaniu zrobimy symulacjê tego zjawiska.

Na pocz¹tku dnia masz po 10 monet ka¿dego nomina³u: 5 z³, 2 z³, 1 z³, 50 gr, 20 gr, 10 gr, 5 gr, 2 gr, 1 gr.
Do twojego sklepu przychodz¹ klienci i zawsze p³ac¹ banknotami. Przez to liczba monet nie zwiêksza siê podczas dnia. Napisz algorytm, który oblicza za pomoc¹ jakich nomina³ów wydaæ resztê, aby obs³u¿yæ jak najwiêksz¹ iloœæ klientów danego dnia. Program dzia³a tak d³ugo, a¿ nie jest w stanie wydaæ reszty z powodu zbyt ma³ej iloœci monet. Wydana klientowi reszta musi siê zgadzaæ co do grosza. Niedozwolone jest wydanie wiêkszej reszty, je¿eli zosta³y w kasie monety o wiêkszym nominale ni¿ potrzebny.

Program musi posiadaæ funkcjê bool wydajReszte(float ile). Argument funkcji jest sum¹ reszty do wydania, w zakresie 0.01 .. 9.99 z³. Funkcja zwraca true, je¿eli w kasie jest wystarczaj¹ca iloœæ monet do wydania reszty. Funkcja zwraca false, je¿eli nie jest w stanie wydaæ reszty klientowi. Je¿eli funkcja nie jest w stanie wydaæ reszty, program wypisze na ekranie iloœæ transakcji, które poprawnie obs³u¿y³.

Dodatkowo program posiada funkcjê void reset(), dziêki której mo¿na przywróciæ stan kasy z pocz¹tku dnia. Oznacza to, ¿e po wywo³aniu funkcji resetuj¹cej w kasie bêdzie po 10 monet ka¿dego nomina³u. Funkcja ta bêdzie wykorzystana do przywrócenia stanu kasy w celu wykonania wielu testów automatycznych.

Przyk³adowe argumenty wejœciowe:

8.26 9.01 ... tu jeszcze 20 innych liczb ... 1.00 2.55 7.31

Je¿eli 7.31 jest sum¹, która nie mo¿e byæ wydana, funkcja zwróci false, a na ekranie zobaczymy komunikat:

Transakcji: 24

*/

/*********************************************************
*
*	zmienne globalne
*
*********************************************************/

int ilemonet[9] = {10,10,10,10,10,10,10,10,10};	// 10 szt. kazdej z monet: 5 z³, 2 z³, 1 z³, 50 gr, 20 gr, 10 gr, 5 gr, 2 gr, 1 gr
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
	if ( ile < 0.01){	// blad zaokragleñ / reprezentacji zmiennej float
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


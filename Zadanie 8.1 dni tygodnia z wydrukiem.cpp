#include <iostream>
using namespace std;

/*
Jaki dzieñ tygodnia

Napisz funkcjê int weekDay(int year, int month, int day);która na podstawie daty poda, jaki dzieñ tygodnia przypada na t¹ datê. 
Funkcja wypisuje na ekranie dzieñ tygodnia oraz zwraca wartoœæ 1..7 (1 dla poniedzia³ku, 7 dla niedzieli).
Bierzemy pod uwagê lata 2000 - 2020. Do wykonania zadania przydatna mo¿e byæ informacja, ¿e 1 styczeñ 2000 wypad³ w sobotê.

int main()
{

	cout << weekDay(2001,1,1) << endl;
	cout << weekDay(2001,3,2) << endl;
	cout << weekDay(2000,2,7) << endl;
	cout << weekDay(2000,1,1) << endl;
	cout << weekDay(2000,1,2) << endl;
	cout << weekDay(2000,1,3) << endl;
	cout << weekDay(2000,1,4) << endl;
	cout << weekDay(2000,1,5) << endl;
	cout << weekDay(2000,1,6) << endl;
	cout << weekDay(2000,1,7) << endl;
	cout << weekDay(2000,1,8) << endl;

	return 0;
}

*/

int weekDay(int year, int month, int day)
{
	
	int y = 2000;	// rok pocz¹tkowy
	int dy = 0;		// suma liczby dni w pelnych latach
	
	while (y < year)	// sumowanie liczby dni dla pelnych lat
	{
		if ((y%4 == 0 && y%100 != 0) || y%400 == 0) // je¿eli rok jest przestepny
		{
			dy = dy + 366;
		}
		else
		{
			dy = dy + 365;
		}
		
		y++;
		
	}//koniec while (y < year)
	
	
	
	
	int m = 1;	// miesiac poczatkowy roku = styczen = 1
	int dm = 0; // suma liczby dni w pelnych miesiacach
	
	while (m < month)	// sumowanie liczby dni dla pelnych miesiecy w ostatnim roku
	{
		switch (m)
		{
			case 1:	// dla miesi¹c = 31 dni
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				dm = dm + 31;
				break;
				
			case 2:	// dla miesiac = luty
				if ((y%4 == 0 && y%100 != 0) || y%400 == 0) // je¿eli rok jest przestepny
				{
					dm = dm + 29;
				}
				else
				{
					dm = dm + 28;
				}
				break;
				
			case 4: // dla miesiac = 30 dni
			case 6:
			case 9:
			case 11:
				dm = dm + 30;
				break;
				
			default:
				cout << "blad w liczeniu dni miesiecy" << endl;
				break;
			
		}// koniec switch (m)
					
//		cout << "m" << m << endl;
		m++;
	
	}// koniec while(m < month)
	
	
	int dd = day; // liczba dni w ostatnim miesiacu
	
	
	
	
	// suma wszystkich dni od 1.01.2000 = sobota
	int d = dy + dm + dd;
	cout << "......d=....." << d << endl;
	
	// reszta z dzielenia liczby dni przez 7 daje dzien tygodnia: 1- sobota, 2 - niedziela, ...
	int dw = d % 7;
	
	
	
	cout << "dy " << dy << endl;
	cout << "dm " << dm << endl;
	cout << "dd " << dd << endl;
	cout << "d " << d << endl;	
	
	
	// funkcja drukuje dzien tygodnia
	// i zwraca wartoœæ 1..7 (1 dla poniedzia³ku, 7 dla niedzieli)
	switch (dw)
	{
		case 1:
			cout << "sobota" << endl;
			return 6; // zwraca wartosc 6 bo sobota ma wartosc 6 w wyniku zwracanym przez funkcje weekDay(..,..,..)
		case 2:
			cout << "niedziela" << endl;
			return 7;
		case 3:
			cout << "poniedzialek" << endl;
			return 1;
		case 4:
			cout << "wtorek" << endl;
			return 2;
		case 5:
			cout << "sroda" << endl;
			return 3;
		case 6:
			cout << "czwartek" << endl;
			return 4;
		case 0:
			cout << "piatek" << endl;
			return 5;
		default:
			cout << "blad w wyliczaniu dni tygodnia (obliczanie (dw))" << dw << endl;
			return 0;
	}
	
	
	
	
}// funkcja koniec int weekDay(int year, int month, int day)


int main()
{

	cout << weekDay(2001,1,1) << endl;
	cout << weekDay(2001,3,2) << endl;
	cout << weekDay(2000,2,7) << endl;
	cout << weekDay(2000,1,1) << endl;
	cout << weekDay(2000,1,2) << endl;
	cout << weekDay(2000,1,3) << endl;
	cout << weekDay(2000,1,4) << endl;
	cout << weekDay(2000,1,5) << endl;
	cout << weekDay(2000,1,6) << endl;
	cout << weekDay(2000,1,7) << endl;
	cout << weekDay(2000,1,8) << endl;

	return 0;
}


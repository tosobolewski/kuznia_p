#include <iostream>
using namespace std;

/*
Zadanie 4.1. Pêtle for()

Ka¿dy z poni¿szych punktów zrealizuj u¿ywaj¹c pêtli for.
Napisz program, który wypisze na ekranie:

w pierwszej linii 15 gwiazdek (*)
w drugiej linii liczbê bêd¹c¹ sum¹ liczb od 21 do 40
w trzeciej linii wypisze na ekranie liczby od 30 do 20 (od najwiêkszej do najmniejszej) oddzielone spacj¹.
*/

int main()
{
	
	// wypisz 15 gwiazdek
	for (int i=0; i<15; i++)
		{
			cout << "*";
		}
	cout << endl;
	
	
	
	// liczba suma liszb od 21 do 40
	int suma = 0;
	for (int i=21; i<=40; i++)
		{
			suma += i;
		}
	cout << suma << endl;
	
	
	
	// liczby od 30 do 20 (od najwiêkszej do najmniejszej) oddzielone spacj¹
	for (int i = 30;i >= 20; i--) 
		{
			cout << i;
			if (i!=20)
				{
					cout << " ";
				}
			else
				{
					cout << endl;
				}
		}
	
	
		
	// koniec main - zwraca 0
	return 0;
}

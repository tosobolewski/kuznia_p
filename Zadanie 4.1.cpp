#include <iostream>
using namespace std;

/*
Zadanie 4.1. P�tle for()

Ka�dy z poni�szych punkt�w zrealizuj u�ywaj�c p�tli for.
Napisz program, kt�ry wypisze na ekranie:

w pierwszej linii 15 gwiazdek (*)
w drugiej linii liczb� b�d�c� sum� liczb od 21 do 40
w trzeciej linii wypisze na ekranie liczby od 30 do 20 (od najwi�kszej do najmniejszej) oddzielone spacj�.
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
	
	
	
	// liczby od 30 do 20 (od najwi�kszej do najmniejszej) oddzielone spacj�
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

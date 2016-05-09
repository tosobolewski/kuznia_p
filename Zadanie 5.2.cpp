#include <iostream>
using namespace std;

/*
Zadanie 5.2. Liczba dziesi�ciocyfrowa

Napisz program, kt�ry prosi u�ytkownika o podanie liczby ca�kowitej dodatniej. Nast�pnie sprawdza, 
czy liczba ta ma 10 cyfr. Dla liczb, kt�re maj� 10 cyfr program ma wypisa� na konsoli komunikat: OK!. 
Dla liczb wi�kszych lub mniejszych program ma wypisa� na konsoli komunikat: NOT OK!.
 

    // Dla przyk�adowych liczb:
    NOT OK!     123456789
    OK!         1234567890
    NOT OK!     12345678901
    ...
*/

int main()
{
	
	long long int liczba;
	
	cout << "Podaj liczbe calkowita dodatnia :";
	cin >> liczba;
	
	//1234567890
	//1000000000
	//9999999999
	
	
	if (liczba >= 1000000000)
		{
			
			if (liczba <= 9999999999 )
					{
						cout << "OK!" << endl;
					}
			else
					{
						cout << "NOT OK!" << endl;
					}	
		}
	else 
		{
			cout << "NOT OK!" << endl;
		}
					
	
	return 0;
}


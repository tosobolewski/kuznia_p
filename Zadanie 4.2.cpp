#include <iostream>
using namespace std;

/*
Zadanie 4.2. Suma liczb naturalnych

Napisz program, kt�ry poprosi u�ytkownika o wpisanie liczby naturalnej z zakresu 1..1000. Nast�pnie wypisze na ekran tylko jedn� liczb�, kt�ra jest sum� liczb od 1 do liczby podanej przez u�ytkownika. Program obliczy sum� u�ywaj�c p�tli for(). Je�eli u�ytkownik poda liczb� mniejsz� ni� 1 lub wi�ksz� ni� 1000, program wypisze 0.

Przyk�ady:

dla liczby 3 program wypisz� liczb� 6 (1+2+3)
dla liczby 5 program wypisz� liczb� 15 (1+2+3+4+5)
dla liczby 1 program wypisz� liczb� 1 (suma liczb od 1 do 1 wynosi 1)
*/

int main()
{
	int liczba = 0;
	int suma = 0;
	cin >> liczba;	
	
	
	
	if (liczba >= 1)
		{
			if (liczba <= 1000)
					{
						for (int i=1; i <= liczba; i++)
								{
									suma += i;
								}
					}
		
		}
		
		
	cout << suma << endl;
	
	
	
	return 0;
}

#include <iostream>
using namespace std;

/*
Zadanie 3.1. Suma liczb

Napisz program, kt�ry za pomoc� polecenia cin pobiera liczby podane przez u�ytkownika. Nast�pnie 
sumuje te liczby tak d�ugo, dop�ki u�ytkownik nie poda liczby zero. Jako wynik dzia�ania program 
wypisze na ekran tylko jedn� liczb�, b�d�c� sum� liczb dotychczas wpisanych przez u�ytkownika.

Przyk�adowo dla liczb wpisanych przez u�ytkownika: 4 8 9 44 0 program wypisze na ekran liczb�: 65.
*/

int main()
{
	int liczba = 0;
	int sumaLiczb = 0;
	
	while (1)
	{
		
		cin >> liczba;
			
		if (liczba==0) 
			{
				break;
			}
		
		sumaLiczb += liczba;
		
	}
	
	cout << sumaLiczb;
	
	return 0;
}

#include <iostream>
using namespace std;

/*
Zadanie 5.3. Kt�ra litera alfabetu

Napisz program, kt�ry za pomoc� polecenia cin pobierze jedn� liter� alfabetu (a - z). Nast�pnie program 
wypisze za pomoc� polecenia cout kt�ra jest to litera alfabetu. Przyjmijmy wersj� alfabetu bez polskich znak�w. 
Program powinien obs�ugiwa� tylko 26 liter dost�pnych na standardowej klawiaturze komputerowej. W tym uk�adzie 
litera 'a' jest 1. liter� alfabetu, natomiast 'z' jest 26. liter� alfabetu.

Dla znak�w, kt�re nie s� literami, program wypisz� liczb� 0.
Program powinien poda� prawid�ow� liczb� niezale�nie od tego, czy u�ytkownik wpisze ma�� czy wielk� liter�.

Przyk�adowe liczby:
Dla znaku 'a' program wy�wietli: 1
Dla znaku 'C' program wy�wietli: 3
Dla znaku 'x' program wy�wietli: 24
Dla znaku 'Z' program wy�wietli: 26
Dla znaku '1' program wy�wietli: 0 (poniewa� '1' nie jest liter�)
*/

int main()
{
	char litera;
	int liczba;
		
	cin >> litera;
	
	liczba = litera;
	

	
	if ((liczba>=65) && (liczba <=90))
		{
			cout << (liczba - 64) << endl; 					//du�e litery A...Z (65 ... 90)
			
		}
	else if ((liczba >=97) && (liczba <= 122))
		{
			cout << (liczba - 96) << endl;					 //male litery a...z (97 ... 122)
		}
	else
		{
			cout << 0 << endl;
		}
		
		
	return 0;
}


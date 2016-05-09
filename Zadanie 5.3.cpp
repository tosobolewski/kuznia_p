#include <iostream>
using namespace std;

/*
Zadanie 5.3. Która litera alfabetu

Napisz program, który za pomoc¹ polecenia cin pobierze jedn¹ literê alfabetu (a - z). Nastêpnie program 
wypisze za pomoc¹ polecenia cout która jest to litera alfabetu. Przyjmijmy wersjê alfabetu bez polskich znaków. 
Program powinien obs³ugiwaæ tylko 26 liter dostêpnych na standardowej klawiaturze komputerowej. W tym uk³adzie 
litera 'a' jest 1. liter¹ alfabetu, natomiast 'z' jest 26. liter¹ alfabetu.

Dla znaków, które nie s¹ literami, program wypiszê liczbê 0.
Program powinien podaæ prawid³ow¹ liczbê niezale¿nie od tego, czy u¿ytkownik wpisze ma³¹ czy wielk¹ literê.

Przyk³adowe liczby:
Dla znaku 'a' program wyœwietli: 1
Dla znaku 'C' program wyœwietli: 3
Dla znaku 'x' program wyœwietli: 24
Dla znaku 'Z' program wyœwietli: 26
Dla znaku '1' program wyœwietli: 0 (poniewa¿ '1' nie jest liter¹)
*/

int main()
{
	char litera;
	int liczba;
		
	cin >> litera;
	
	liczba = litera;
	

	
	if ((liczba>=65) && (liczba <=90))
		{
			cout << (liczba - 64) << endl; 					//du¿e litery A...Z (65 ... 90)
			
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


#include <iostream>
using namespace std;

/*
Zadanie 4.2. Suma liczb naturalnych

Napisz program, który poprosi u¿ytkownika o wpisanie liczby naturalnej z zakresu 1..1000. Nastêpnie wypisze na ekran tylko jedn¹ liczbê, która jest sum¹ liczb od 1 do liczby podanej przez u¿ytkownika. Program obliczy sumê u¿ywaj¹c pêtli for(). Je¿eli u¿ytkownik poda liczbê mniejsz¹ ni¿ 1 lub wiêksz¹ ni¿ 1000, program wypisze 0.

Przyk³ady:

dla liczby 3 program wypiszê liczbê 6 (1+2+3)
dla liczby 5 program wypiszê liczbê 15 (1+2+3+4+5)
dla liczby 1 program wypiszê liczbê 1 (suma liczb od 1 do 1 wynosi 1)
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

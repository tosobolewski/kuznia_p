#include <iostream>
using namespace std;

/*
Zadanie 3.2. Odgadnij liczb�

Napisz program, kt�ry po uruchomieniu poprosi u�ytkownika o odgadni�cie liczby z zakresu od 1 do 100. 
W zale�no�ci od liczby, kt�r� wpisze u�ytkownik, program wypisze na ekran poszczeg�lne komunikaty:

Je�eli u�ytkownik poda liczb� wi�ksz� ni� 42, na ekranie pojawi si� komunikat: "Liczba X to za duzo". 
Je�eli u�ytkownik poda liczb� mniejsz� ni� 42, na ekranie pojawi si� komunikat: "Liczba X to za malo". 
Je�eli u�ytkownik poda liczb� 42, na ekranie pojawi si� komunikat: "Brawo, wygrales po X probach". 
Je�eli u�ytkownik nie wpisze liczby 42 podczas dziesi�ciu pr�b, na ekranie pojawi si� komunikat: "Niestety, nie zgadles w 10 rundach, przegrywasz".
*/

int main()
{
	int liczba = 0;
	int licznik = 0;
	
	
	//10-cio krotne pobranie danych, testy i wydruki biezace
	
	while (licznik < 10)
	{			
		licznik += 1;
		
		cout << "Podaj liczbe od 1 do 100: ";
		cin >> liczba;
	
		
		if (liczba < 42)
			{
					cout << "Liczba " << liczba << " to za malo" << endl;
			}
		else if ( liczba == 42)
			{
					break;		
			}
		else if ( liczba > 42)
			{
					cout << "Liczba " << liczba << " to za duzo" << endl;
			}				
	}	

	
	
	//wydruk koncowych rezultat�w gry 
	
	if (licznik < 10 )
		{
				cout << "Brawo, wygrales po " << licznik << " probach" << endl;
		}
	
	if (licznik == 10)
		{
				cout << "Niestety nie zgadles w " << licznik << " rundach, przegrywasz";
		}
	
	
	//koniec funkcji main zwraca 0
	
	return 0;
}

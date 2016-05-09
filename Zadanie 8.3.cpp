#include <iostream>
using namespace std;

/*
Zadanie 8.3. PESEL: Poprawna data

Zmie� program PESEL z poprzedniej lekcji w ten spos�b, aby sprawdza�, czy podana data jest prawid�owa. Sprawd� ile miesi�c ma dni i czy jest to rok przest�pny. 
Przyk�adowo data 31.04.2010 jest nieprawid�owa, poniewa� kwiecie� ma 30 dni.

Zadanie nale�y zrobi� u�ywaj�c nast�puj�cej funkcji:
bool dateValidation(int year, int month, int day);

Zmienna year b�dzie wys�ana jako liczba czterocyfrowa. W programie mo�na u�y� wi�kszej ilo�ci funkcji, ta jedna jest jednak wymagana dok�adnie w takiej postaci.


Zadanie 7.2. PESEL

Przeczytaj na wikipedii, jak zakodowany jest numer PESEL.
Nast�pnie napisz program, kt�ry poprosi u�ytkownika o podanie numeru PESEL. Maj�c numer PESEL program powinien sprawdzi� w nast�puj�cej kolejno�ci:

Czy numer PESEL sk�ada si� z 11 cyfr. Je�eli nie, program wypisze komunikat: "PESEL musi miec 11 cyfr".
Sprawdzi poprawno�� numeru poprzez zbadanie poprawno�ci cyfry kontrolnej. Je�eli numer nie jest poprawny, na konsoli zostanie wypisane: "Niepoprawna cyfra kontrolna".
Sprawdzi p�e� zakodowan� w PESELu, i wypisze j� na konsol�: "mezczyzna" lub "kobieta".
Wypisze dat� urodzenia zakodowan� w PESELu w formacie DD.MM.RRRR. Dla dnia i miesi�ca mniejszych od 10 nale�y u�y� zera wiod�cego, np. zamiast "5.1.2000" program wy�wietli "05.01.2000".
Po wy�wietleniu powy�szych komunikat�w program powinien si� zako�czy�.
*/

bool dateValidation(int year, int month, int day)
{
	if (day <=0 )
	{
		return 0;
	}

	if ((month >=1 ) && (month <= 12))
	{
	switch (month)
		{
			case 1:	// dla miesi�c = 31 dni
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day <=31) return 1;
				break;
				
			case 2:	// dla miesiac = luty
				if ((year%4 == 0 && year%100 != 0) || year%400 == 0) // je�eli rok jest przestepny
				{
					if (day <=29) {return 1;} else {return 0;};
				}
				else
				{
					if (day <=28) {return 1;} else { return 0;};
				}
				break;
				
			case 4: // dla miesiac = 30 dni
			case 6:
			case 9:
			case 11:
				if (day <=30) return 1;
				break;
				
			default:
				cout << "blad w liczeniu dni miesiecy " << month << endl;
				break;
			
		}// koniec switch (m)
	} 
	else
	{
		return 0;
	}//koniec if
	
return 0;	
	
};




int main()
{
	// podaj numer PESEL
	unsigned long long int pesel; // liczba 64 bit bez znaku: 0 .. 18 446 744 073 709 551 615
	cin >> pesel;
	
	if (0) // instrukcja wykorzystywana podczas test�w
	{
	 	pesel = 0 ;
	}
	
	// czy numer pesel ma 11 cyfr
	//
	unsigned long long int test;
	test = pesel/10000000000;
	
	if ((test < 1) || (test > 9))
	{
		cout << "PESEL musi miec 11 cyfr" << endl;
		return 0;
	}
	
	// przypisanie kolejnych 11-tu cyfr do zmiennych c1, c2, ..., c11
	//
	unsigned long long int p = pesel;
	
	int c11 = p % 10;
	p = p / 10;					// zostaje 10 cyfr
	int c10 = p % 10;
	p = p / 10;					// zostaje 9 cyfr
	int c9 = p % 10;
	p = p / 10;
	int c8 = p % 10;
	p = p / 10;
	int c7 = p % 10;
	p = p / 10;
	int c6 = p % 10;
	p = p / 10;
	int c5 = p % 10;	
	p = p / 10;
	int c4 = p % 10;
	p = p / 10;
	int c3 = p % 10;
	p = p / 10;
	int c2 = p % 10;
	p = p / 10;					// zostaje 1 cyfra
	int c1 = p % 10;
	

	// sprawdzenie poprawnosci numeru -> ( a+3b+7c+9d+e+3f+7g+9h+i+3j+k % 10 ) == 0 -> pesel poprawny jezeli ostatnia cyfra obliczonej liczby jest == 0
	//
	unsigned long long int suma_kontrolna;
	
	suma_kontrolna = (c1 + 3*c2 + 7*c3 + 9*c4 + c5 + 3*c6 + 7*c7 + 9*c8 + c9 + 3*c10 + c11) % 10;
	if (suma_kontrolna != 0)
	{
		cout << "Niepoprawna cyfra kontrolna" << endl;
		return 0;
	}
	
	// sprawdzenie plci
	//
	switch (c10)
	{
		case 0:
		case 2:
		case 4:
		case 6:
		case 8:
			cout << "kobieta" << endl;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
			cout << "mezczyzna" << endl;
			break;
		default:
			cout << "blad cyfry okreslajacej plec, c10 = " << c10 << endl;
			break;
	}
	
	// okreslanie stulecia i niezbednej korekty
	//
	int stulecie;
	int korekta;
	switch (c3)
	{
		case 8:
		case 9:
			stulecie = 1800;
			korekta = 8; 
			break;
		case 0:
		case 1:
			stulecie = 1900;
			korekta = 0;
			break;
		case 2:
		case 3:
			stulecie = 2000;
			korekta = 2;
			break;
		case 4:
		case 5:
			stulecie = 2100;
			korekta = 4;
			break;
		case 6:
		case 7:
			stulecie = 2300;
			korekta = 6;
			break;
		default:
			cout << "blad okreslania stulecia, c3 = " << c3 << endl;
			break;
	}
	
	
	// wypisz date urodzenia w formacie DD.MM.RRRR , uwzglednij korekte
	//
	cout << c5 << c6 << "." << c3 - korekta << c4 << "." << stulecie +  c1*10 + c2 << endl;
	
	if (dateValidation(stulecie +  c1*10 + c2,(c3-korekta)*10 + c4 ,c5*10+c6))
	{
		cout << "Data prawidlowa" << endl;
	}
	else
	{
		cout << "Data nieprawidlowa" << endl;
	} 
	
	// zakonczenie programu
	return 0;
}


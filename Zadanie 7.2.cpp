#include <iostream>
using namespace std;

/*
Zadanie 7.2. PESEL

Przeczytaj na wikipedii, jak zakodowany jest numer PESEL.
Nastêpnie napisz program, który poprosi u¿ytkownika o podanie numeru PESEL. Maj¹c numer PESEL program powinien sprawdziæ w nastêpuj¹cej kolejnoœci:

Czy numer PESEL sk³ada siê z 11 cyfr. Je¿eli nie, program wypisze komunikat: "PESEL musi miec 11 cyfr".
Sprawdzi poprawnoœæ numeru poprzez zbadanie poprawnoœci cyfry kontrolnej. Je¿eli numer nie jest poprawny, na konsoli zostanie wypisane: "Niepoprawna cyfra kontrolna".
Sprawdzi p³eæ zakodowan¹ w PESELu, i wypisze j¹ na konsolê: "mezczyzna" lub "kobieta".
Wypisze datê urodzenia zakodowan¹ w PESELu w formacie DD.MM.RRRR. Dla dnia i miesi¹ca mniejszych od 10 nale¿y u¿yæ zera wiod¹cego, np. zamiast "5.1.2000" program wyœwietli "05.01.2000".
Po wyœwietleniu powy¿szych komunikatów program powinien siê zakoñczyæ.
*/

int main()
{
	// podaj numer PESEL
	unsigned long long int pesel; // liczba 64 bit bez znaku: 0 .. 18 446 744 073 709 551 615
	cin >> pesel;
	
	if (0) // instrukcja wykorzystywana podczas testów
	{
	 	pesel = 0 ;
	}
	
	// czy numer pesel ma 11 cyfr // blad przy pesel zaczynajacym sie od '0' !!! -> http://forum.4programmers.net/Newbie/143398-spoj_-_problem_z_programem_pesel
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
	 
	// zakonczenie programu
	return 0;
}


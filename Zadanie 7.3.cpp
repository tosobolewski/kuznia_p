#include <iostream>
using namespace std;

/*
Zadanie 7.3. 

Zdefiniowany jest typ wyliczeniowy, kt�ry definiuje numery kierunkowe do 10 najwi�kszych miast w Polsce:

enum kierunkowe
{
	Warszawa = 22,
	Krakow = 12,
	Lodz = 42,
	Wroclaw = 71,
	Poznan = 61,
	Gdansk = 58,
	Szczecin = 91,
	Bydgoszcz = 52,
	Lublin = 81,
	Katowice = 32
};
Napisz program, kt�ry poprosi u�ytkownika o podanie numeru telefonu wraz z numerem kierunkowym, bez spacji. 
Nast�pnie je�eli dwie pierwsze cyfry numeru b�d� zgadza�y si� z jednym z numer�w zdefiniowanych w enum kierunkowe, 
program wy�wietli na ekranie nazw� odpowiedniego miasta. Je�li dwie pierwsze cyfry nie zgadzaj� si� z �adnym z miast, 
program wy�wietli komunikat: "Nieznane miasto". Dla uproszczenia mo�na za�o�y�, �e wszystkie numery maj� 9 cyfr. 

Przyk�ad dzia�ania programu:

Dla numeru "223333333" program wy�wietli: "Warszawa"
Dla numeru "912345678" program wy�wietli: "Szczecin"
Dla numeru "881112233" program wy�wietli: "Nieznane miasto"
*/




int main()
{
	
	enum kierunkowe
	{
		Warszawa = 22,
		Krakow = 12,
		Lodz = 42,
		Wroclaw = 71,
		Poznan = 61,
		Gdansk = 58,
		Szczecin = 91,
		Bydgoszcz = 52,
		Lublin = 81,
		Katowice = 32
	};
	
	
	
	cout << "Podaj numer telefonu wraz z numerem kierunkowym, bez spacji: ";
	unsigned int numerTel; 
	cin >> numerTel ;
	
	int numerKier = numerTel / 10000000;
	
	//cout << numerTel << endl;
	//cout << numerKier << endl;
	
	switch (numerKier)
	{
		case Warszawa:
			cout << "Warszawa" << endl;
			break;
		case Krakow:
			cout << "Krakow" << endl;
			break;
		case Lodz:
			cout << "Lodz" << endl;
			break;
		case Poznan:
			cout << "Poznan" << endl;
			break;
		case Gdansk:
			cout << "Gdansk" << endl;
			break;
		case Szczecin:
			cout << "Szczecin" << endl;
			break;
		case Bydgoszcz:
			cout << "Bydgoszcz" << endl;
			break;
		case Lublin:
			cout << "Lublin" << endl;
			break;
		case Katowice:
			cout << "Katowice" << endl;
			break;
		default:
			cout << "Nieznane miasto" << endl;
			break;
	}

	return 0;
}


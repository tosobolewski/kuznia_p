#include <iostream>
using namespace std;

/*
Zadanie 7.3. 

Zdefiniowany jest typ wyliczeniowy, który definiuje numery kierunkowe do 10 najwiêkszych miast w Polsce:

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
Napisz program, który poprosi u¿ytkownika o podanie numeru telefonu wraz z numerem kierunkowym, bez spacji. 
Nastêpnie je¿eli dwie pierwsze cyfry numeru bêd¹ zgadza³y siê z jednym z numerów zdefiniowanych w enum kierunkowe, 
program wyœwietli na ekranie nazwê odpowiedniego miasta. Jeœli dwie pierwsze cyfry nie zgadzaj¹ siê z ¿adnym z miast, 
program wyœwietli komunikat: "Nieznane miasto". Dla uproszczenia mo¿na za³o¿yæ, ¿e wszystkie numery maj¹ 9 cyfr. 

Przyk³ad dzia³ania programu:

Dla numeru "223333333" program wyœwietli: "Warszawa"
Dla numeru "912345678" program wyœwietli: "Szczecin"
Dla numeru "881112233" program wyœwietli: "Nieznane miasto"
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


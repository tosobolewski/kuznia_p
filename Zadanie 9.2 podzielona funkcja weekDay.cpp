#include <iostream>
using namespace std;

/* 
Zadanie 9.2. Ilosc dni roboczych miedzy dwoma datami.

Napisz funkcjê int workingDay(int initYear, int initMonth, int initDay, int finalYear, int finalMonth, int finalDay);, 
która w wyniku swojego dzia³ania zwróci liczbê dni roboczych pomiêdzy dwoma datami. Pisz¹c dni robocze mamy na myœli wszystkie dni z zakresu poniedzia³ek - pi¹tek, 
nawet jeœli dla danej daty w taki dzieñ wypada œwiêto. Np. 25 i 26 grudzieñ bêd¹ zaliczone do dni roboczych, jeœli wypadn¹ pomiêdzy poniedzia³kiem a pi¹tkiem. 

Przyk³adowe wywo³anie funkcji z nastêpuj¹cymi parametrami: workingDay(2014, 1, 1, 2014, 1, 10); powinno w wyniku zwróciæ liczbê 8.

Bierzemy pod uwagê lata 2000 - 2020. Mo¿na wykorzystaæ funkcjê z zadania 8.1.
*/


/******************************************************************************************************
*
*	funkcja zwracaj¹ca ilosc dni od bazowego dnia: SpecificBaseDay = 1.01.2000
* 	int daysFromMyBaseDay( int year, int month, int day);
* 	
* 	np. daysFromSpecificBaseDay( 2000, 01, 05) zwraca 5
*
*	funkcja sumuje ilosci dni obliczone w trzech etapach:
*	1) obliczenie ilosci dni z pe³nych lat od 1.01.2000 roku,
*	2) obliczenie ilosci dni z pozosta³ych pe³nych miesiêcy badanego okresu,
*	3) dni nale¿¹ce do badanego okresu z pozosta³ego niepe³nego miesi¹ca,
*	zwraca sumê powy¿szych.
*
*******************************************************************************************************/

int daysFromSpecificBaseDay( int year, int month, int day){

// Specific Base Day = 1.01.2000r (sobota)

//	sumowanie dni dla ka¿dego pe³nego roku w zadanym okresie
	
	int y = 2000;	// rok pocz¹tkowy
	int dy = 0;		// suma liczby dni w pelnych latach
	
	while (y < year)	// *** sumowanie w zmiennej 'dy' liczby dni ka¿dego pe³nego roku w zadanym okresie***
	{
		if ((y%4 == 0 && y%100 != 0) || y%400 == 0) // je¿eli rok jest przestepny
		{
			dy = dy + 366;
		}
		else
		{
			dy = dy + 365;
		}
		
		y++;
		
	}//koniec while (y < year)
	
	
//	sumowanie dni z ka¿dego pe³nego miesi¹ca w ostatnim niepe³nym roku badanego okresu	
	
	int m = 1;	// miesiac poczatkowy roku = styczen = 1
	int dm = 0; // pocz¹tkowa suma liczby dni w pelnych miesiacach w ostatnim roku
	
	while (m < month)	// *** sumowanie w zmiennej 'dm' liczby dni dla kolejnych pelnych miesiecy w ostatnim roku ***
	{
		switch (m)
		{
			case 1:	// dla miesiêcy = 31 dni
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				dm = dm + 31;
				break;
				
			case 2:	// dla miesiac = luty
				if ((y%4 == 0 && y%100 != 0) || y%400 == 0) // je¿eli rok jest przestepny
				{
					dm = dm + 29;
				}
				else
				{
					dm = dm + 28;
				}
				break;
				
			case 4: // dla miesiêcy = 30 dni
			case 6:
			case 9:
			case 11:
				dm = dm + 30;
				break;
				
			default:
				cout << "blad w liczeniu dni miesiecy" << endl;
				break;
			
		}// koniec switch (m)
					
		m++;
	
	}// koniec while(m < month)
	
//	dni z niepe³nego (ostatniego) miesi¹ca nale¿¹cych do badanego okresu
	
	int dd = day; // *** w zmiennej 'dd' liczba dni nale¿¹cych do badanego okresu w ostatnim niepe³nym miesiacu ***

// dodanie wszystkich wyliczonych dni: z pe³nych lat + pe³nych miesiêcy + dni z niepe³nego (ostatniego) miesi¹ca		
	
	int d = dy + dm + dd;  // sumowanie wszystkich dni od bazowego punktu odniesienia tj. _sobota_ 1.01.2000 do wskazanej daty	
	
//	zwraca wartosc 'd'
	
	return d;
}
/*
end int daysFromSpecificDay(int year, int month, int day)
*/




/**************************************************************************************
*
*	funkcja zwracaj¹ca dzien tygodnia z zadania 8.1
* 	int weekDay(int year, int month, int day)
* 	
* 	np. weekDay(2010,12,22);
*
***************************************************************************************/
 
int weekDay(int year, int month, int day)
{
	
	int dniOdDniaBazowego = daysFromSpecificBaseDay(year,month,day);  // ile dni minê³o od Dzien Bazowy = _sobota_ 1.01.2000  

	
//	modullo 7 podaje resztê - kolejny dzieñ tygodnia przesuniêty wzglêdem punktu odniesienia jakim jest Dzien Bazowy
	
	int dw = dniOdDniaBazowego % 7;  // reszta z dzielenia liczby dni przez 7 daje dzien tygodnia: 1- sobota, 2 - niedziela, ...
	
		
//	wydruk wyników i zwrot liczby okreslaj¹cej dzieñ tygodnia - wartoœæ 1..7 (1 dla poniedzia³ku, 7 dla niedzieli)
	
	switch (dw) 
	{
		case 1:
			//cout << "sobota" << endl;
			return 6; // zwraca wartosc 6 bo sobota ma wartosc 6 w wyniku zwracanym przez funkcje weekDay(..,..,..)
		case 2:
			//cout << "niedziela" << endl;
			return 7;
		case 3:
			//cout << "poniedzialek" << endl;
			return 1; 							// zwraca 1 = poniedzia³ek
		case 4:
			//cout << "wtorek" << endl;
			return 2;
		case 5:
			//cout << "sroda" << endl;
			return 3;
		case 6:
			//cout << "czwartek" << endl;
			return 4;
		case 0:
			//cout << "piatek" << endl;
			return 5;
		default:
			cout << "blad w wyliczaniu dni tygodnia (obliczanie (dw))" << dw << endl;
			return 0;
	}
	
}
/*end int weekDay(int year, int month, int day)*/




/**************************************************************************************************************
*
*	funkcja zwracaj¹ca ilosc teoretycznych dni roboczych pomiedzy dwoma datami, 
*	od godz. 0:00 pierwszego dnia do 23:59 ostatniego - tzn. (ilosc dni pomiêdzy + 1)
* 	int workingDay(int initYear, int initMonth, int initDay, int finalYear, int finalMonth, int finalDay);
* 	
* 	np. workingDay(2010,12,22,2012,10,29);
*
**************************************************************************************************************/

int workingDay(int initYear, int initMonth, int initDay, int finalYear, int finalMonth, int finalDay){
	
//	cout<< initYear << endl;
//	cout<< initMonth << endl;
//	cout<< initDay << endl;
//	cout<< finalYear << endl;
//	cout<< finalMonth << endl;
//	cout<< finalDay << endl;
	
	
	int dniPomiedzy = daysFromSpecificBaseDay(finalYear,finalMonth,finalDay) - daysFromSpecificBaseDay(initYear,initMonth,initDay) + 1;
	
	int roboczeWPelneTygodnie = (dniPomiedzy/7) * 5;	// zbadane wszystkie dni obejmuj¹ce pe³ne tygodnie 
	
	int roboczeWNiepelnyTydzien = 0;	
	
	int dniNiepelnegoTygodnia = (dniPomiedzy % 7);		
	
	
	int dzienTygodniaPierwszegoDnia = weekDay(initYear, initMonth, initDay);  // n = 1- poniedzia³ek, 2 - wtorek, ..., 7 - niedziela
		
	for(int i=0; i < dniNiepelnegoTygodnia; i++){			// petla - ile z dni niepelnego tygodnia jest dniami roboczymi ?
			if ((dzienTygodniaPierwszegoDnia + i) < 6 ){		// czy dzien jest roboczy, czyli n = 1..5
				roboczeWNiepelnyTydzien += 1;						// je¿eli roboczy to zwiekszamy licznik
			}		
	}
	
	return (roboczeWPelneTygodnie + roboczeWNiepelnyTydzien);
	
}
/*end workingDay(int initYear, int initMonth, int initDay, int finalYear, int finalMonth, int finalDay)*/


int main()
{

//	cout << "workingDay(2014,01,01,2014,01,01) =" << "   " << workingDay(2014,01,01,2014,01,01) << endl;
//	cout << "workingDay(2014,01,01,2014,01,10) =" << "   " << workingDay(2014,01,01,2014,01,10) << endl;
//	cout << "workingDay(2014,01,01,2014,01,18) =" << "   " << workingDay(2014,01,01,2014,01,18) << endl;
	
	return 0;
}


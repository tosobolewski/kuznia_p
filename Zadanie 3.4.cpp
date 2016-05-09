#include <iostream>
using namespace std;

/*
Zadanie 3.4. Dart - 301

Je¿eli uczyliœcie siê jeŸdziæ na rowerze metod¹ prowadzenia na kiju przez osobê starsz¹, to pewnie pamiêtacie dzieñ, w którym odwróciliœcie siê za siebie i okaza³o siê, ¿e jedziecie samodzielnie. Wasz tata (albo starszy brat, albo inny mentor) stwierdzi³, ¿e radzicie sobie na tyle dobrze, ¿e mo¿e Was ju¿ puœciæ. Czêsto koñczy³o siê to upadkiem, ale upadki to czêœæ nauki.

My doszliœmy w uczeniu Was do podobnego momentu - uwa¿amy, ¿e nie musimy ju¿ trzymaæ kija i mo¿emy pozwoliæ Wam pobawiæ siê samodzielnie. Teraz równie¿ przygotowaliœmy zadanie ¿yciowe: chcielibyœmy ¿ebyœcie napisali program, który zlicza punkty w darta.

Zasady gry 301 dla 1 gracza:
Jest to najbardziej znana gra w darta. Grana w wiêkszoœci Dart-ligach i wielu turniejach. Zawodnik zaczyna grê od stanu punktowego 301. Na koniec ka¿dej kolejki (po rzuceniu 3 rzutek) odejmuje siê sumê zdobytych punktów od poprzedniego stanu punktowego. Zawodnik, musi zredukowaæ iloœæ punktów dok³adnie do zera. Gdy zawodnik w jednej kolejce zdobêdzie wiêcej punktów ni¿ potrzebne jest do osi¹gniêcia zera - oznacza to "BUST" i nie bêd¹ one zapisane. Ca³kowita punktacja powraca do stanu z poprzedniej kolejki.

Treœæ zadania
Napisz program, który zlicza punkty w grê 301 dla jednego gracza, wed³ug zasad podanych powy¿ej. Program mo¿e mieæ dowoln¹ liczbê rund. W ka¿dej rundzie zawodnik ma do wykorzystania 3 lotki. Ka¿da lotka mo¿e punktowaæ w zakresie 0 – 60 punktów. Jeœli punktacja podana przez gracza bêdzie mieœci³a siê w tym zakresie, nie bêdziemy sprawdzali poprawnoœci punktów (w prawdziwej grze zawodnik nie ma szans zdobyæ np. 59 punktów w jednym rzucie, a w naszej grze mo¿e). Jeœli jednak wartoœæ jednego rzutu nie mieœci siê w zakresie 0 - 60, program wyœwietli komunikat: "Niepoprawna ilosc punktow".

Gra koñczy siê, gdy zawodnik osi¹gnie 0 punktów - nawet, jeœli bêdzie to po pierwszej lub drugiej lotce, a wiêc w œrodku rundy!

W ka¿dej rundzie program wyœwietli nastêpuj¹ce komunikaty:
Runda 1, rzut 1: Podaj iloœæ punktów
Runda 1, rzut 2: Podaj iloœæ punktów
Runda 1, rzut 3: Podaj iloœæ punktów
Runda 1, liczba twoich punktów: x

Gdzie x jest liczb¹ punktów posiadanych przez gracza, a nie iloœci¹ punktów zdobytych w rundzie. Przyk³adowo je¿eli w pierwszej rundzie rzuci³em 20 pkt, to x = 301 – 20 = 281.
Je¿eli gracz w rundzie rzuci wiêcej punktów ni¿ mu pozosta³o, zobaczymy komunikat:
Runda 1, BUST!
Liczba twoich punktów: x

Komunikat BUST! pojawi siê bezpoœrednio po rzucie, w którym gracz przekroczy³ punktacjê. Oznacza to, ¿e BUST! mo¿e byæ po 1, 2 lub 3 rzucie. Niezale¿nie od numeru rzutu, BUST! zawsze koñczy bie¿¹c¹ rundê.

Na zakoñczenie gry (w momencie, gdy u¿ytkownik uzyska 0 pkt) program wypisze komunikat:
Gra zakonczona w rundzie X 

Dodatkowym wymaganiem jest, aby program zakoñczy³ siê natychmiast po wprowadzeniu przez u¿ytkownika liczby -1. Po wprowadzeniu liczby punktów -1 program nie musi wyœwietlaæ na ekranie ¿adnego komunikatu.
*/

int main()
{
	int runda = 0;
	int rzut = 0;
	
	int punkty_rzutu = 0;
	int punkty_rundy = 0;
	int punkty_gry = 301;
	int punkty_zakonczonej_rundy = 0;
		
	while(1)
	{
		runda += 1;
		
		while (rzut < 3)
		{
				rzut += 1;
				punkty_rzutu = 0;
				
				cout << "Runda "<< runda <<", rzut "<< rzut <<": Podaj ilosc punktow ";
				cin >> punkty_rzutu;
			
			// warunek wyjscia z programu		
				if (punkty_rzutu == -1)
					{
						break;
					}
					
			// warunek czy punkty sa w zakresie 0-60 pkt. je¿eli tak to cofnij licznik rzutow i powtorz rzut 
				if(punkty_rzutu < 0)
					{
						cout << "Niepoprawna ilosc punktow" << endl;
						rzut -= 1;
						punkty_rzutu = 0;
						continue;
					}
				if(punkty_rzutu > 60)
					{
						cout << "Niepoprawna ilosc punktow" << endl;
						rzut -= 1;
						punkty_rzutu = 0;
						continue;
					}
		
			
			// sumowanie punktow rundy
				punkty_rundy += punkty_rzutu;
		
		
			// sumowanie punktow gry (odejmowanie od 301pkt.)
				punkty_gry -= punkty_rzutu;
				
				
			// sprawdzenie warunkoww zakonczenia gry w trakcie rundy			
				if (punkty_gry == 0)
					{
						// komunikat "Gra zakonczona w rundzie " przeniesiony do petli while(1) obslugujacej cykl rund
						break;
					}				
			
					
			// sprawdzenie warunku BUST! i obsluga zakonczenia rundy w trybie BUST! , BUST = punkty_gry < 0
 				if (punkty_gry < 0)
					{
						cout << "Runda "<< runda <<", BUST!" << endl;
						cout << "Liczba twoich punktow: " << punkty_zakonczonej_rundy << endl;
						
						// korekta punktow
						punkty_gry = punkty_zakonczonej_rundy;
						
						//zakonczenie rundy = zakonczenie petli while
						break;				
					}

		}   // <- koniec petli while obsluguj¹cej cykl 3 rzuty
		
		
	// aktualizacja licznika punktów zakonczonych rund	
		punkty_zakonczonej_rundy = punkty_gry;	
		
				
	// sprawdzenie warunku zakonczenia programu po wpisaniu "-1"	
		if (punkty_rzutu == -1 )
					{
						cout << "Gra zakonczona w rundzie " << runda << endl;
						break;
					}
		
	
	// wypisanie komunikatow dla uzytkownika po zakonczonej rundzie	
		if (punkty_zakonczonej_rundy == 0)
					{
						cout << "Gra zakonczona w rundzie " << runda << endl;
						break;
					}
		else 
					{
						cout << "Runda " << runda << ", liczba twoich punktow: " << punkty_zakonczonej_rundy << endl;
					}	
	
	
	// zerowanie zmiennych petli "3 rzuty"								
		rzut = 0;
		punkty_rzutu = 0;
		
		
					
	} // <- koniec petli while obslugujacej cykl rund
	
	
	return 0;
}

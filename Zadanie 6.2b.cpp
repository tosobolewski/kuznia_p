    #include <iostream>
    using namespace std;
	
	/*
	Zadanie 6.2. Bankomat z menu

	Zmie� zadanie 3.3 z bankomatem w taki spos�b, aby by�a mo�liwo�� wybierania operacji za pomoc� menu. U�ytkownik za pomoc� liczb 0 - 4 b�dzie mia� do wyboru nast�puj�ce operacje:

	1: sprawdzenie salda. Po wybraniu opcji 1 na ekranie wy�wietli si� komunikat: "Stan twojego konta wynosi: X"
	2: szybka wyp�ata 50 z�. Po wybraniu opcji 2 na ekranie wy�wietli si� komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X"
	3: szybka wyp�ata 100 z�. Po wybraniu tej opcji, na ekranie wy�wietli si� komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X"
	4: wyp�ata innej kwoty. Po wybraniu tej opcji program b�dzie zachowywa� si� wed�ug wymaga� z zadania 3.3.
	0: wyj�cie z programu. Zawsze przed zako�czeniem programu na ekranie wy�wietli si� komunikat: "Dziekujemy za korzystanie z naszego bankomatu"
 
	Do zbudowania menu u�yj typu wyliczeniowego enum.
	
	

	**************************************************************************************
	Zadanie 3.2. Symulacja bankomatu
	
	Zadanie z bankomatem:
	Pocz�tkowy stan konta u�ytkownika zawsze wynosi 2500.
	U�ytkownik mo�e wyp�aci� kwot� pieni�dzy nie wi�ksz�, ni� posiada na koncie.
	Je�eli u�ytkownik wybierze wszystkie pieni�dze z konta, niech program si� zako�czy.
	

	Zmie� zadanie z bankomatem w taki spos�b, aby spe�nia�o nast�puj�ce wymagania:

	Req.1: W przypadku, gdy u�ytkownik wpisze kwot� 0, program powinien si� zako�czy�. Zawsze przed zako�czeniem program wypisze komunikat: "Dziekujemy za korzystanie z naszego bankomatu".
	Req.2: W przypadku, gdy u�ytkownik wpisze kwot� ujemn�, to program powinien wypisa� komunikat: "Kwota musi byc dodatnia" oraz poprosi� o ponowne wpisanie kwoty. Zmienna stanKonta powinna pozosta� niezmieniona. W programie musi pojawi� si� instrukcja continue.
	Req.3: W przypadku, gdy u�ytkownik wpisze prawid�ow� kwot�, na ekranie pojawi si� komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X". Za�o�enie, �e zawsze na pocz�tku programu stan konta wynosi 2500 jest wci�� aktualne.
	Req.4: W przypadku, gdy u�ytkownik wpisze kwot� wi�ksz� ni� wynosi aktualny stan konta, na ekranie pojawi si� komunikat: "Nie masz wystarczajacych srodkow na koncie. Stan twojego konta wynosi: X".
	***************************************************************************************
	*/
	
	int main()
    {
        int stanKonta = 2500;   // stan naszego konta; gdy zaczynamy korzysta� z bankomatu mamy 2500 z�
        int kwota;              // kwota, kt�r� bedziemy wyplaca� z bankomatu

        // na poczatku programu informujemy uzytkownika ile ma kasy
        cout << "Stan twojego konta: "      // ten cout jest zapisany w dwoch liniach zamiast jednej
            << stanKonta << endl << endl;   // zauwaz, ze srednik jest tylko na koncu drugiej linii




		// + zad. 6.2. wypisz menu na konsoli
		cout << "1 - Sprawdzenie salda\n";
		cout << "2 - Szybka wyplata 50 zl\n";
		cout << "3 - Szybka wyplata 100 zl\n";
		cout << "4 - Wyplata innej kwoty\n";
		cout << "0 - Wyjscie z programu\n";
	
		
		// + zad. 6.2. definicja wartosci enum menu
		enum menu
			{
				wyjscie = 0,
				stan_konta = 1,
				wyplata_50 = 2,
				wyplata_100 = 3,
				wyplata_inna = 4
			};




        while( stanKonta > 0 ) // warunek wykonania -> musimy miec PLN na koncie, aby wyplaci�
        {

        	// czytaj wybor uzytkownika
			int wybor;
			cout << "Wybor uzytkownika: "; 
			cin >> wybor;
	
			kwota = 0;
			
			// + zad. 6.2. obsluga menu + niektore podstawowe operacje
			switch (wybor)
				{
					case stan_konta:
										cout << "Stan twojego konta: "      // ten cout jest zapisany w dwoch liniach zamiast jednej
            							<< stanKonta << endl << endl;   // zauwaz, ze srednik jest tylko na koncu drugiej linii
										break;
			
					case wyplata_50:
										kwota = 50;		
										break;
			
					case wyplata_100:
										kwota = 100;		
										break;
			
					case wyplata_inna:									
										do 
										{

											cout << "Podaj kwote" << endl;
        									cin >> kwota; // u�ytkownik wpisuje kwot�; zwr�� uwag�, �e strza�ki s� w drug� stron� ni� przy cout	
        								
        										// modyfikacja do Req. 1., Req. 2.
											if (kwota == 0)
           							 			{
            										break;
            									}
            								else if (kwota < 0)
            									{
            										cout << "Kwota musi byc dodatnia \n" ;
            										//continue;    			
            									}
        								
        								
        								} while ( kwota < 0);
        								
										break;
			
					case wyjscie:
						kwota = 0;
						break;
				
					default:
						cout << "Podaj wartosc z zakresu 0-4\n";
						break;
				}
        	
        	
			if ((kwota == 0)&&(wybor == wyjscie))
			{
				break; 
			}	
	
		    if (kwota != 0)
		    {
		    
            	if ( kwota <= stanKonta) // czy u�ytkownik ma na koncie tyle pieni�dzy, ile chce wyplaci�?
           		{
                	stanKonta = stanKonta - kwota; // to samo mozna zapisac jako: stanKonta -= kwota;
                	cout << "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: "
                    << stanKonta << endl << endl;
           		}
            	else    // chcesz wyplaci� wiecej niz masz pieni�dzy na koncie
            	{
                	cout << "Nie masz wystarczajacych srodkow na koncie. Stan twojego konta wynosi: "
                	<< stanKonta << endl << endl;
            	}
        	}	
        } // koniec g��wnej petli while(1);
 
        cout << "Dziekujemy za korzystanie z naszego bankomatu.\n";
        return 0;
    }  

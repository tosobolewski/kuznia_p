    #include <iostream>
    using namespace std;
	
	/*
	Zadanie 6.2. Bankomat z menu

	Zmieñ zadanie 3.3 z bankomatem w taki sposób, aby by³a mo¿liwoœæ wybierania operacji za pomoc¹ menu. U¿ytkownik za pomoc¹ liczb 0 - 4 bêdzie mia³ do wyboru nastêpuj¹ce operacje:

	1: sprawdzenie salda. Po wybraniu opcji 1 na ekranie wyœwietli siê komunikat: "Stan twojego konta wynosi: X"
	2: szybka wyp³ata 50 z³. Po wybraniu opcji 2 na ekranie wyœwietli siê komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X"
	3: szybka wyp³ata 100 z³. Po wybraniu tej opcji, na ekranie wyœwietli siê komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X"
	4: wyp³ata innej kwoty. Po wybraniu tej opcji program bêdzie zachowywa³ siê wed³ug wymagañ z zadania 3.3.
	0: wyjœcie z programu. Zawsze przed zakoñczeniem programu na ekranie wyœwietli siê komunikat: "Dziekujemy za korzystanie z naszego bankomatu"
 
	Do zbudowania menu u¿yj typu wyliczeniowego enum.
	
	

	**************************************************************************************
	Zadanie 3.2. Symulacja bankomatu
	
	Zadanie z bankomatem:
	Pocz¹tkowy stan konta u¿ytkownika zawsze wynosi 2500.
	U¿ytkownik mo¿e wyp³aciæ kwotê pieniêdzy nie wiêksz¹, ni¿ posiada na koncie.
	Je¿eli u¿ytkownik wybierze wszystkie pieni¹dze z konta, niech program siê zakoñczy.
	

	Zmieñ zadanie z bankomatem w taki sposób, aby spe³nia³o nastêpuj¹ce wymagania:

	Req.1: W przypadku, gdy u¿ytkownik wpisze kwotê 0, program powinien siê zakoñczyæ. Zawsze przed zakoñczeniem program wypisze komunikat: "Dziekujemy za korzystanie z naszego bankomatu".
	Req.2: W przypadku, gdy u¿ytkownik wpisze kwotê ujemn¹, to program powinien wypisaæ komunikat: "Kwota musi byc dodatnia" oraz poprosiæ o ponowne wpisanie kwoty. Zmienna stanKonta powinna pozostaæ niezmieniona. W programie musi pojawiæ siê instrukcja continue.
	Req.3: W przypadku, gdy u¿ytkownik wpisze prawid³ow¹ kwotê, na ekranie pojawi siê komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X". Za³o¿enie, ¿e zawsze na pocz¹tku programu stan konta wynosi 2500 jest wci¹¿ aktualne.
	Req.4: W przypadku, gdy u¿ytkownik wpisze kwotê wiêksz¹ ni¿ wynosi aktualny stan konta, na ekranie pojawi siê komunikat: "Nie masz wystarczajacych srodkow na koncie. Stan twojego konta wynosi: X".
	***************************************************************************************
	*/
	
	int main()
    {
        int stanKonta = 2500;   // stan naszego konta; gdy zaczynamy korzystaæ z bankomatu mamy 2500 z³
        int kwota;              // kwota, któr¹ bedziemy wyplacaæ z bankomatu

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




        while( stanKonta > 0 ) // warunek wykonania -> musimy miec PLN na koncie, aby wyplaciæ
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
        									cin >> kwota; // u¿ytkownik wpisuje kwotê; zwróæ uwagê, ¿e strza³ki s¹ w drug¹ stronê ni¿ przy cout	
        								
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
		    
            	if ( kwota <= stanKonta) // czy u¿ytkownik ma na koncie tyle pieniêdzy, ile chce wyplaciæ?
           		{
                	stanKonta = stanKonta - kwota; // to samo mozna zapisac jako: stanKonta -= kwota;
                	cout << "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: "
                    << stanKonta << endl << endl;
           		}
            	else    // chcesz wyplaciæ wiecej niz masz pieniêdzy na koncie
            	{
                	cout << "Nie masz wystarczajacych srodkow na koncie. Stan twojego konta wynosi: "
                	<< stanKonta << endl << endl;
            	}
        	}	
        } // koniec g³ównej petli while(1);
 
        cout << "Dziekujemy za korzystanie z naszego bankomatu.\n";
        return 0;
    }  

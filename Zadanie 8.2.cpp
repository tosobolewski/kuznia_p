    #include <iostream>
    using namespace std;
	
	/*
	Zadanie 8.2. Bankomat: Poprawna kwota

	Zmieñ program Bankomat z zadania 3.3 w ten sposób, aby sprawdza³, czy podana kwota jest prawid³owa. 
	Upewnij siê, ¿e bankomat mo¿e wyp³aciæ podan¹ kwotê jako wielokrotnoœæ banknotów 50-z³otowych i ¿e kwota nie jest ujemna. 
	U¿yj nastepuj¹cej funkcji: bool poprawnaKwota(int kwota);
	Funkcja zwróci true, jeœli kwota jest dodatni¹ wielokrotnoœci¹ 50.
	
	
	
	Zadanie 3.3. Symulacja bankomatu
	
	Zadanie z bankomatem:
	Pocz¹tkowy stan konta u¿ytkownika zawsze wynosi 2500.
	U¿ytkownik mo¿e wyp³aciæ kwotê pieniêdzy nie wiêksz¹, ni¿ posiada na koncie.
	Je¿eli u¿ytkownik wybierze wszystkie pieni¹dze z konta, niech program siê zakoñczy.
	

	Zmieñ zadanie z bankomatem w taki sposób, aby spe³nia³o nastêpuj¹ce wymagania:

	Req.1: W przypadku, gdy u¿ytkownik wpisze kwotê 0, program powinien siê zakoñczyæ. Zawsze przed zakoñczeniem program wypisze komunikat: "Dziekujemy za korzystanie z naszego bankomatu".
	Req.2: W przypadku, gdy u¿ytkownik wpisze kwotê ujemn¹, to program powinien wypisaæ komunikat: "Kwota musi byc dodatnia" oraz poprosiæ o ponowne wpisanie kwoty. Zmienna stanKonta powinna pozostaæ niezmieniona. W programie musi pojawiæ siê instrukcja continue.
	Req.3: W przypadku, gdy u¿ytkownik wpisze prawid³ow¹ kwotê, na ekranie pojawi siê komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X". Za³o¿enie, ¿e zawsze na pocz¹tku programu stan konta wynosi 2500 jest wci¹¿ aktualne.
	Req.4: W przypadku, gdy u¿ytkownik wpisze kwotê wiêksz¹ ni¿ wynosi aktualny stan konta, na ekranie pojawi siê komunikat: "Nie masz wystarczajacych srodkow na koncie. Stan twojego konta wynosi: X".
	*/
	
	
	bool poprawnaKwota(int kwota)
	{
		//int x = kwota / 50;
		int r = kwota % 50;
		
		if (( kwota > 0) && (r == 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	
	int main()
    {
        int stanKonta = 2500;   // stan naszego konta; gdy zaczynamy korzystaæ z bankomatu mamy 2500 z³
        int kwota;              // kwota, któr¹ bedziemy wyplacaæ z bankomatu

        // na poczatku programu informujemy uzytkownika ile ma kasy
        cout << "Stan twojego konta: "      // ten cout jest zapisany w dwoch liniach zamiast jednej
            << stanKonta << endl << endl;   // zauwaz, ze srednik jest tylko na koncu drugiej linii

        while( stanKonta > 0 ) // warunek wykonania -> musimy miec PLN na koncie, aby wyplaciæ
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
            			cout << "Kwota musi byc dodatnia \n" << "Wpisz ponownie kwote \n";
            			continue;    			
            	}
            else if (!poprawnaKwota(kwota))				// uzupelnienie do zadania 8.2
		   		{
		    			cout << "Kwota musi byc wielokrotnoscia 50 zl" << endl;
		    			continue;
		   		}
		    
		    
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

        cout << "Dziekujemy za korzystanie z naszego bankomatu.\n";
        return 0;
    }  

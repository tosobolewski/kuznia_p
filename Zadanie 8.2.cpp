    #include <iostream>
    using namespace std;
	
	/*
	Zadanie 8.2. Bankomat: Poprawna kwota

	Zmie� program Bankomat z zadania 3.3 w ten spos�b, aby sprawdza�, czy podana kwota jest prawid�owa. 
	Upewnij si�, �e bankomat mo�e wyp�aci� podan� kwot� jako wielokrotno�� banknot�w 50-z�otowych i �e kwota nie jest ujemna. 
	U�yj nastepuj�cej funkcji: bool poprawnaKwota(int kwota);
	Funkcja zwr�ci true, je�li kwota jest dodatni� wielokrotno�ci� 50.
	
	
	
	Zadanie 3.3. Symulacja bankomatu
	
	Zadanie z bankomatem:
	Pocz�tkowy stan konta u�ytkownika zawsze wynosi 2500.
	U�ytkownik mo�e wyp�aci� kwot� pieni�dzy nie wi�ksz�, ni� posiada na koncie.
	Je�eli u�ytkownik wybierze wszystkie pieni�dze z konta, niech program si� zako�czy.
	

	Zmie� zadanie z bankomatem w taki spos�b, aby spe�nia�o nast�puj�ce wymagania:

	Req.1: W przypadku, gdy u�ytkownik wpisze kwot� 0, program powinien si� zako�czy�. Zawsze przed zako�czeniem program wypisze komunikat: "Dziekujemy za korzystanie z naszego bankomatu".
	Req.2: W przypadku, gdy u�ytkownik wpisze kwot� ujemn�, to program powinien wypisa� komunikat: "Kwota musi byc dodatnia" oraz poprosi� o ponowne wpisanie kwoty. Zmienna stanKonta powinna pozosta� niezmieniona. W programie musi pojawi� si� instrukcja continue.
	Req.3: W przypadku, gdy u�ytkownik wpisze prawid�ow� kwot�, na ekranie pojawi si� komunikat: "Wyplaciles pieniadze. Stan twojego konta po tej operacji wynosi: X". Za�o�enie, �e zawsze na pocz�tku programu stan konta wynosi 2500 jest wci�� aktualne.
	Req.4: W przypadku, gdy u�ytkownik wpisze kwot� wi�ksz� ni� wynosi aktualny stan konta, na ekranie pojawi si� komunikat: "Nie masz wystarczajacych srodkow na koncie. Stan twojego konta wynosi: X".
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
        int stanKonta = 2500;   // stan naszego konta; gdy zaczynamy korzysta� z bankomatu mamy 2500 z�
        int kwota;              // kwota, kt�r� bedziemy wyplaca� z bankomatu

        // na poczatku programu informujemy uzytkownika ile ma kasy
        cout << "Stan twojego konta: "      // ten cout jest zapisany w dwoch liniach zamiast jednej
            << stanKonta << endl << endl;   // zauwaz, ze srednik jest tylko na koncu drugiej linii

        while( stanKonta > 0 ) // warunek wykonania -> musimy miec PLN na koncie, aby wyplaci�
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
            			cout << "Kwota musi byc dodatnia \n" << "Wpisz ponownie kwote \n";
            			continue;    			
            	}
            else if (!poprawnaKwota(kwota))				// uzupelnienie do zadania 8.2
		   		{
		    			cout << "Kwota musi byc wielokrotnoscia 50 zl" << endl;
		    			continue;
		   		}
		    
		    
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

        cout << "Dziekujemy za korzystanie z naszego bankomatu.\n";
        return 0;
    }  

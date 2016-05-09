#include <iostream>
using namespace std;

/*
Kalkulator BMI

BMI to skrót z jêzyka angielskiego: body mass index, co mo¿na przet³umaczyæ jako wskaŸnik masy cia³a. Wspó³czynnik BMI charakteryzuje relacjê pomiêdzy mas¹ cia³a a wzrostem.

BMI obliczamy dziel¹c masê cia³a podan¹ w kilogramach przez kwadrat wzrostu podany w metrach. Np. dla osoby o wadze 80 kg i wzroœcie 175 cm, wspó³czynnik wyniesie:
BMI = 80 / (1,75*1,75) = 26

Napisz program, który zapyta u¿ytkownika o jego wagê (w kg) i wzrost (w cm), a nastêpnie obliczy BMI i przyporz¹dkuje u¿ytkownika do odpowiedniej kategorii:

< 16,0 – wyglodzenie
16,0–16,99 – wychudzenie
17,0–18,49 – niedowaga
18,5–24,99 – prawidlowe
25,0–29,99 – nadwaga
30,0–34,99 – 1 stopien otylosci
35,0–39,99 – 2 stopien otylosci
>= 40,0 – 3 stopien otylosci
Program wypisze na ekran informacje sformatowane w nastêpuj¹cy sposób:

Twoj BMI wynosi 26 = nadwaga
Twoj BMI wynosi 20 = prawidlowe
Twoj BMI wynosi 35 = 2 stopien otylosci
*/

int main()
{
	// pobierz od u¿utkownika wage i wzrost
	
	
	float waga;
	cout << "Podaj wage [kg]: ";
	cin >> waga;
	float wzrost;
	cout << "Podaj wzrost [cm]: ";
	cin >> wzrost;
	
	
	// oblicz BMI = 10000 * 80 / (175*175) = 26 , waga - kg, wzrost - cm,
	
	float bmi = 10000 * waga / (wzrost*wzrost);
	
	
	// wypisz wyniki na ekran
	
	// pierwszy sk³adnik wyniku
	//cout << "Twoj BMI wynosi " << bmi << " - ";
	
	// drugi sk³admik wyniku
	if (bmi < 16) 
		{
			cout << "wyglodzenie" << endl;
		}
	else if (bmi < 17)
			{
				cout << "wychudzenie" << endl;
			}
		 else if ( bmi < 18.5)
				{
					cout << "niedowaga" << endl;
				}
			  else if (bmi < 25)
					{
						cout << "prawidlowe" << endl;
					}
				   else if (bmi < 30)
						{
							cout << "nadwaga" << endl;
						}
						else if ( bmi < 35)
							{
								cout << "1 stopien otylosci" << endl;
							}
							else if (bmi < 40)
								{
									cout << "2 stopien otylosci" << endl;
								}
								else // (bmi >=40)
									{
										cout << "3 stopien otylosci" << endl;
									}
	 	 
if (0)  //test	
    {
		cout << "waga = " << waga << "  Wzrost = " << wzrost << endl ;
	}
	
	
	return 0;
}


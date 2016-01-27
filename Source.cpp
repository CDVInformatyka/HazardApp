#include "Header.h"
#include <ctime>

int main()
{
	setlocale(LC_ALL, "");
	srand(time(nullptr));
	SetConsoleTitleA("HazardApp");
	int liczby[6][2], winner[6], x, y;
	menu();
	cls();

	auto money = 100;
	int wynik;

	bool koniec = FALSE;

	while (koniec == FALSE) {

		money--;
		wynik = 0;

		for (auto i = 0; i < 6; i++)						//Podawanie liczb
		{

			do											//P�tla sprawdzaj�ca, czy to zakres od 1 do 49
			{
				cls();
				cout << "Podaj " << i + 1 << " liczb� z zakresu od 1 do 49" << endl;
				x = walidacja();
				for (auto j = 0; j < 6; j++) {			//Sprawdzanie, czy liczba si� powtarza
					if (liczby[j][0] == x) {
						x = 0;
					}
				}
				liczby[i][0] = x;						//Przypisanie zmiennej
				liczby[i][1] = 0;						//Wyczyszczenie zawarto�ci
			} while (x < 1 || x > 49);					//Sprawdzenie czy liczba jest z przedzia�u

			bool test;
			do {
				y = random(49) + 1;						//Dla y przypisujemy randomow� liczb�
				test = FALSE;							//Ustawiamy warto�� test na fa�sz
				for (auto j = 1; j<6; j++) {				//P�tla sprawdzaj�ca powt�rki
					if (winner[j] == y) {				//Je�li jaka� liczba si� powt�rzy
						test = TRUE;					//to zmienia warto�� na prawda
					}
				}

			} while (test == TRUE);
			winner[i] = y;								//Po wyj�ciu z p�tli przypisujemy liczb�
		}
		cls();

		cout << "Losowanie:" << endl;					//Wypisanie liczb
		for (auto i = 0; i < 6; i++)
		{
			cout << winner[i];
			cout.width(5);
		}
		cout << endl << "Wytypowane liczby:" << endl;	//Wypisanie liczb
		for (auto i = 0; i < 6; i++)
		{

			for (auto j = 0; j < 6; j++) {
				if (liczby[i][0] == winner[j]) {
					liczby[i][1] += 1;
				}
			}

		}

		for (auto i = 0; i < 6; i++)
		{
			if (liczby[i][1] == 1) {
				cout << "(" << liczby[i][0] << ")";
				wynik++;
			}
			else {
				cout << liczby[i][0];
			}
			cout.width(5);
		}

		cout << endl;
		switch (wynik) {
		case 3: money += 2;       break;
		case 4: money += 10;      break;
		case 5: money += 100;     break;
		case 6: money += 100000;  break;
		}

		if (money<1) {
			koniec = TRUE;
		}
		else {
			koniec = kontynuacja();
		}

		for (auto i = 0; i<6; i++) {
			liczby[i][0] = 0;
			liczby[i][1] = 0;
		}
	}

	cls();
	cout << "Stan konta: " << money << endl;

	pause();
	return EXIT_SUCCESS;
}

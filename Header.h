/*
*  Podstawowe biblioteki
*/

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

/*
*  Podstawowe funkcje
*/

inline void delay(unsigned long ms)
{
	Sleep(ms);
}

inline void pause() {
	//if (text == "") {
	//	cout << "Naciśnij dowolny klawisz, by kontynuować...";
	//}
	//else {
	//	cout << text;
	//}
	//cin.clear(); cin.sync(); cin.get();
	system("pause");
}

inline void cls() {
	system("cls");
}

inline int walidacja() {
	int x;
	while (!(cin >> x)) { cin.clear(); cin.sync(); }
	return x;
}

inline int random(int ileliczb = 2147483647, int plus = 0) {
	return rand() % ileliczb + plus;
}

inline void lotto() {
	cout << "    __    ____  ________________ " << endl;
	delay(500);
	cout << "   / /   / __ \\/_  __/_  __/ __ \\" << endl;
	delay(500);
	cout << "  / /   / / / / / /   / / / / / /" << endl;
	delay(500);
	cout << " / /___/ /_/ / / /   / / / /_/ / " << endl;
	delay(500);
	cout << "/_____/\\____/ /_/   /_/  \\____/  " << endl << endl;
	delay(1000);
	pause();
	cls();
}

void opis();

inline void menu(int i = 0) {
	if (i == 0)
	{
		lotto();
	}
	cout << "Wybierz opcję:" << endl;
	cout << "1. Opis gry" << endl;
	cout << "2. Rozpocznij grę" << endl;
	int opcja;
	opcja = walidacja();
	switch (opcja) {
	case 1: opis(); break;
	case 2: break;
	default: cout << "Nastąpiło zwolnienie blokady!" << endl; menu();
	}
}

/*
*  Gra
*/

inline void opis() {
	cls();
	cout << "Program na początku pyta użytkownika o 6 liczb z zakresu od 1 do 49" << endl;
	cout << "Następnie program wygeneruje 6 kolejny liczb i wyświetli wynik." << endl;
	cout << "Oba typowania zostaną wyświetlone i porównane ze sobą." << endl;
	cout << "W przypadku udanego typowania, można otrzymać nagrodę!" << endl;
	cout << "Trójka - nagroda 2 złote" << endl;
	cout << "Czwórka - 10 złotych" << endl;
	cout << "Piątka - 100 złotych" << endl;
	cout << "Szóstka - 100000 złotych" << endl;
	pause();
	cls();
	menu(1);
}

inline bool kontynuacja() {
	cout << "Czy chcesz kontynuować grę?" << endl;
	cout << "Naciśnij ENTER, aby kontynuować lub ESC, aby zakończyć grę!" << endl;
	bool powtorka = TRUE;
	unsigned char znak;
	int kod;
	while (powtorka) {
		znak = _getch();
		kod = static_cast < int >(znak);
		if (kod == 13) {
			return FALSE;
		}
		if (kod == 27) {
			return TRUE;
		}
	}
	return false;
}

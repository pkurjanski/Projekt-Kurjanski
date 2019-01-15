#include <iostream>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"

using namespace std;

void main()
{
	Pracownik *a;
	const Pracownik *b;
	ListaPracownikow c;
	int s;
	Napis n, i;
	do
	{
		
		cout << "1. Dodaj pracownika do listy." << endl;
		cout << "2. Usun pracownika z listy." << endl;
		cout << "3. Wypisz wszystkich pracownikow na liscie." << endl;
		cout << "4. Znajdz pracownika." << endl;
		cout << "5. Zamknij program." << endl;
		cin >> s;
		system("cls");
		switch (s)
		{
		case 1:
			a = new Pracownik;
			a->Wpisz();
			c.Dodaj(*a);
			system("pause");
			break;
		case 2:
			a = new Pracownik;
			a->Wpisz();
			c.Usun(*a);
			system("pause");
			break;
		case 3:
			c.WypiszPracownikow();
			system("pause");
			break;
		case 4:
			cout << "Podaj nazwisko: ";
			n.Wpisz();
			cout << "Podaj imie: ";
			i.Wpisz();
			cout << "Szukany pracownik: ";
			b = c.Szukaj(n.Zwroc(), i.Zwroc());
			if (b != nullptr) b->Wypisz();
			else cout << "nie istnieje";
			cout << endl;
			system("pause");
			break;
		case 5:
			system("pause");
			exit(0);
			break;
		default:
			cout << "Podaj poprawna opcje" << endl;
		}
		system("cls");
	} while (1 == 1);
	return;
}
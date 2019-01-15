#include "ListaPracownikow.h"
#include "Pracownik.h"
#include <iostream>

using namespace std;

ListaPracownikow::ListaPracownikow()
	: m_pPoczatek()
	, m_nLiczbaPracownikow(0)
{
	this->m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow()
{
}


void ListaPracownikow::Dodaj(const Pracownik & p)
{
	Pracownik *temp, *x = this->m_pPoczatek;
	if (this->m_pPoczatek == nullptr)
	{
		this->m_pPoczatek = (Pracownik*)&p;
		cout << "Pracownik zostal dodany" << endl;
	}
	else if (x->Porownaj(p) < 0)
	{
		temp = x;
		this->m_pPoczatek = (Pracownik*)&p;
		this->m_pPoczatek->m_pNastepny = temp;
		cout << "Pracownik zostal dodany" << endl;
	}
	else
	{
		do
		{
			if (x->Porownaj(p) == 0)
			{
				cout << "Pracownik juz znajduje sie na liscie" << endl;
				return;
			}
			if (x->Porownaj(p) > 0)
			{
				if (x->m_pNastepny == nullptr)
				{
					x->m_pNastepny = (Pracownik*)&p;
					x = x->m_pNastepny;
					x->m_pNastepny = nullptr;
					cout << "Pracownik zostal dodany" << endl;
					return;
				}
				else
				{
					if (x->m_pNastepny->Porownaj(p) < 0)
					{
						temp = x->m_pNastepny;
						x->m_pNastepny = (Pracownik*)&p;
						x = x->m_pNastepny;
						x->m_pNastepny = temp;
						cout << "Pracownik zostal dodany" << endl;
						return;
					}
				}
			}
			x = x->m_pNastepny;
		} while (x != nullptr);
	}
}


void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik *x = this->m_pPoczatek;
	int i = 1;
	if (x == nullptr)
	{
		cout << "Pusta lista" << endl;
	}
	else
	{
		do
		{
			cout << i << ". ";
			x->Wypisz();
			cout << endl;
			x = x->m_pNastepny;
			i++;
		} while (x != nullptr);
	}
}


void ListaPracownikow::Usun(const Pracownik &wzorzec)
{
	Pracownik *x = this->m_pPoczatek, *temp;
	if (x == nullptr)
	{
		cout << "Pusta lista" << endl;
	}
	else
	{
		if (x->Porownaj(wzorzec) == 0 && x->m_pNastepny == nullptr)
		{
			this->m_pPoczatek = nullptr;
			free(x);
			cout << "Pracownik zostal usuniety" << endl;
		}
		else if (x->Porownaj(wzorzec) == 0)
		{
			this->m_pPoczatek = x->m_pNastepny;
			free(x);
			cout << "Pracownik zostal usuniety" << endl;
		}
		else
		{
			do
			{
				if (x->m_pNastepny == nullptr)
				{
					cout << "Nie istnieje taki pracownik." << endl;
					return;
				}
				if (x->m_pNastepny->Porownaj(wzorzec) == 0 && x->m_pNastepny->m_pNastepny == nullptr)
				{
					temp = x->m_pNastepny;
					x->m_pNastepny = nullptr;
					free(temp);
					cout << "Pracownik zostal usuniety." << endl;
					return;
				}
				else if (x->m_pNastepny->Porownaj(wzorzec) == 0)
				{
					temp = x->m_pNastepny;
					x->m_pNastepny = x->m_pNastepny->m_pNastepny;
					free(temp);
					cout << "Pracownik zostal usuniety." << endl;
					return;
				}
				x = x->m_pNastepny;
			} while (1 == 1);
		}
	}
}


const Pracownik* ListaPracownikow::Szukaj(const char* Nazwisko, const char* Imie)
{
	Pracownik *x = this->m_pPoczatek;
	if (x != nullptr)
	{
		do 
		{
			if (x->Sprawdz_Nazwisko(Nazwisko) == 0 && x->Sprawdz_Imie(Imie) == 0)
			{
				return x;
			}
			x = x->m_pNastepny;
		} while (x != nullptr);
	}
	return nullptr;
}

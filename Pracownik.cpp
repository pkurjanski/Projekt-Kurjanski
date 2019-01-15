#include "Pracownik.h"
#include "Data.h"
#include <string.h>
#include <iostream>

using namespace std;

Pracownik::Pracownik(const char *im, const char *naz, int dzien, int miesiac, int rok)
	: m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesiac, rok), m_nIDZatrudnienia()
{
	this->m_pNastepny = nullptr;
}


Pracownik::Pracownik(const Pracownik & wzor) 
	: m_DataUrodzenia(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok()), m_nIDZatrudnienia()
{
	this->m_Imie.Ustaw(wzor.m_Imie.Zwroc());
	this->m_Nazwisko.Ustaw(wzor.m_Nazwisko.Zwroc());
}


Pracownik::~Pracownik()
{
}


const char* Pracownik::Imie() const
{
	return nullptr;
}


const char* Pracownik::Nazwisko() const
{
	return nullptr;
}


void Pracownik::Imie(const char* nowe_imie)
{
	this->m_Imie.Ustaw(nowe_imie);
}


void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	this->m_Nazwisko.Ustaw(nowe_nazwisko);
}


void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}


void Pracownik::DataUrodzeniaW()
{
	this->m_DataUrodzenia.Wpisz();
}


void Pracownik::Wypisz() const
{
	this->m_Imie.Wypisz();
	cout << " ";
	this->m_Nazwisko.Wypisz();
	cout << " ";
	this->m_DataUrodzenia.Wypisz();
}


void Pracownik::Wpisz()
{
	Napis i, n;
	cout << "Podaj imie: ";
	i.Wpisz();
	Imie(i.Zwroc());
	cout << "Podaj nazwisko: ";
	n.Wpisz();
	Nazwisko(n.Zwroc());
	DataUrodzeniaW();
}


int Pracownik::Sprawdz_Imie(const char* por_imie) const
{
	return this->m_Imie.SprawdzNapis(por_imie);
}


int Pracownik::Sprawdz_Nazwisko(const char* por_nazwisko) const
{
	return this->m_Nazwisko.SprawdzNapis(por_nazwisko);
}


int Pracownik::Porownaj(const Pracownik & wzorzec) const
{
	if (Sprawdz_Nazwisko(wzorzec.m_Nazwisko.Zwroc()) == 0)
	{
		if (Sprawdz_Imie(wzorzec.m_Imie.Zwroc()) == 0)
		{
			return this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
		}
		else return Sprawdz_Nazwisko(wzorzec.m_Nazwisko.Zwroc());
	}
	else return Sprawdz_Imie(wzorzec.m_Imie.Zwroc());
}


Pracownik & Pracownik::operator =(const Pracownik & wzor)
{
	Imie(wzor.m_Imie.Zwroc());
	Nazwisko(wzor.m_Nazwisko.Zwroc());
	DataUrodzenia(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
	return *this;
}


bool Pracownik::operator ==(const Pracownik & wzor) const
{
	if (Porownaj(wzor) == 0) return true;
	return false;
}


ostream & operator <<(ostream & wy, Pracownik & p)
{
	return wy << p.m_Imie << endl << p.m_Nazwisko << endl << p.m_DataUrodzenia;
}


istream & operator >>(istream & we, Pracownik & p)
{
	return we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
}
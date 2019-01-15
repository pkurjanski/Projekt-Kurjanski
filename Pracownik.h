#pragma once
#include "Napis.h"
#include "Data.h"
#include <iostream>


class Pracownik
{
public:
	Pracownik(const char * im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik & wzor);
	~Pracownik();
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
public:
	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void DataUrodzeniaW();
	void Wypisz() const;
	void Wpisz();
	int Sprawdz_Imie(const char* por_imie) const;
	int Sprawdz_Nazwisko(const char* por_nazwisko) const;
	Pracownik* m_pNastepny;
	int Porownaj(const Pracownik & wzorzec) const;
private:
	const int m_nIDZatrudnienia;
public:
	Pracownik & operator =(const Pracownik & wzor);
	bool operator ==(const Pracownik & wzor) const;
	friend ostream & operator <<(ostream & wy, Pracownik & p);
	friend istream & operator >>(istream & we, Pracownik & p);
};


ostream & operator <<(ostream & wy, Pracownik & p);
istream & operator >>(istream & we, Pracownik & p);


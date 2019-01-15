#pragma once
#include "Pracownik.h"
class ListaPracownikow
{
public:
	ListaPracownikow();
	~ListaPracownikow();
private:
	Pracownik* m_pPoczatek;
public:
	void Dodaj(const Pracownik & p);
private:
	int m_nLiczbaPracownikow;
public:
	void WypiszPracownikow() const;
	void Usun(const Pracownik &wzorzec);
	const Pracownik* Szukaj(const char* Nazwisko, const char* Imie);
};


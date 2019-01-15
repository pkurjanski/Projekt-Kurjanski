#include "Data.h"
#include "Napis.h"
#include <iostream>

using namespace std;

Data::Data(int d, int m, int r)
	: m_nDzien(d)
	, m_nMiesiac(m)
	, m_nRok(r)
{
}


Data::~Data()
{
}


void Data::Ustaw(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
}


int Data::Dzien() const
{
	return this->m_nDzien;
}


int Data::Miesiac() const
{
	return this->m_nMiesiac;
}


int Data::Rok() const
{
	return this->m_nRok;
}


void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}


void Data::Wpisz()
{
	int d, m, r;
	cout << "Podaj dzien: ";
	cin >> d;
	cout << "Podaj miesiac: ";
	cin >> m;
	cout << "Podaj rok: ";
	cin >> r;
	Ustaw(d, m, r);
}


void Data::Koryguj()
{
}


int Data::Porownaj(const  Data & wzor) const
{
	if (wzor.m_nRok - this->m_nRok == 0)
	{
		if (wzor.m_nMiesiac - this->m_nMiesiac == 0)
		{
			return wzor.m_nDzien - this->m_nDzien;
		}
		else return wzor.m_nMiesiac - this->m_nMiesiac;
	}
	else return wzor.m_nRok - this->m_nRok;
}


ostream & operator<<(ostream & wy, const Data & d)
{
	return wy << d.m_nDzien << "-" << d.m_nMiesiac << "-" << d.m_nRok;
}


istream & operator>>(istream & we, Data & d)
{
	return we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
}

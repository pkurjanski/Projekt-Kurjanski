#include "Napis.h"
#include <iostream>
#include <string.h>

using namespace std;

Napis::Napis(const char * nap)
{
	m_pszNapis = new char[strlen(nap)];
	strcpy(this->m_pszNapis, nap);
	this->m_nDl = strlen(this->m_pszNapis);
}


Napis::Napis(const Napis & wzor)
{
	this->Ustaw(wzor.Zwroc());
	this->m_nDl = wzor.m_nDl;
}


Napis::~Napis()
{
	delete m_pszNapis;
}


const char* Napis::Zwroc() const
{
	return this->m_pszNapis;
}


void Napis::Ustaw(const char* nowy_napis)
{
	strcpy(this->m_pszNapis, nowy_napis);
}


void Napis::Wypisz() const
{
	cout << this->m_pszNapis;
}


void Napis::Wpisz()
{
	char input[40];
	cin.clear();
	cin.sync();
	cin >> input;
	strcpy(this->m_pszNapis, input);
}


int Napis::SprawdzNapis(const char* por_napis) const
{
	return -strcmp(this->m_pszNapis, por_napis);
}


Napis & Napis::operator =(const Napis & wzor)
{
	this->m_nDl = wzor.m_nDl;
	this->Ustaw(wzor.Zwroc());
	return *this;
}


bool Napis::operator ==(const Napis & wzor) const
{
	if (strcmp(this->m_pszNapis, wzor.m_pszNapis) == 0) return true;
	return false;
}


ostream & operator <<(ostream & wy, const Napis & p)
{
	return wy << p.m_pszNapis;
}



istream & operator >>(istream & we, Napis & p)
{
	return we >> p.m_pszNapis;
}

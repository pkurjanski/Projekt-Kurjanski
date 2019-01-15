#pragma once
#include <iostream>

using namespace std;

class Data
{
public:
	Data(int d, int m, int r);
	~Data();
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	int Porownaj(const  Data & wzor) const;
	friend ostream & operator<<(ostream & wy, const Data & d);
	friend istream & operator>>(istream & we, Data & d);
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
};

ostream & operator<<(ostream & wy, const Data & d);
istream & operator>>(istream & we, Data & d);


#pragma once
#include <string>
#include <vector>

using namespace std;

class Carte
{
private:
	int id;
	string tip, titlu;
	double pret;
public:
	Carte(int id, string titlu, string tip, double pret) :id{ id }, titlu{ titlu }, tip{ tip }, pret{ pret }{};

	int getid() const
	{
		return id;
	}
	string gettip() const
	{
		return tip;
	}
	string gettitlu() const
	{
		return titlu;
	}
	double getpret() const
	{
		return pret;
	}
	~Carte() {};
};



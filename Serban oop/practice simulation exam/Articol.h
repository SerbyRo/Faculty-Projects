#pragma once
#include <string>
#include <vector>

using namespace std;

class Articol
{
private:
	string nume;
	string tip;
	int marime;
	int stoc;
public:
	Articol() = default;
	Articol(const string nume, const string tip, const int marime, const int stoc) :nume{ nume }, tip{ tip }, marime{ marime }, stoc{ stoc }{

	}
	string getnume() const
	{
		return nume;
	}
	string gettip() const
	{
		return tip;
	}
	int getmarime() const
	{
		return marime;
	}
	int getstoc() const
	{
		return stoc;
	}
};


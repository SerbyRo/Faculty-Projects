#include "ManageMasini.h"
#include <random>
#include <iostream>

using std::cout;


void ManageMasini::adauga(const Masina& mas)
{
	//auto iterator = find_if(masini.begin(), masini.end(), [&](Masina mas1) {return mas == mas1; });
	auto iterator = std::find_if(this->masini.begin(), this->masini.end(),
		[&](const Masina item) { return mas.egal(item); });
	if (iterator != masini.end())
	{
		cout << "Masina exista deja in lista!" << "\n";
	}
	else
	{
		masini.push_back(mas);
	}
}

const int ManageMasini::getSize() const noexcept {
	return masini.size();
}

void ManageMasini::genereazarandomlista(int rdmnumber, vector<Masina> allmasini)
{
	std::shuffle(begin(allmasini), end(allmasini), std::default_random_engine{});
	for (int i = 0;i < rdmnumber;i++)
	{
		adauga(allmasini.at(i));
	}
}

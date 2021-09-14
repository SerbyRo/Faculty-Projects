#include "ServiceMasina.h"
#include <functional>
#include <algorithm>
#include <assert.h>

vector <Masina> ServiceMasina::generalSort(bool(*maiMicF)(const Masina&, const Masina&))
{
	vector <Masina> v{ repomasini.getAll() };
	for (size_t i = 0;i < v.size() - 1;i++)
	{
		for (size_t j = i + 1;j < v.size();j++)
		{
			if (!maiMicF(v[i], v[j]))
			{
				Masina aux = v[i];
				v[i] = v[j];
			 	v[j] = aux;
			}
		}
	}
	return v;
}


/*
Adauga o noua masina
arunca exceptie daca: nu se poate salva, nu este valid
*/
void ServiceMasina::addMasina(const string& nrinmatriculare, const string& producator, const string& tip, const string& model)
{
	Masina mas{ nrinmatriculare,producator,tip,model };
	validator.valideazamasina(mas);
	/*vector <Masina> v{ repomasini.getAll() };
	int ok = 1;
	for (auto& masina : v)
	{
		if (masina.getnrinmatriculare()==mas.getnrinmatriculare())
		{
			ok = 0;
		}
	}
	if (ok)
	{
		repomasini.store(mas);
	}*/
	repomasini.store(mas);
}

/*
* Sorteaza dupa nrinmatriculare
*/

vector<Masina> ServiceMasina::sortbynrinmatriculare()
{
	auto copyAll = repomasini.getAll();
	std::sort(copyAll.begin(), copyAll.end(), cmpnrinmatriculare);
	return copyAll;
}
/*
* Sorteaza dupa tip
*/
vector<Masina> ServiceMasina::sortbytip()
{
	return generalSort(cmptip);
}
/*
* Sorteaza dupa producator+model
*/
vector<Masina> ServiceMasina::sortbyproducatormodel()
{
	return generalSort([](const Masina& mas1, const Masina& mas2) {
		if (mas1.getproducator() == mas2.getproducator())
		{
			return mas1.getmodel() < mas2.getmodel();
		}
		return mas1.getproducator() < mas2.getproducator();
		});
}

/*
* Filtreaza dupa producator
*/
vector<Masina> ServiceMasina::filtreaza(function<bool(const Masina&)> fct)
{
	vector<Masina> rez;
	for (const auto& mas : repomasini.getAll()) {
		if (fct(mas)) {
			rez.push_back(mas);
		}
	}
	return rez;
}

vector<Masina> ServiceMasina::filterbyproducator(string producator) {
	return filtreaza([producator](const Masina& mas) {
		return mas.getproducator() == producator;
	});
}

vector<Masina> ServiceMasina::filterbytip(string tip)
{
	return filtreaza([tip](const Masina& mas) {
		return mas.gettip() == tip;
		});
}

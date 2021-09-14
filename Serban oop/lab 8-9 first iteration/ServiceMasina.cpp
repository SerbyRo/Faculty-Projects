#include "ServiceMasina.h"
#include "Masina.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>

using std::cout;

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


bool ServiceMasina::searchservice(string nrinmatriculare)
{
	Masina mas{ nrinmatriculare,"a","a","a" };
	int const pozitie = repomasini.searchrepo(mas);
	if (pozitie == -1)
	{
		return false;
	}
	return true;
}

void ServiceMasina::updateservice(string nrinmatriculare, string producator, string tip, string model)
{
	Masina mas{ nrinmatriculare,producator,tip,model };
	repomasini.updaterepo(mas);
}

void ServiceMasina::deleteservice(string nrinmatriculare)
{
	Masina mas{ nrinmatriculare,"a","a","a" };
	repomasini.deleterepo(mas);
}

vector<Masina> ServiceMasina::filterbyproducator(string producator)
{
	vector<Masina> lista = repomasini.getAll();
	vector<Masina>lista_filtrata;

	auto iterator = std::copy_if(lista.begin(), lista.end(), std::back_inserter(lista_filtrata), [producator](const Masina& mas) noexcept {return mas.getproducator() == producator;});
	return lista_filtrata;
}

vector<Masina> ServiceMasina::filterbytip(string tip)
{
	vector<Masina>lista = repomasini.getAll();
	vector<Masina>lista_filtrata;
	auto iterator = std::copy_if(lista.begin(), lista.end(), std::back_inserter(lista_filtrata), [tip](const Masina& mas) noexcept {return mas.gettip() == tip;});
	return lista_filtrata;
}


vector<Masina> ServiceMasina::generalsort(int cmd) {
	vector<Masina> lista = this->getAll();
	if (cmd == 0)
	{
		auto listasortata = [](const Masina& mas1, const Masina& mas2) {return mas1.getnrinmatriculare() < mas2.getnrinmatriculare();};
		sort(lista.begin(), lista.end(), listasortata);
	}
	if (cmd == 1)
	{
		auto listasortata = [](const Masina& mas1, const Masina& mas2) {return mas1.gettip() < mas2.gettip();};
		sort(lista.begin(), lista.end(), listasortata);
	}
	if (cmd == 2)
	{
		auto listasortata = [](const Masina& mas1, const Masina& mas2) {
			if (mas1.getproducator() == mas2.getproducator())
			{
				return mas1.getmodel() < mas2.getmodel();
			}
			return mas1.getproducator() < mas2.getproducator();
		};
		sort(lista.begin(), lista.end(), listasortata);
	}
	return lista;
}

int ServiceMasina::listagoala() {
	worklist.goleste();
	return worklist.getallmasini().size();
}

vector<Masina>& ServiceMasina::getworklist()
{
	return worklist.getallmasini();
}

void ServiceMasina::addworkcar(string nrinmatriculare)
{
	const auto masina = this->repomasini.getMasina(Masina{ nrinmatriculare,"a","a","a" });
	this->worklist.adauga(masina);
}

void ServiceMasina::generaterandomlist(int random_number)
{
	const int reposize = this->repomasini.getAll().size();
	if (reposize <= 0)
	{
		cout << "Prea putine masini!";
	}
	const auto allmasini = this->repomasini.getAll();
	worklist.genereazarandomlista(random_number, allmasini);
}


int ServiceMasina::searchDTO(map<string, DTO> dict, string model) noexcept
{
	for (auto& iterator : dict)
	{
		if (iterator.first == model)
		{
			iterator.second.increment();
			return true;
		}
	}
	return false;
}


map<string, DTO> ServiceMasina::raport()
{
	map<string, DTO> rap;
	for (const auto& iterator : repomasini.getAll())
	{
		string model = iterator.getmodel();
		if (searchDTO(rap, model) == false)
		{
			DTO obiect{ model };
			rap.insert(make_pair(model, obiect));
		}
		else
		{
			for (auto& iterator1 : rap)
			{
				if (iterator1.first == model)
				{
					iterator1.second.increment();
				}
			}
		}

	}
	return rap;
}

void ServiceMasina::saveworklistinCVS(string file)
{
	worklist.storetoCVS(file);
}
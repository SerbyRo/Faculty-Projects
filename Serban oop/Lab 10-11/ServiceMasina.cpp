#include "ServiceMasina.h"
#include "Masina.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include "ActiuneUndo.h"

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
	undo_action.push_back(make_unique<UndoAdauga>(repomasini, mas));
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
	/*Masina masmodificata=repomasini.updaterepo(mas);
	Masina masmodificata = repomasini.find(nrinmatriculare);
	Masina masina = repomasini.getMasinabynrinmatriculare(nrinmatriculare);
	masina.setproducator(producator);
	masina.settip(tip);
	masina.setmodel(model);
	Masina masmodificata = repomasini.updaterepo(masina);*/
	Masina mas1 = repomasini.getMasina(mas);
	repomasini.updaterepo(mas);
	undo_action.push_back(make_unique<UndoModifica>(repomasini, mas1));
}

void ServiceMasina::deleteservice(string nrinmatriculare)
{
	//Masina mas{ nrinmatriculare,"a","a","a" };
	Masina mas = repomasini.find(nrinmatriculare);
	repomasini.deleterepo(mas);
	//Masina masstearsa = mas;
	//cout << mas.getnrinmatriculare() << " " << mas.getproducator() << "\n";
	undo_action.push_back(make_unique<UndoSterge>(repomasini, mas));
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

int ServiceMasina::listagoala() noexcept {
	worklist.goleste();
	notifyObserver();
	size_t lungime = worklist.getallmasini().size();
	int lungime1 = static_cast<int>(lungime);
	return lungime1;
}

const vector<Masina>& ServiceMasina::getworklist() noexcept
{
	return worklist.getallmasini();
}

void ServiceMasina::addworkcar(string nrinmatriculare)
{
	for (const auto& iterator : repomasini.getAll())
	{
		if (iterator.getnrinmatriculare() == nrinmatriculare)
		{
			const auto masina = this->repomasini.getMasina(iterator);
			this->worklist.adauga(iterator);
		}
	}
	notifyObserver();
	//const auto masina = this->repomasini.getMasina(Masina{ nrinmatriculare,"a","a","a" });

}

void ServiceMasina::generaterandomlist(int random_number)
{
	size_t lungime = this->repomasini.getAll().size();
	int lungime1 = static_cast<int>(lungime);
	const int reposize = lungime1;
	if (reposize <= 0)
	{
		cout << "Prea putine masini!\n";
	}
	const auto allmasini = this->repomasini.getAll();
	worklist.genereazarandomlista(random_number, allmasini);
	notifyObserver();
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

void ServiceMasina::undo()
{
	if (this->undo_action.empty())
	{
		throw RepoException("Nu se mai poate face undo!");
	}
	/*auto actiune = undo_action.back().get();
	actiune->doUndo();
	undo_action.pop_back();*/
	this->undo_action.back()->doUndo();
	undo_action.pop_back();
}

Masina ServiceMasina::findservice(string nrinmatriculare)
{
	for (const auto& mas : repomasini.getAll())
	{
		if (mas.getnrinmatriculare() == nrinmatriculare)
		{
			return mas;
		}
	}
	return Masina{ "Masina","nu","s-a","gasit" };
}
#include "RepoMasina.h"
#include "Masina.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using std::ostream;
using std::stringstream;
using std::cout;

void RepoMasina::store(const Masina& mas)
{
	if (exist(mas))
	{
		throw RepoException("Exista o masina cu numarul de inmatriculare:" + mas.getnrinmatriculare());
	}
	repomasini.push_back(mas);
}

bool RepoMasina::exist(const Masina& mas)
{
	try
	{
		find(mas.getnrinmatriculare());
		return true;
	}
	catch (const RepoException&)
	{
		return false;
	}
}
const Masina& RepoMasina::find(string nrinmatriculare) const {
	/*for (const auto& mas : repomasini)
	{
		if (mas.getnrinmatriculare() == nrinmatriculare)
		{
			return mas;
		}
	}*/
	for (unsigned i = 0;i < repomasini.size();i++)
	{
		if (repomasini.at(i).getnrinmatriculare() == nrinmatriculare)
		{
			return repomasini.at(i);
		}
	}

	throw RepoException("Nu exista masina cu numarul de inmatriculare" + nrinmatriculare);
}

int RepoMasina::searchrepo(const Masina& mas)
{
	/*int i = 0;
	for (const auto& masina : repomasini)
	{
		if (mas.egal(masina) == true)
		{
			cout << masina.getnrinmatriculare() << " " << masina.getproducator() << " " << masina.gettip() << " " << masina.getmodel();
			return i;
		}
		i++;
	}
	return -1;*/

	for (unsigned i = 0;i < repomasini.size();i++)
	{
		if (repomasini.at(i).egal(mas) == true)
		{
			return i;
		}
	}
	return -1;
}

void RepoMasina::updaterepo(const Masina& mas)
{
	const int pozitie = searchrepo(mas);
	if (pozitie == -1)
	{
		throw RepoException("Nu exista masina in lista!\n");
	}
	repomasini.at(pozitie) = mas;
}

void RepoMasina::deleterepo(const Masina& mas)
{
	const int pozitie = searchrepo(mas);
	if (pozitie == -1)
	{
		throw RepoException("Nu exista masina in lista!\n");
	}
	repomasini.erase(repomasini.begin() + pozitie);
}


const vector<Masina>& RepoMasina::getAll() const noexcept {
	return repomasini;
}


Masina RepoMasina::getMasina(const Masina& mas)
{
	auto iterator = std::find_if(this->repomasini.begin(), this->repomasini.end(), [&](Masina& mas1) {return mas.egal(mas1); });
	if (iterator == this->repomasini.end())
	{
		return mas;
	}
	return *iterator;
}

ostream& operator<<(ostream& out, const RepoException& erori)
{
	out << erori.message;
	return out;
}


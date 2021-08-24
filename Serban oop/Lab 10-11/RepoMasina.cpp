#include "RepoMasina.h"
#include "Masina.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using std::ostream;
using std::stringstream;
using std::cout;
using std::ifstream;
using std::ofstream;

void MemoryRepo::store(const Masina& mas)
{
	if (exist(mas))
	{
		//throw RepoException("Exista o masina cu numarul de inmatriculare:" + mas.getnrinmatriculare());
		return;
	}
	repomasini.push_back(mas);
}

bool MemoryRepo::exist(const Masina& mas)
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
const Masina& MemoryRepo::find(string nrinmatriculare) const {
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

int MemoryRepo::searchrepo(const Masina& mas)
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

void MemoryRepo::updaterepo(const Masina& mas)
{
	const int pozitie = searchrepo(mas);
	if (pozitie == -1)
	{
		throw RepoException("Nu exista masina in lista!\n");
	}
	repomasini.at(pozitie) = mas;
	/*Masina masinainlocuita = repomasini.at(pozitie);
	repomasini.at(pozitie)=mas;
	return masinainlocuita;*/
}

void MemoryRepo::deleterepo(const Masina& mas)
{
	const int pozitie = searchrepo(mas);
	if (pozitie == -1)
	{
		throw RepoException("Nu exista masina in lista!\n");
	}
	repomasini.erase(repomasini.begin() + pozitie);
}


const vector<Masina>& MemoryRepo::getAll() const noexcept {
	return repomasini;
}


const int MemoryRepo::getSize()const noexcept
{
	size_t lungime = repomasini.size();
	int n_int = static_cast<int>(lungime);
	return n_int;
}

Masina MemoryRepo::getMasina(const Masina& mas)
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

ostream& operator<<(ostream& out, const FileRepoException& erori)
{
	out << erori.message;
	return out;
}

void RepoFileMasina::loadFromFile()
{
	ifstream fin(this->filename);
	if (!fin.is_open())
	{
		throw FileRepoException("Fisierul nu s-a putut deschide!");
	}
	while (!fin.eof())
	{
		string nrinmatriculare;
		fin >> nrinmatriculare;
		if (fin.eof())
		{
			break;
		}
		string producator;
		fin >> producator;
		string tip;
		fin >> tip;
		string model;
		fin >> model;
		Masina mas{ nrinmatriculare,producator,tip,model };
		RepoFileMasina::store(mas);
	}
	fin.close();
}


void RepoFileMasina::writeToFile()
{
	ofstream fout(this->filename);
	if (!fout.is_open()) {
		throw FileRepoException("Nu se poate deschide fisierul!");
	}
	for (auto& mas : this->getAll())
	{
		fout << mas.getnrinmatriculare() << " ";
		fout << mas.getproducator() << " ";
		fout << mas.gettip() << " ";
		fout << mas.getmodel() << "\n";
	}
	fout.close();
}

void RepoFileMasina::store(const Masina& mas)
{
	MemoryRepo::store(mas);
	writeToFile();
}

void RepoFileMasina::updaterepo(const Masina& mas)
{
	MemoryRepo::updaterepo(mas);
	writeToFile();
}

void RepoFileMasina::deleterepo(const Masina& mas)
{
	MemoryRepo::deleterepo(mas);
	writeToFile();
}

//activitate de laborator
void LabRepo::throwprobabilityexception() const
{
	if (rand() % 10 * 0.1 < this->probabilitate)
	{
		throw RepoException("Avem probleme cu probabilitatea!");
	}
}


bool LabRepo::exist(const Masina& mas)
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

const Masina& LabRepo::find(string nrinmatriculare) const
{
	for (unsigned i = 0;i < all_masini_vector.size();i++)
	{
		if (all_masini_vector.at(i).getnrinmatriculare() == nrinmatriculare)
		{
			return all_masini_vector.at(i);
		}
	}

	throw RepoException("Nu exista masina cu numarul de inmatriculare" + nrinmatriculare);
}

void LabRepo::store(const Masina& mas)
{
	this->throwprobabilityexception();
	const auto iterator = this->all_masini.find(mas.getnrinmatriculare());
	if (iterator != this->all_masini.end())
	{
		throw RepoException("Masina exista deja in lista!");
	}
	this->all_masini.insert(make_pair(mas.getnrinmatriculare(), mas));
	this->all_masini_vector.push_back(mas);
}

void LabRepo::updaterepo(const Masina& mas)
{
	this->throwprobabilityexception();
	/*const auto iterator = this->all_masini.find(mas.getnrinmatriculare());
	if (iterator != this->all_masini.end())
	{
		throw RepoException("Masina nu exista in lista!");
	}
	const auto masinaveche = *iterator;
	this->all_masini.erase(iterator);
	this->all_masini.insert(make_pair(mas.getnrinmatriculare(), mas));
	replace_if(this->all_masini_vector.begin(), this->all_masini_vector.end(), [&](const Masina& mas1) {return mas.egal(mas1);},mas);*/
	const int pozitie = searchrepo(mas);
	if (pozitie == -1)
	{
		throw RepoException("Nu exista masina in lista!\n");
	}
	all_masini_vector.at(pozitie) = mas;
}

void LabRepo::deleterepo(const Masina& mas)
{
	this->throwprobabilityexception();
	const size_t erased = this->all_masini.erase(mas.getnrinmatriculare());
	const int erased_int = (int)erased;
	if (erased_int == 0)
	{
		throw RepoException("Masina nu exista!");
	}
	const auto iterator = remove_if(this->all_masini_vector.begin(), this->all_masini_vector.end(), [&](const Masina& mas1) {return mas.egal(mas1);});
	this->all_masini_vector.pop_back();
}

Masina LabRepo::getMasina(const Masina& mas) {
	this->throwprobabilityexception();
	const auto iterator = this->all_masini.find(mas.getnrinmatriculare());
	if (iterator == this->all_masini.end())
	{
		throw RepoException("Masina nu exista in lista!");
	}
	return (*iterator).second;
}

const vector<Masina>& LabRepo::getAll() const noexcept {
	//this->throwprobabilityexception();
	return this->all_masini_vector;
}

const int LabRepo::getSize() const noexcept {

	const size_t the_size = this->all_masini_vector.size();
	const int the_size_int = (int)the_size;
	return the_size_int;
}

int LabRepo::searchrepo(const Masina& mas)
{
	for (unsigned i = 0;i < all_masini_vector.size();i++)
	{
		if (all_masini_vector.at(i).egal(mas) == true)
		{
			return i;
		}
	}
	return -1;
}



#include "FileRepo.h"
#include <fstream>


void FileRepo::LoadFromFile()
{
	ifstream fin{ filename };
	if (!fin.is_open())
	{
		return;
	}
	int id;
	string titlu, tip;
	double pret;
	while (fin >> id >> titlu >> tip >> pret)
	{
		Carte carte{ id,titlu,tip,pret };
		carti.push_back(carte);
	}
}

void FileRepo::WriteToFile()
{
	ofstream fout{ filename };
	if (!fout.is_open())
	{
		return;
	}
	for (auto car : carti)
	{
		fout << car.getid() << " ";
		fout << car.gettitlu() << " ";
		fout << car.gettip() << " ";
		fout << car.getpret() << "\n";
	}
}


void FileRepo::addRepo(const Carte& car)
{
	for (auto carte : carti)
	{
		if (car.getid() == carte.getid())
		{
			throw RepoException("Id existent!\n");
		}
	}
	carti.push_back(car);
	WriteToFile();
}
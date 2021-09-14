#include "FileRepo.h"
#include "Tractor.h"
#include <fstream>

void FileRepo::LoadFromFile()
{
	ifstream fin{ filename };
	if (!fin.is_open())
	{
		return;
	}
	int id, nrroti;
	string descriere, tip;
	while (fin >> id >> descriere >> tip >> nrroti)
	{
		Tractor trac{ id,descriere,tip,nrroti };
		tractoare.push_back(trac);
	}
}


void FileRepo::WriteToFile()
{
	ofstream fout{ filename };
	if (!fout.is_open())
	{
		return;
	}
	for (auto trac : tractoare)
	{
		fout << trac.getid() << " ";
		fout << trac.getdenumire() << " ";
		fout << trac.gettip() << " ";
		fout << trac.getnrroti() << "\n";
	}
}


void FileRepo::addRepo(const Tractor& trac)
{
	for (auto t : tractoare)
	{
		if (t.getid() == trac.getid())
		{
			throw FileRepoException("Exista deja tractorul cu id-ul respectiv!\n");
		}
	}
	tractoare.push_back(trac);
	WriteToFile();
}
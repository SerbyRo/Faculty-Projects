#include "FileRepoArticol.h"
#include <fstream>

void FileRepoArticol::LoadfromFile()
{
	ifstream fin{ this->filename };
	if (!fin.is_open())
	{
		return;
	}
	vector<Articol> listanoua;
	while (!fin.eof())
	{
		string nume, tip;
		int marime, stoc;
		fin >> nume;
		if (fin.eof())
		{
			break;
		}
		fin >> tip >> marime >> stoc;
		Articol art{ nume,tip,marime,stoc };
		listanoua.push_back(art);
	}
	articole = listanoua;
	fin.close();
}

void FileRepoArticol::WriteToFile()
{
	ofstream fout{ this->filename };
	if (!fout.is_open())
	{
		return;
	}

	for (auto art : articole)
	{
		fout << art.getnume() << " ";
		fout << art.gettip() << " ";
		fout << art.getmarime() << " ";
		fout << art.getstoc() << endl;
	}
	fout.close();
}

void FileRepoArticol::addrepo(const Articol& art)
{
	articole.push_back(art);
	WriteToFile();
}

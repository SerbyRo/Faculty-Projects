#pragma once
#include "Articol.h"
#include <vector>
#include <string>
class FileRepoArticol
{
private:
	vector<Articol> articole;
	string filename;
	void LoadfromFile();
	void WriteToFile();
public:
	FileRepoArticol(const string filename) :filename{ filename } {
		LoadfromFile();
		WriteToFile();
	}
	/*
	* functie care preia toate elementele din fisier
	* pre-
	* post-vectorul de articole
	*/
	vector<Articol>& getAllRepo()
	{
		LoadfromFile();
		return articole;
	}
	/*
	* functie prin intermediul careia se adauga un element in lista
	* pre-un articol de tip Articol
	* post-modificarea listei
	*/
	void addrepo(const Articol& art);
};


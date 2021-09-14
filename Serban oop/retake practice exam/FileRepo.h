#pragma once
#include "Tractor.h"


class FileRepoException {
	string erori;
public:
	FileRepoException(string erori) :erori{ erori } {}

	string geterori()
	{
		return erori;
	}
};

class FileRepo
{
private:
	vector<Tractor>tractoare;
	string filename;
public:
	void LoadFromFile();
	void WriteToFile();
	FileRepo(string filename) :filename{ filename } {
		LoadFromFile();
	}

	/*
	* functionalitate care returneaza lista de tractoare din fisier
	*/
	const vector<Tractor>& getAllRepo() const
	{
		return tractoare;
	}
	/*
	* functionalitate prin intermediul careia se adauga un tractor in lista
	* pre- tractorul care va fi adaugat 
	* post- lista modificata in urma adaugarii tractorului
	*/
	void addRepo(const Tractor& trac);
};


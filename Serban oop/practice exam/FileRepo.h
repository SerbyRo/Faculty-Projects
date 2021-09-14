#pragma once
#include "Carte.h"

class RepoException {
private:
	string erori;
public:
	RepoException(string erori) :erori{ erori } {};

	string geterori()
	{
		return erori;
	}
};


class FileRepo
{
private:
	vector<Carte> carti;
	string filename;
public:
	void LoadFromFile();
	void WriteToFile();
	FileRepo(string filename) :filename{ filename } {
		LoadFromFile();
	};

	const vector<Carte>& getAllRepo() const
	{
		return carti;
	}

	/*
	* functionalitate care adauga o carte in lista
	* pre- o entitate de tip Carte
	* post- modificarea listei , ulterior adaugarii cartii respective
	*/
	void addRepo(const Carte& carte);
};


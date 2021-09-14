#pragma once
#include "FileRepoArticol.h"
#include "Articol.h"
#include <string>
class ServiceArticol
{
private:
	FileRepoArticol& filerepo;
public:
	ServiceArticol(FileRepoArticol& filerepo) :filerepo{ filerepo } {

	}
	/*
	* functie de getAll prin care preia toate elementele din service
	*/
	vector<Articol>& getAllService()
	{
		return filerepo.getAllRepo();
	}
	/*
	* functie de gasire a unui articol dupa un nume dat 
	* pre-string nevid care reprezinta numele 
	* post-articolul respectiv
	*/
	Articol findart(string nume);
	/*
	* functie care adauga un articol in lista
	* pre-articolul care va fi adaugat
	* post-modificarea listei
	*/
	void addService(const Articol& art);
	/*
	* functie care filtreaza dupa nume
	* pre-un string nevid reprezentand numele
	* post-articolul cu acel nume
	*/
	vector<Articol> filternume(string nume);
	/*
	* functie care filtreaza dupa nume
	* pre-un numar natural nenul
	* post-articolul cu acea marime
	*/
	vector<Articol> filtermarime(int marime);


	void stergeService(int stoc);
};


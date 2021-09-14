#pragma once
#include "Masina.h"
#include "RepoMasina.h"
#include <vector>
#include <string>
#include <functional>
#include "Validatori.h"

using std::string;
using std::vector;
using std::function;


class ServiceMasina
{
private:
	RepoMasina& repomasini;
	ValidateMasina& validator;
	/*
	 Functie de sortare generala
	 maiMareF - functie care compara 2 Masini, verifica daca are loc relatia mai mare
			  - poate fi orice functie (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Masina)
			  - poate fi functie lambda (care nu capteaza nimic in capture list)
	 returneaza o lista sortata dupa criteriu dat ca paramatru
	*/
	vector<Masina> generalSort(bool (*maiMicF)(const Masina&, const Masina&));
	/*
	Functie generala de filtrare
	fct - poate fi o functie
	fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
	returneaza doar masinile care trec de filtru (fct(pet)==true)
	*/
	vector<Masina> filtreaza(function<bool(const Masina&)> fct);
public:
	/*
	* constructorul clasei implicit care initializeaza campurile 
	* acesteia cu null
	*/
	ServiceMasina(RepoMasina& repomasini,ValidateMasina& validator):repomasini{repomasini},validator{validator}{}
	//nu permitem copierea de elemente
	ServiceMasina(const RepoMasina& repo) = delete;
	/*
	 returneaza toate animalele in ordinea in care au fost adaugate
	*/
	const vector<Masina>& getAll() noexcept {
		return repomasini.getAll();
	}
	/*
	Adauga un nou pet
	arunca exceptie daca: nu se poate salva, nu este valid
	*/
	void addMasina(const string& nrinmatriculare, const string& producator, const string& tip, const string& model);

	/*
	Sorteaza dupa nrinmatriculare
	*/
	vector<Masina> sortbynrinmatriculare();

	/*
	* Sorteaza dupa tip
	*/
	vector<Masina> sortbytip();

	/*
	Sorteaza dupa producator+model
	*/
	vector<Masina> sortbyproducatormodel();

	/*
	* Filtrare dupa producator
	*/
	vector<Masina> filterbyproducator(string producator);
	/*
	* Filtrare dupa tip
	*/
	vector<Masina> filterbytip(string tip);
};


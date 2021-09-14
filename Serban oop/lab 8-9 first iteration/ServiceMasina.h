#pragma once

#include "Masina.h"
#include "RepoMasina.h"
#include <vector>
#include <string>
#include <functional>
#include "Validatori.h"
#include "ManageMasini.h"
#include <map>
#include "DTO.h"

using std::map;

using std::string;
using std::vector;
using std::function;


class ServiceMasina
{
private:
	RepoMasina& repomasini;
	ValidateMasina& validator;
	ManageMasini& worklist;

public:
	ServiceMasina(RepoMasina& repomasini, ValidateMasina& validator, ManageMasini& worklist) noexcept :repomasini{ repomasini }, validator{ validator }, worklist{ worklist }{}
	//nu permitem copierea de elemente
	ServiceMasina(const RepoMasina& repo) = delete;
	/*
	 returneaza toate animalele in ordinea in care au fost adaugate
	*/
	const vector<Masina>& getAll() noexcept {
		return repomasini.getAll();
	}
	/*
		Adauga o masina
		pre-numar de inmatricualre string nevid
			producator string nevid
			tip string nevid
			model string nevid
		post-modificarea listei
	*/
	void addMasina(const string& nrinmatriculare, const string& producator, const string& tip, const string& model);

	/*
	* Functie care cauta o masina in lista
	* pre-numardeinmatriculare string nevid
	* post-true, in caul in care exista
	*	   false, altfel
	*/
	bool searchservice(string nrinmatriculare);

	/*
	* Functie care modifica o masina in lista
	* pre-numar de inmatricualre string nevid
			producator string nevid
			tip string nevid
			model string nevid
	  post-modificarea masinii
	*/
	void updateservice(string nrinmatriculare, string producator, string tip, string model);

	/*
	* Functie care sterge o materie
	* pre-numar de inmatricularee string nevid
	* post-modificarea listei
	*/
	void deleteservice(string nrinmatriculare);


	vector<Masina> generalsort(int cmd);

	/*
	* Filtrare dupa producator
	* pre- producator string nevid
	* post-lista cu masinile care au producatorul dat
	*/
	vector<Masina> filterbyproducator(string producator);
	/*
	* Filtrare dupa tip
	* pre-tip string nevid
	* post-lista cu masinile care au tipul dat
	*/
	vector<Masina> filterbytip(string tip);
	/*
	* functie prin intermediul careia golesc lista
	*/
	int listagoala();
	/*
	* functie care adauga o masina in worklist
	* pre-numar de inmatriculare string nevid
	* post-modificarea worklistului
	*/
	void addworkcar(string nrinmatriculare);
	/*
	* functie prin care se genereaza random elemente in worklist 
	* pre-numarul de masini generate random
	* post-
	*/
	void generaterandomlist(const int random_number);
	/*
	* functie care returneaza lista de masini din worklist
	*/
	vector<Masina>& getworklist();
	/*
	* functie care cauta daca dto-ul respectiv s-a creat sau nu
	* pre-dictionar care are ca si cheie string nevid ce reprezinta modelul 
	*/
	int searchDTO(map<string, DTO> dict, string model) noexcept;
	/*
	* functie care face raportul efectiv de tip map
	*/
	map<string, DTO> raport();
	/*
	* functie prin intermediul careia se salveaza lista intr-un fisier CVS sau HTML
	*/
	void saveworklistinCVS(string file);
};


#pragma once
#include "FileRepo.h"
#include "Tractor.h"
#include "Validatori.h"
class ServiceTractor
{
	FileRepo& filerepo;
	Validatori& val;
public:
	ServiceTractor(FileRepo& filerepo, Validatori& val):filerepo{filerepo},val{val}{}

	/*
	* functionalitate care preia toate tractoarele din lista 
	*/
	const vector<Tractor>& getAllService() const
	{
		return filerepo.getAllRepo();
	}

	/*
	* functionalitate prin intermediul careia se adauga un tractor in lista
	  pre-entitatile unui obiect de tip tractor:id , descriere , tip si numar de roti
	  post- lista modificata in urma adaugarii tractorului 
	*/
	void addService(int id, string descriere, string tip, int nrroti);

	/*
	* functionalitate prin intermediul careia se sorteaza lista de tractoare dupa denumire
	* pre-
	* post-lista sortata
	*/
	vector<Tractor> sortbydenumire();

	/*
	* functionalitate prin intermediul careia se filtreaza lista de tractoare dupa filtrul ales in ComboBox
	* pre- string reprezentand tipul dupa care se face filtrarea
	* post-lista filtrata
	*/
	vector<Tractor> filterbytip(string tip);

	/*
	* functionalitate care returneaza tipurile distincte de tractoare
	* pre-
	* post-vector de stringuri
	*/
	vector<string> nrtipuri();
};


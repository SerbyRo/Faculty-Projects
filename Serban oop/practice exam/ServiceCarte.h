#pragma once
#include "FileRepo.h"
#include "Carte.h"
#include "Validatori.h"
#include <algorithm>
class ServiceCarte
{
private:
	FileRepo& repocarti;
	Validatori& val;
public:
	ServiceCarte(FileRepo& repocarti, Validatori& val) :repocarti{ repocarti }, val{ val }{};
	/*
	* functionalitate care preia toate cartile din repo
	*/
	const vector<Carte> getAllService() const
	{
		return repocarti.getAllRepo();
	}

	/*
	* functionalitate prin car ese adauga o carte si primeste ca si parametri elementele acesteia
	* id- numar natural nenul
	* titlu- stringnevid
	* tip - string nevid
	* pret - numar real pozitiv
	*/
	void addService(int id, string titlu, string tip, double pret);



	/*
	* functionalitate care sorteaza cartile dupa numarul de litere din tip
	*/

	vector<Carte> sortbyliteretip()
	{
		vector<Carte> carti = repocarti.getAllRepo();
		sort(carti.begin(), carti.end(), [&](Carte& car1, Carte& car2) {
			return car1.gettip().size() < car2.gettip().size();
			});
		return carti;
	}
};


#pragma once

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;

using std::ostream;


class Masina
{
private:
	string nrinmatriculare;
	string producator;
	string tip;
	string model;
public:
	Masina() = default;
	/*
	* constructorul clasei Masina
	* prin intermediu acestuia se initializeaza cele 4 campuri ale clasei cu Null
	*/
	Masina(const string nrinmatriculare, const string producator, const string tip, const string model) :
		nrinmatriculare{ nrinmatriculare }, producator{ producator }, tip{ tip }, model{ model }{

	}
	/*
	* constructorul de copiere
	* se apeleaza de fiecare data cand se face o copie a elementului Masina
	* se evita copierea acolo unde nu este cazul
	*/
	Masina(const Masina& mas) :nrinmatriculare{ mas.nrinmatriculare }, producator{ mas.producator }, tip{ mas.tip }, model{ mas.model }{
		cout << "Copy constructor done!\n";
	}
	/*
	* functie getter pentru numar de inmatriculare
	*/
	string getnrinmatriculare() const {
		return nrinmatriculare;
	}
	/*
	* functie getter pentru producator
	*/
	string getproducator() const {
		return producator;
	}
	/*
	* functie getter pentru tip
	*/
	string gettip() const {
		return tip;
	}
	/*
	* functie getter pentru model
	*/
	string getmodel() const {
		return model;
	}
	/*
	* functie prin care se suprascrie operatia de egalitate intre doua masini
	*/
	bool egal(const Masina& ot) const;
	/*
	* functie de suprascriere a operatorului de insertie a unei masini
	*/
	friend ostream& operator<<(ostream& os, const Masina& mas)
	{
		os << mas.getnrinmatriculare() << " " << mas.getproducator() << " " << mas.gettip() << " " << mas.getmodel() << "\n";
		return os;
	}
};

/*
Compara dupa numar de inmatriculare
returneaza true daca mas1.tip e mai mic decat mas2.tip
*/
bool cmpnrinmatriculare(const Masina& mas1, const Masina& mas2);
/*
Compara dupa tip
returneaza true daca mas1.tip e mai mic decat mas2.tip
*/
bool cmptip(const Masina& mas1, const Masina& mas2);


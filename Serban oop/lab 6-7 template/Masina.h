#pragma once
#include <string>
#include <iostream>


using std::string;
using std::cout;

class Masina
{
private:
	string nrinmatriculare;
	string producator;
	string tip;
	string model;
public:
	/*
	* constructorul clasei Masina
	* prin intermediu acestuia se initializeaza cele 4 campuri ale clasei cu Null
	*/
	Masina(const string nrinmatriculare,const string producator,const string tip,const string model):
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
	* functie getter
	* returneaza numarul de inmatriculare al masinii
	*/
	string getnrinmatriculare() const{
		return nrinmatriculare;
	}
	/*
	* functie getter
	* returneaza producatorul  masinii
	*/
	string getproducator() const {
		return producator;
	}
	/*
	* functie getter
	* returneaza tipul masinii
	*/
	string gettip() const {
		return tip;
	}
	/*
	* functie getter
	* returneaza modelul masinii
	*/
	string getmodel() const {
		return model;
	}
};

/*
Compara dupa numar de inmatriculare
returneaza true daca mas1.nrinmatriculare e mai mic decat mas2.nrinmatriculare
*/
bool cmpnrinmatriculare(const Masina& mas1, const Masina&mas2);
/*
Compara dupa tip
returneaza true daca mas1.tip e mai mic decat mas2.tip
*/
bool cmptip(const Masina& mas1, const Masina& mas2);


#pragma once

#include "Masina.h"
#include "Validatori.h"
//#include "VectorTemplate.h"

#include <vector>
#include <string>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;

class RepoMasina
{
private:
	vector<Masina>repomasini;
	bool exist(const Masina& mas);
public:
	RepoMasina() = default;
	//nu permitem copierea elementelor
	RepoMasina(const RepoMasina& masina) = delete;
	/*
	Salvare masina
	arunca exceptie daca mai exista o masina cu acelasi nrinmatriculare
	*/
	void store(const Masina& mas);

	/*
	*   Cautare masina
	*	returneaza o masina
	*
	*/
	Masina getMasina(const Masina& mas);


	/*
	* Cautare masina
	* arunca exceptie daca nu exista acea masina
	*/
	int searchrepo(const Masina& mas);

	/*
	* Updatare masina
	* arunca exceptie daca nu exista acea masina
	*/
	void updaterepo(const Masina& mas);

	/*
	* Stergere masina
	* arunca exceptie daca
	*/
	void deleterepo(const Masina& mas);
	/*
	Cauta
	arunca exceptie daca nu exista animal
	*/
	const Masina& find(string nrinmatriculare) const;
	/*
	* returneaza toate masinile din lista
	*/
	const vector<Masina>& getAll() const noexcept;
};
class RepoException {
	string message;
public:
	/*
	* constructorul implicit
	*/
	RepoException(const string& msg) :message{ msg } {}
	/*
	* functie care suprascrie operatorul de insertie
	*/
	friend ostream& operator<<(ostream& out, const RepoException& erori);
};

ostream& operator<<(ostream& out, const RepoException& erori);



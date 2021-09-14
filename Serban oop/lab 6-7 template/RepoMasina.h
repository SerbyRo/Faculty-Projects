#pragma once
#include "Masina.h"
#include "Validatori.h"


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
	//constructorul implicit al clasei
	RepoMasina() = default;
	//nu permitem copierea elementelor
	RepoMasina(const RepoMasina& masina) = delete;
	/*
	Salvare masina
	arunca exceptie daca mai exista o masina cu acelasi nrinmatriculare
	*/
	void store(const Masina& mas);
	/*
	Cauta
	arunca exceptie daca nu exista masina
	*/
	const Masina& find(string nrinmatriculare) const;
	/*
	* returneaza toate masinile din lista
	*/
	const vector<Masina>& getAll() const noexcept;

	/*
	* Functie care sterge o masina 
	*/
	//void deleterepo(const Masina& mas);
	
};
class RepoException {
	string message;
public:
	RepoException(const string& msg):message{msg}{}
	friend ostream& operator<<(ostream& out, const RepoException& erori);
};

ostream& operator<<(ostream& out, const RepoException& erori);
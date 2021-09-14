#pragma once

#include "Masina.h"
#include "Validatori.h"
//#include "VectorTemplate.h"

#include <vector>
#include <string>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <map>


using std::vector;
using std::string;
using std::ostream;
using std::map;
using std::make_pair;

class RepoMasina
{
private:

public:
	RepoMasina() = default;
	//nu permitem copierea elementelor
	RepoMasina(const RepoMasina& masina) = delete;
	/*
	Salvare masina
	arunca exceptie daca mai exista o masina cu acelasi nrinmatriculare
	*/
	virtual void store(const Masina& mas) = 0;
	/*
	*   Cautare masina
	*	returneaza o masina
	*/
	 virtual Masina getMasina(const Masina& mas) = 0;
	/*
	* Cautare masina
	* arunca exceptie daca nu exista acea masina
	*/
	 virtual int searchrepo(const Masina& mas) = 0;

	/*
	* Updatare masina
	* arunca exceptie daca nu exista acea masina
	*/
	virtual void updaterepo(const Masina& mas) = 0;

	/*
	* Stergere masina
	* arunca exceptie daca
	*/
	virtual void deleterepo(const Masina& mas) = 0;
	/*
	Cauta
	arunca exceptie daca nu exista animal
	*/
	virtual const Masina& find(string nrinmatriculare) const = 0;
	/*
	* returneaza toate masinile din lista
	*/
	virtual const vector<Masina>& getAll() const noexcept = 0;

	virtual bool exist(const Masina& mas) = 0;

	virtual const int getSize() const noexcept = 0;

	virtual ~RepoMasina() = default;
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

class MemoryRepo : public RepoMasina {
private:
	vector<Masina> repomasini;
public:
	MemoryRepo() noexcept : RepoMasina(),repomasini{ }{}
	virtual void store(const Masina& mas) override;
	virtual int searchrepo(const Masina& mas) override;
	virtual void deleterepo(const Masina& mas) override;
	virtual void updaterepo(const Masina& mas) override;
	virtual const Masina& find(string nrinmatriculare) const override;
	virtual bool exist(const Masina& mas) override;
	Masina getMasina(const Masina& mas) override;
	const vector<Masina>& getAll() const noexcept override;
	const int getSize() const noexcept override;
};



class RepoFileMasina:public MemoryRepo {
private:
	string filename;
	void loadFromFile();
	void writeToFile();
public:
	RepoFileMasina(string filename) :MemoryRepo(), filename{ filename }{
		loadFromFile();
	}
	void store(const Masina& mas) override;
	void updaterepo(const Masina& mas) override;
	void deleterepo(const Masina& mas) override;
};




class FileRepoException {
	string message;
public:
	/*
	* constructorul implicit
	*/
	FileRepoException(const string& msg) :message{ msg } {}
	/*
	* functie care suprascrie operatorul de insertie
	*/
	friend ostream& operator<<(ostream& out, const FileRepoException& erori);
};

ostream& operator<<(ostream& out, const FileRepoException& erori);


class LabRepo :public RepoMasina {
private:
	map<string, Masina> all_masini;
	vector<Masina> all_masini_vector;
	double probabilitate;
	void throwprobabilityexception() const;
public:
	LabRepo(const double probabilitate) noexcept :RepoMasina(), all_masini{}, all_masini_vector{}, probabilitate{ probabilitate }{

	}
	void store(const Masina& mas) override;
	int searchrepo(const Masina& mas) override;
	void deleterepo(const Masina& mas) override;
	void updaterepo(const Masina& mas) override;
	const Masina& find(string nrinmatriculare) const override;
	Masina getMasina(const Masina& mas) override;
	bool exist(const Masina& mas) override;
	const vector<Masina>& getAll() const noexcept override;
	const int getSize() const noexcept override;

};
#pragma once
#include "Masina.h"
#include"RepoMasina.h"
#include <vector>
#include <random>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
using std::ofstream;

class ManageMasini
{
private:
	vector<Masina> masini;
public:
	/*
	* constructorul implicit
	*/
	ManageMasini() = default;
	/*
	* destructorul implicit
	*/
	~ManageMasini() = default;
	/*
	* funtie prin intermediul careia se goleste worklist-ul 
	*/
	void goleste() noexcept
	{
		masini.clear();
	}
	/*
	* functie prin intermediul careia se adauga o masina in worklist
	* pre-obiect de tip Masina
	* post-modificarea listei
	*/
	void adauga(const Masina& mas); //{
		//if (std::find(masini.begin(), masini.end(), mas).operator==(masini.end()))
		//{
			//masini.push_back(mas);
		//}
		//else
		//{
			//cout << "Masina exista deja in lista!";
		//}
	//}
	/*
	* functie care returneaza numarul de masini din worklist
	*/
	const int getSize() const noexcept;
	/*
	* functie prin intermediul careia se genereaza random masini
	* pre-rdm_number de tip intreg si un vector de masini de tip Masina
	*/
	void genereazarandomlista(const int rdm_number, vector<Masina> allmasini);
	/*
	* functie care returneaza toate masinile din worklist
	*/
	vector<Masina>& getallmasini() noexcept {
		return masini;
	}
	/*
	* functie care primeste ca si parametru un fisier si stocheaza informatiile din worklist intr-un fisier CVS sau HTML
	* pre-numele fisierului
	* post-popularea fisierului
	*/
	void storetoCVS(string file)
	{
		ofstream fout(file);
		for (auto iterator : masini)
		{
			fout << iterator << "\n";
		}
		fout.close();
	}
};



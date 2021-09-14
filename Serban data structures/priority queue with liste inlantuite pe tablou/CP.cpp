#include "CP.h"
#include <exception>
#include <stdio.h>
#include <iostream>
using namespace std;

using std::cout;


//25.TAD Coada cu priorități – reprezentare sub forma unei LSI cu perechi(element, prioritate) 
//ordonate în funcție de priorități(în raport cu o relație de ordine ).


void CP::redim()
{
	//compexitate O(capacitate)
	Element* elem_nou = new Element[2 * this->capacitate];
	int* legurmatornou = new int[2 * this->capacitate];
	
	for (int i = 0;i < this->capacitate;i++)
	{
		elem_nou[i] = this->elemente[i];
		legurmatornou[i] = this->legatura_urmator[i];
	}
	
	//lista spatiului liber
	for (int i = this->capacitate;i < (2 * this->capacitate) - 1;i++)
	{
		legurmatornou[i] = i + 1;
	}
	
	legurmatornou[(2*this->capacitate)-1] = -1;

	delete[] elemente;
	delete[] legatura_urmator;
	this->elemente = elem_nou;
	this->legatura_urmator = legurmatornou;

	this->prim_liber = this->capacitate;
	this->capacitate = 2 * this->capacitate;
}



CP::CP(Relatie r) {
	/* de adaugat */
	//complexitate theta(1)
	this->rel = r;
	this->capacitate = 10;
	this->dimensiune = 0;
	elemente = new Element[this->capacitate];
	legatura_urmator = new int[this->capacitate];

	//lista spatiului liber
	//complexitate theta(capacitate)
	for (int i = 0;i < this->capacitate-1;i++)
	{
		this->legatura_urmator[i] = i + 1;
	}
	this->legatura_urmator[this->capacitate - 1] = -1;
	this->prim = -1;
	this->prim_liber = 0;
	
}


int CP::aloca()
{
	//complexitate theta(1)
	int i = this->prim_liber;
	this->prim_liber = this->legatura_urmator[prim_liber];
	this->dimensiune++;
	return i;
}



void CP::dealoca(int i)
{
	//complexitate theta(1)
	this->legatura_urmator[i] = this->prim_liber;
	this->prim_liber = i;
	this->dimensiune--;
}


int CP::creeazaNod(Element element) {
	//complexitate O(capacitate)
	if (this->prim_liber == -1)
	{
		redim();
	}
	//complexitate amortizata theta(1)
	int i = aloca();
	this->elemente[i] = element;

	return i;
}

void CP::adauga(TElem e, TPrioritate p) {
	/* de adaugat */
	
	if (this->dimensiune >= this->capacitate)
		redim();

	Element nouelement;
	nouelement.first = e;
	nouelement.second = p;
	int i = creeazaNod(nouelement);
	//daca nu avem elemente in lista
	//complexitate amortizata theta(1)
	if (this->prim == -1)
	{
		legatura_urmator[i] = -1;
		this->prim = i;
		return;
	}

	//daca adaugam la inceputul listei
	//compexitate theta(1)
	if (rel(p, elemente[this->prim].second))
	{
			legatura_urmator[i] = prim;
			this->prim = i;
			return;
	}
	//complexitate O(n)
	int legatura_anterior = this->prim;
	int curent = legatura_urmator[prim];
	while ( !rel(p, elemente[curent].second) && curent != -1)
		{
				curent = legatura_urmator[curent];
				legatura_anterior = legatura_urmator[legatura_anterior];
		}
	int copie = legatura_urmator[legatura_anterior];
	legatura_urmator[legatura_anterior] = i;
	legatura_urmator[i] = copie;
	return;

}

//arunca exceptie daca coada e vida
Element CP::element() const {
	/* de adaugat */
	//complexitate theta(1)
	if (vida())
	{
		throw exception("Lista e vida!");
	}
	else
	{
		return this->elemente[this->prim];
	}
}

Element CP::sterge() {
	/* de adaugat */
	//daca nu avem elemente in lista
	//complexitate theta(1) deoarece se sterge la inceputul listei
	if (vida())
	{
		throw exception("Lista este vida!");
	}
	Element elementsters = this->elemente[prim];
	int sters = prim;
	this->prim = legatura_urmator[prim];
	dealoca(sters);
	return elementsters;
}

bool CP::vida() const {
	/* de adaugat */
	//complexitate theta(1)
	return this->dimensiune == 0;
}
CP::~CP() {
	/* de adaugat */
	//complexitate theta(1)
	delete[] elemente;
	delete[] legatura_urmator;
};

/*
* caz favorabil:theta(dimensiune)
* caz defavorabil:theta(dimensiune)
* caz mediu:theta(dimensiune)
* overall:theta(dimensiune)
*/

TPrioritate CP::schimbaprioritate(TElem elem, TPrioritate prioritatenoua)
{
	CP cp(rel);
	int length = cp.getdimensiune();
	int ok = 0;
	for (int i = 0;i < length;i++)
	{
		Element elem1 = cp.sterge();
		if (elem1.first==elem)
		{
			ok = 1;
			TPrioritate prioritateveche = elem1.second;
			elem1.second = prioritatenoua;
			return prioritateveche;
		}
	}
	if (ok == 0)
	{
		prioritatenoua = -1;
		return prioritatenoua;
	}
}

/*
* Pseudocod:
* Subalgoritm schimbaprioritate(TElem elem , TPrioritate prioritatenoua,CP& cp)
* pre-un obiect de tip TElem elem
*     un obiect de tip TPrioritate prioritatenoua
* post-returneaza prioritatea veche daca elemenul exista in lista
*	  altfel , returneaza -1
*	  cp'
*  CP cp(rel)
*  length=cp.getdimensiune()
*  ok=0
*  pentru i=0,length executa
*     Element elem1=cp.sterge()
*	  daca elem1.first =elem atunci
*			ok=1
*			TPriortate prioritateveche=elem1.second
*			elem1.second=prioritatenoua
*			returneaza prioritateveche
*	  sfdaca
*  sfpentru
*  daca ok=0 atunci
*		prioritatenoua=-1
*		returneaza prioritatenoua
*  sfdaca
* sfSubalgoritm
*/


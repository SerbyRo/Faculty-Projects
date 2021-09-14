#include "Colectie.h"
#include "Iterator.h"
#include <exception>
#include <iostream>

using namespace std;


void Colectie::redim()
{
	//complexitate theta(lg)
	TElem* elemsNou = new int[2 * cp];
	for (int i = 0;i < lg;i++)
	{
		elemsNou[i] = elems[i];
	}
	cp = 2 * cp;
	delete[] elems;
	elems = elemsNou;
}


Colectie::Colectie() {
	/* de adaugat */
	//dim = 0;
	this->cp = 1;

	//alocam spatiul de memorare pentru vector 
	elems = new TElem[cp];
	poz = new TElem[cp];
	//setam numarul de elemente
	this->lg = 0;   
}


void Colectie::adauga(TElem elem) {
	/*
	* v = [1, 3]
	*
	* D = [1, 3]
	* p = [0, 2]
	*/
	//complexitate amortizata theta(1) ,in cazul in care lungimea depaseste capacittea va fi complexitate de O(lg)
	if (lg == cp)
	{
		redim();
	}
	this->elems[lg++] = elem;
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	//complexitate O(lg);daca este ultimul element cel sters , va fi complexitate amortizata theta(1)
	for (int i = 0;i < lg;i++)
	{
		if (this->elems[i] == elem)
		{
			for (int j = i;j < lg - 1;j++)
			{
				this->elems[j] = this->elems[j + 1];
			}
			this->lg = this->lg - 1;
			return true;
		}
	}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	//complexitate O(lg)
	for (int i = 0;i < lg;i++)
	{
		if (this->elems[i] == elem)
			return true;
	}
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	//complexitate O(lg)
	int contor = 0;
	for (int i = 0;i < lg;i++)
	{
		if (this->elems[i] == elem)
		{
			contor++;
		}
	}
	return contor;
}


int Colectie::dim() const {
	/* de adaugat */
	//complexitate theta(1)
	return this->lg;
}


bool Colectie::vida() const {
	/* de adaugat */
	//return dim == 0;
	//complexitate theta(1)
	return this->lg == 0;
}

IteratorColectie Colectie::iterator() const {
	//complexitate theta(1)
	return  IteratorColectie(*this);
}



Colectie::~Colectie() {
	/* de adaugat */
	//complexitate theta(1)
	delete[] elems;
	//delete[] poz;
}



#pragma once
#include "Colectie.h"

class Colectie;
typedef int TElem;
/**
* v = [10, 11, 12, 13, 14]
*/

class IteratorColectie
{
	friend class Colectie;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorColectie(const Colectie& c);

	//contine o referinta catre containerul pe care il itereaza
	const Colectie& col;
	/* aici e reprezentarea specifica a iteratorului int i = -1*/


	//pozitia curenta in iterator
	int curent;

	int frecventa;


public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;
};


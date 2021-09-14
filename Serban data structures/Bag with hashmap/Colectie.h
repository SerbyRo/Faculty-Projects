#pragma once
#include <vector>

#define NULL_TELEM -1
typedef int TElem;

const long long NMax=25000;

class IteratorColectie;



class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	//numarul de locatii din tabela de dispersie
	int m;
	//vectorul elementelor-vector static
	TElem e[NMax];
	//functia de dispersie extinsa
	int hashfunction(TElem e, int i) const;
	int lungime=0;
	//frecventa fiecarui element in parte
	int frecventa[NMax];
public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	void intersectie(const Colectie& b);

	// destructorul colectiei
	~Colectie();

};



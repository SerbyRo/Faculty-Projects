#pragma once


#define NULL_TELEM -1
typedef int TElem;
typedef bool(*Relatie)(TElem, TElem);

class IteratorMultime;

class Nod;

typedef Nod* PNod;

class Nod {
	friend class Multime;
private:
	TElem elem;
	PNod stanga;
	PNod dreapta;

public:
	Nod(TElem elem, PNod stanga, PNod dreapta);

	TElem getelement() const ;
	PNod getstanga() const;
	PNod getdreapta() const;
};


bool rel(TElem, TElem);

class Multime {
	friend class IteratorMultime;

private:
	/* aici e reprezentarea */
	PNod radacina;

	PNod adauga_recursiv(PNod p, TElem elem); // nefolosita
	PNod sterge_recursiv(PNod p, TElem elem);
	PNod cauta_recursiv(PNod p, TElem elem) const;
	PNod nod_minim(PNod nod);
	void distrug_recursiv(PNod p); // nefolosita

public:
	//constructorul implicit
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	bool adauga(TElem e);

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	bool sterge(TElem e);

	//verifica daca un element se afla in multime
	bool cauta(TElem elem) const;

	void intersectie(const Multime& mul);

	//intoarce numarul de elemente din multime;
	int dim() const;

	//verifica daca multimea e vida;
	bool vida() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	// destructorul multimii
	~Multime();
};






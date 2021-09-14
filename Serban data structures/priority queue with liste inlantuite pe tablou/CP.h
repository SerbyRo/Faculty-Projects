#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>


using std::ostream;

using namespace std;

typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool (*Relatie)(TPrioritate p1, TPrioritate p2);

class CP {
private:
	/* aici reprezentarea */
    // relatia intre chei
    Relatie rel;

    // vector dinamic de elemente
    int capacitate;

    int dimensiune;

    // vector de elemente
    Element* elemente;

    // vector de legatura
    int* legatura_urmator;

    // pentru redimensionare
    void redim();

    // primul element al listei
    int prim;

    // primul element liber
    int prim_liber;

    // functii pentru alocarea/dealocarea unui spatiu liber
    // se returneaza pozitia unui spatiu liber in lista
    int aloca();

    // dealoca spatiul de indice i
    void dealoca(int i);

    

    // functie privata care creeaza un nod in lista inlantuita
    int creeazaNod(Element element);
public:
	//constructorul implicit
	CP(Relatie r);

	//adauga un element in CP
	void adauga(TElem e, TPrioritate p);

	//acceseaza elementul cel mai prioritar in raport cu relatia de ordine
	//arunca exceptie daca CP e vida
	Element element()  const;

	//sterge elementul cel mai prioritar si il returneaza
	//arunca exceptie daca CP e vida
	Element sterge();

	//verifica daca CP e vida;
	bool vida() const;

	// destructorul cozii
	~CP();


    //functie care modifica prioritatea unui element
    TPrioritate schimbaprioritate(TElem elem, TPrioritate prioritatenoua);

   
    int getdimensiune()
    {
        return this->dimensiune;
    }
};




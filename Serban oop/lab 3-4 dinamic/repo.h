#ifndef REPO_H
#define REPO_H
#include "domain.h"

typedef Cheltuiala Elemtype;

typedef struct {
	Elemtype* elems;
	int lg;
	int cap;
}Lista;

/*
* functie care creeaza lista vida
* pre-
* post-lista vida
*/
Lista create_list_vid();

/*
* functie de eliberare/distrugere a functiei
* pre-lista de tipul Lista care va fi distrusa
* post-distrugerea acesteia
*/
void destroy_list(Lista* l);

/*
* functie care returneaza un element al listei
* pre-lista de cheltuieli de tip lista si pozitia elementului 
* post-elementul returnat
*/
Elemtype get_expense(Lista* l, int poz);


/*
* functie care modifica un element al listei
* pre-lista de cheltuieli de tip Lista ,pozitia elementului si cheltuiala cu care va fi inlocuit
* post-lista modificata
*/
Elemtype set_expense(Lista* l, int poz, Cheltuiala c);


/*
* functie care returneaza lungimea listei
* pre-lista de cheltuiala de tip Lista
* post-lungimea acesteia
*/
int size(Lista* l);


/*
* functie care adauga un element de tip Cheltuiala in lista
* pre-lista de cheltuieli de tip Lista sicheltuiala pe care o adaugam
* post-lista modificata
*/
void add_expense(Lista* l, Elemtype el);

/*
* functie care copiaza lista
* pre-lista de cheltuieli de tip Lista
* post-copia listei
*/
Lista copy_list(Lista* l);


/*
* functie prin care modificam capacitatea listei :o dublam pe aceasta 
* pre-lista de cheltuieli de tip Lista 
* post-modificarea capacitatii listei
*/
void ensureCapacity(Lista* l);

/*
* functie care sorteaza lista descrescator in functie de suma
* pre-lista de cheltuieli de tip Lista
* post-lista de cheltuieli de tip Lista ordonata
*/
void sort_repo_by_sum(Lista* l);


/*
* functie care sterge o cheltuiala
* pre-lista de cheltuieli de tip Lista si ziua in care s-a efectuat cheltuiala-numar intreg >0 si <32
* post-lista modificata in urma stergerii
*/
void delete_repo_expense(Lista* l,int zi);


#endif /*REPO_H*/

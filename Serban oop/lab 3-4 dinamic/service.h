#ifndef SERVICE_H
#define SERVICE_H
#include "domain.h"
#include "repo.h"

typedef struct {
	Lista cheltuieli;
} Expenses;

/*
* functie care creeaza cheltuielile
* pre-
* post-lista de cheltuieli creata
*/
Expenses create_service_expense();

/*
* functie care distruge lista de cheltuieli
* pre-lista de cheltuieli care va fi distrusa
* post-lista de cheltuieli va fi vida
*/
void destroy_expenses(Expenses* expenses);

/*
* functie care adauga o cheltuiala
* pre-lista de cheltuieli de tip Expenses si campurile unei cheltuieli
* post-lista modificata in urma adaugarii cheltuielii
*/
int add_service_expense(Expenses* expenses, int zi,float suma,char* tip);


/*
* functie care preia toate cheltuielile care contin un anumit string
* pre-lista de cheltuieli de tip Expenses si stringul dupa care va fi cautat
* post-elementele listei care indeplinesc aceasta conditie
*/

Lista get_all_expenses(Expenses* expenses, char* substring);

/*
* functie care seteaza/updateaza o cheltuiala din lista de cheltuieli
* pre-lista de cheltuieli de tip Expenses,pozitia cheltuielii pe care o updatam-numar intreg
* nenul si cheltuiala cu care o vom inlocui
* post-modificarea listei
*/
Elemtype set_service_expense(Expenses* l, int poz, Cheltuiala c);

/*
* functie care sterge o cheltuiala
* pre-lista de cheltuieli de tip Lista si ziua in care s-a efectuat cheltuiala-numar intreg >0 si <32
* post-lista modificata in urma stergerii
*/
void delete_service_expense(Expenses* l, int zi);


/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
*/
typedef float(*FunctieComparare)(Cheltuiala* o1, Cheltuiala* o2);
//typedef int(*FunctieComparare1)(Cheltuiala* o1, Cheltuiala* o2);

/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void sort(Lista* l, FunctieComparare cmpF);

void sort1(Lista* l, FunctieComparare cmpF);

/*
* functie care sorteaza lista descrescator in functie de suma
* pre-lista de cheltuieli de tip Expenses
* post-lista de cheltuieli de tip Expenses ordonata
*/
Lista sort_by_sum(Expenses* expense);

Lista sort_by_sum1(Expenses* expense);

/*
* functie de comparare a 2 cheltuieli
* pre-cele 2 cheltuieli
* post-relatia de ordine
*/
float cmpSum(Cheltuiala* p1, Cheltuiala* p2);

#endif /*SERVICE_H*/

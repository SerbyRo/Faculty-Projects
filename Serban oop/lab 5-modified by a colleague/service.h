#ifndef SERVICE_H
#define SERVICE_H
#include "domain.h"
#include "repo.h"

typedef struct {
	Lista* cheltuieli;
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
int add_service_expense(Expenses* expenses, int zi, float suma, char* tip);


/*
* functie care preia toate cheltuielile care contin un anumit string
* pre-lista de cheltuieli de tip Expenses si stringul dupa care va fi cautat
* post-elementele listei care indeplinesc aceasta conditie
*/

Lista* get_all_expenses(Expenses* expenses, char* substring);

/*
* functie care preia toate cheltuielile care contin o suma data
* pre-lista de cheltuieli de tip Expenses si stringul dupa care va fi cautat
* post-elementele listei care indeplinesc aceasta conditie
*/

Lista* get_all_expenses_sum(Expenses* expenses, float suma);

/*
* functie care preia toate cheltuielile care contin cheltuieli dupa o anumita zi
* pre-lista de cheltuieli de tip Expenses si stringul dupa care va fi cautat
* post-elementele listei care indeplinesc aceasta conditie
*/

Lista* get_all_expenses_day(Expenses* expenses, int zi);


/*
* functie care seteaza/updateaza o cheltuiala din lista de cheltuieli
* pre-lista de cheltuieli de tip Expenses,pozitia cheltuielii pe care o updatam-numar intreg
* nenul si cheltuiala cu care o vom inlocui
* post-modificarea listei
*/
Elemtype set_service_expense(Expenses* l, int poz, Cheltuiala* c);

/*
* functie care sterge o cheltuiala
* pre-lista de cheltuieli de tip Lista si ziua in care s-a efectuat cheltuiala-numar intreg >0 si <32
* post-lista modificata in urma stergerii
*/
void delete_service_expense(Expenses* l, int zi);


/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
   returneaza diferenta sumei celor 2 cheltuieli
*/
typedef float(*FunctieComparare)(Cheltuiala* o1, Cheltuiala* o2);
//typedef int(*FunctieComparare1)(Cheltuiala* o1, Cheltuiala* o2);

/*
* Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egael,1 daca o1>o2 si -1 daca o1<o2
*/
typedef int(FunctieComparare1)(Cheltuiala* c1, Cheltuiala* c2);

/*
* functie care sorteaza lista descrescator in functie de suma
* pre-lista de cheltuieli de tip Lista si functia de comparare dupa care se va realiza compararea
* post-lista de cheltuieli de tip Lista ordonata
*/
void sort(Lista* l, FunctieComparare cmpF);

/*
* functie care sorteaza lista crescator in functie de suma
* pre-lista de cheltuieli de tip Lista si functia de comparare dupa care se va realiza compararea
* post-lista de cheltuieli de tip Lista ordonata
*/
void sort1(Lista* l, FunctieComparare cmpF);

/*
* functie care sorteaza lista crescator in functie de suma
* pre-lista de cheltuieli de tip Lista si functia de comparare dupa care se va realiza compararea
* post-lista de cheltuieli de tip Lista ordonata
*/
void sort2(Lista* l, FunctieComparare cmpF);

/*
* functie care sorteaza lista descrescator in functie de tip
* pre-lista de cheltuieli de tip Lista si functia de comparare dupa care se va realiza compararea
* post-lista de cheltuieli de tip Lista ordonata
*/
void sort3(Lista* l, FunctieComparare1 cmpF);

/*
* functie care sorteaza lista crescator in functie de tip
* pre-lista de cheltuieli de tip Expenses
* post-lista de cheltuieli de tip Expenses ordonata
*/
void sort4(Lista* l, FunctieComparare1 cmpF);

/*
* functie care sorteaza lista descrescator in functie de suma
* pre-lista de cheltuieli de tip Expenses
* post-lista de cheltuieli de tip Expenses ordonata
*/
Lista* sort_by_sum(Expenses* expense);

/*
* functie care sorteaza lista crescator in functie de suma
* pre-lista de cheltuieli de tip Expenses
* post-lista de cheltuieli de tip Expenses ordonata
*/
Lista* sort_by_sum1(Expenses* expense);

/*
* functie care sorteaza lista descrescator in functie de tip
* pre-lista de cheltuieli de tip Expenses
* post-lista de cheltuieli de tip Expenses ordonata
*/
Lista* sort_by_sum2(Expenses* expense);


/*
* functie care sorteaza lista crescator in functie de tip
* pre-lista de cheltuieli de tip Expenses
* post-lista de cheltuieli de tip Expenses ordonata
*/
Lista* sort_by_sum3(Expenses* expense);

/*
* functie de comparare a 2 cheltuieli
* pre-cele 2 cheltuieli
* post-relatia de ordine
*/
float cmpSum(Cheltuiala* p1, Cheltuiala* p2);

/*
* functie de comparare a 2 cheltuieli
* pre-cele 2 cheltuieli
* post-relatia de ordine
*/
int cmpTip(Cheltuiala* c1, Cheltuiala* c2);

/*
* CODE ADDED BY HATNEAN CRISTINA
*/
/*
* Functie care filtreaza cheltuielile
* facute inainte de o anumita zi
* input: expense - Expenses, ista de cheltuieli
*        zi - int, ziua inainte de care dorim sa stim ce cheltuieli s-au efectuat
* output: lista filtrata de cheltuieli
*/
Lista* get_all_expenses_zi(Expenses* expense, int zi);


Lista* get_all_expenses_perioada(Expenses* expense, int zi1, int zi2);


#endif /*SERVICE_H*/

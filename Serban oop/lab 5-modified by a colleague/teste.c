#include "teste.h"
#include "domain.h"
#include "repo.h"
#include "service.h"
#include "validare.h"
#include "ui.h"
#include <assert.h>
#include <string.h>
#include <malloc.h>

void run_domain_tests()
{
	//cream o cheltuiala
	Cheltuiala* c = create_expense(20, 900.5, "imbracaminte");
	//verificam egalitatea sumei
	assert(c->suma == 900.5);
	//verificam egalitatea zilei
	assert(c->zi == 20);
	//verificam egalitatea tipului
	assert(strcmp(c->tip, "imbracaminte") == 0);
	Cheltuiala* c1 = create_expense(21, 900.5, "transport");
	//copiem cheltuiala
	Cheltuiala* c2 = copy_expense(c);
	//distrugem cheltuiala c
	destroy_expense(c);
	//assert(c->tip == NULL);
	//assert(c->zi == 0);
	//assert(c->suma == -1);
	//distrugem cheltuiala c1
	destroy_expense(c1);
	//distrugem cheltuiala c2
	destroy_expense(c2);

}

void run_repo_test1() {
	//cream lista vida
	Lista* l = create_list_vid();
	assert(size(l) == 0);
	//distrugem lista
	destroy_list(l, destroy_expense);
}
void run_repo_test2() {
	//cream lista vida
	Lista* l = create_list_vid();
	//adaugam o cheltuiala
	add_expense(l, create_expense(20, 900.5, "imbracaminte"));
	add_expense(l, create_expense(21, 910, "transport"));
	//verificam lungimea listei
	assert(size(l) == 2);
	Cheltuiala* c = get_expense(l, 0);

	assert(strcmp(c->tip, "imbracaminte") == 0);
	//luam cheltuiala de pe pozitia 1
	c = get_expense(l, 1);
	assert(strcmp(c->tip, "transport") == 0);
	//distrugem lista
	destroy_list(l,destroy_expense);
	//assert(size(l) == 0);
}

void run_repo_test3() {
	//cream lista vida
	Lista* l = create_list_vid();
	//adaugam o cheltuiala
	add_expense(l, create_expense(20, 900.5, "imbracaminte"));
	add_expense(l, create_expense(21, 910, "transport"));
	//facem copie listei
	Lista* l2 = copy_list(l);
	assert(size(l2) == 2);
	Cheltuiala* c = get_expense(l2, 0);
	assert(strcmp(c->tip, "imbracaminte") == 0);
	//Elemtype c2 = set_expense(&l, 0, create_expense(22, 850.3, "altele"));
	//assert(strcmp(c2.tip, "altele") == 0);
	//distrugem lista
	destroy_list(l,destroy_expense);
	//distrugem lista l2
	destroy_list(l2,destroy_expense);
}


void run_repo_test4()
{
	//cream lista vida
	Lista* l = create_list_vid();
	//adaugam cheltuieli
	add_expense(l, create_expense(20, 900.5, "imbracaminte"));
	add_expense(l, create_expense(21, 910, "transport"));
	add_expense(l, create_expense(22, 310, "altele"));
	//sort_repo_by_sum(&l);
	//stergem cheltuiala din ziua 21
	delete_repo_expense(l, 21);
	Cheltuiala* c1 = create_expense(22, 850, "altele");
	//modificare cheltuiala
	Cheltuiala* c2 = set_expense(l, 0, c1);
	Cheltuiala* c3 = get_expense(l, 0);
	assert(strcmp(c3->tip, "altele") == 0);
	//distrugem cheltuiala c2
	destroy_expense(c2);
	//distrugem lista
	destroy_list(l,destroy_expense);

}


void run_service_test1() {
	//cream lista din service
	Expenses expense = create_service_expense();
	//adaugam in lista din service
	add_service_expense(&expense, 10, 10.5, "imbracaminte");
	add_service_expense(&expense, 20, 20.5, "transport");
	//lista sortata descrescator
	Lista* sortata = sort_by_sum(&expense);
	destroy_list(sortata,destroy_expense);
	//sort_by_sum1(&expense);
	//filtrare:preluam toate elementele listei
	Lista* filtered = get_all_expenses(&expense, NULL);
	assert(size(filtered) == 2);

	destroy_list(filtered,destroy_expense);
	//filtrare:preluam toate elementele care contin mb
	filtered = get_all_expenses(&expense, "mb");
	assert(size(filtered) == 1);
	destroy_list(filtered,destroy_expense);
	//filtrare:preluam toate elementele care contin tr
	filtered = get_all_expenses(&expense, "tr");
	assert(size(filtered) == 1);
	destroy_list(filtered,destroy_expense);
	//filtrare:preluam toate elementele care contin a
	filtered = get_all_expenses(&expense, "a");
	assert(size(filtered) == 2);
	//stergem din service cheltuiala
	delete_service_expense(&expense, 20);
	//distrugem lista filtered
	destroy_list(filtered, destroy_expense);
	//distrugem lista din service expense
	destroy_expenses(&expense);
}



void run_validate_tests()
{
	Cheltuiala* c = create_expense(33, 90.5, "imbracaminte");
	//verificam validatorul zi invalida
	int err = valideaza_expense(c);
	assert(err != 0);
	Cheltuiala* c1 = create_expense(3, -90.5, "imbracaminte");
	//verificam validatorul suma invalida
	int err1 = valideaza_expense(c1);
	assert(err1 != 0);
	Cheltuiala* c2 = create_expense(3, 90.5, "");
	//verificam validatorul tip vid
	int err2 = valideaza_expense(c2);
	assert(err2 != 0);
	Cheltuiala* c3 = create_expense(3, 90.5, "aaaa");
	//verificam validatorul tip invalid
	int err3 = valideaza_expense(c3);
	assert(err3 != 0);
	//distrugem cheltuiala c
	destroy_expense(c);
	//distrugem cheltuiala c1
	destroy_expense(c1);
	//distrugem cheltuiala c2
	destroy_expense(c2);
	//distrugem cheltuiala c3
	destroy_expense(c3);
}

void run_service_test2() {
	//cream lista din service
	Expenses expense = create_service_expense();
	int err = add_service_expense(&expense, -9, 9, "transport");
	assert(err != 0);
	//distrugem lista din service
	destroy_expenses(&expense);
}

void run_service_test3() {
	//cream lista din service
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 20, 10.5, "imbracaminte");
	add_service_expense(&expense, 10, 20.5, "transport");
	//adaugam o cheltuiala invalida cu aceeasi zi
	add_service_expense(&expense, 10, 30.5, "altele");
	Cheltuiala* c = create_expense(11, 11.5, "mancare");
	//modificam in service
	Elemtype c1 = set_service_expense(&expense, 0, c);
	//distrugem cheltuiala c1
	destroy_expense(c1);
	//distrugem lista din service
	destroy_expenses(&expense);
}

void run_service_test4()
{
	//cream lista din service
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 20, 20.5, "transport");
	add_service_expense(&expense, 10, 10.5, "imbracaminte");
	//sortarea listei crescator
	Lista* sortata = sort_by_sum1(&expense);
	//distrugem lista sortata
	destroy_list(sortata,destroy_expense);
	//distrugem lista din service
	destroy_expenses(&expense);
}

void run_service_test5()
{
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 20, 20.5, "transport");
	add_service_expense(&expense, 10, 10.5, "imbracaminte");
	//sortarea listei crescator in functue de tip
	Lista* sortata = sort_by_sum3(&expense);
	//distrugem lista sortata
	destroy_list(sortata,destroy_expense);
	//filtrarea listei dupa o cheltuiala data,cheltuieli efectuate dupa ziua respectiva
	Lista* filtrata = get_all_expenses_day(&expense, 15);
	//distrugem lista filtrata
	destroy_list(filtrata,destroy_expense);
	//distrugem lista din service
	destroy_expenses(&expense);
}

void run_service_test6()
{
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 20, 20.5, "imbracaminte");
	add_service_expense(&expense, 10, 10.5, "transport");
	//sortarea listei descrescator in functie de tip 
	Lista* sortata = sort_by_sum2(&expense);
	//distrugem lista sortata
	destroy_list(sortata,destroy_expense);
	//filtrare dupa o anumita suma
	Lista* filtrata = get_all_expenses_sum(&expense, 20.5);
	//distrugem lista sortata
	destroy_list(filtrata,destroy_expense);
	//distrugem lista din service
	destroy_expenses(&expense);
}

/*void run_ui_tests()
{
	runAppUI();
}*/

void run_all_tests()
{
	run_domain_tests();
	run_repo_test1();
	run_repo_test2();
	run_repo_test3();
	run_repo_test4();
	run_service_test1();
	run_service_test2();
	run_service_test3();
	run_service_test4();
	run_service_test5();
	run_service_test6();
	run_validate_tests();
	//run_ui_tests();


	/*
     * CODE ADDED BY HATNEAN CRISTINA
    */
	test_get_all_expenses_zi();
	test_lista_de_liste();
	test_get_all_expenses_perioada(); 
}

/*
* CODE ADDED BY HATNEAN CRISTINA
*/

/*
* functie de test pentru filtrul get_all_expenses_zi din service
*/
void test_get_all_expenses_zi()
{
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 10, 10.5, "imbracaminte");
	add_service_expense(&expense, 20, 20.5, "transport");

	Lista* filtru = get_all_expenses_zi(&expense, 15);
	assert(size(filtru) == 1);
	destroy_list(filtru,destroy_expense);

	filtru = get_all_expenses_zi(&expense, 21);
	assert(size(filtru) == 2);
	destroy_list(filtru,destroy_expense);

	filtru = get_all_expenses_zi(&expense, 5);
	assert(size(filtru) == 0);
	destroy_list(filtru,destroy_expense);

	destroy_expenses(&expense);
}

void test_get_all_expenses_perioada()
{
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 10, 10.5, "imbracaminte");
	add_service_expense(&expense, 20, 20.5, "transport");
	add_service_expense(&expense, 15, 20.5, "transport");

	Lista* filtru = get_all_expenses_perioada(&expense, 14, 21);
	assert(size(filtru) == 2);
	destroy_list(filtru, destroy_expense);

	filtru = get_all_expenses_perioada(&expense, 15, 20);
	assert(size(filtru) == 0);
	destroy_list(filtru, destroy_expense);

	filtru = get_all_expenses_perioada(&expense, 1, 9);
	assert(size(filtru) == 0);
	destroy_list(filtru, destroy_expense);

	destroy_expenses(&expense);
}
#include "teste.h"
#include "domain.h"
#include "repo.h"
#include "service.h"
#include "validare.h"
#include "ui.h"
#include <assert.h>
#include <string.h>

void run_domain_tests()
{
	Cheltuiala c = create_expense(20, 900.5, "imbracaminte");
	assert(c.suma == 900.5);
	assert(c.zi == 20);
	assert(strcmp(c.tip, "imbracaminte")==0);
	Cheltuiala c1 = create_expense(21, 900.5, "transport");
	Cheltuiala c2=copy_expense(&c);
	destroy_expense(&c);
	assert(c.tip == NULL);
	assert(c.zi == 0);
	assert(c.suma == -1);
	destroy_expense(&c1);
	destroy_expense(&c2);

	
}

void run_repo_test1() {
	Lista l = create_list_vid();
	assert(size(&l) == 0);
	destroy_list(&l);
}
void run_repo_test2() {
	Lista l = create_list_vid();
	add_expense(&l, create_expense(20,900.5,"imbracaminte"));
	add_expense(&l, create_expense(21,910,"transport"));
	assert(size(&l) == 2);
	Cheltuiala c = get_expense(&l, 0);

	assert(strcmp(c.tip, "imbracaminte") == 0);
	c = get_expense(&l, 1);
	assert(strcmp(c.tip, "transport") == 0);
	destroy_list(&l);
	assert(size(&l) == 0);
}

void run_repo_test3() {
	Lista l = create_list_vid();
	add_expense(&l, create_expense(20, 900.5, "imbracaminte"));
	add_expense(&l, create_expense(21, 910, "transport"));
	Lista l2 = copy_list(&l);
	assert(size(&l2) == 2);
	Cheltuiala c = get_expense(&l2, 0);
	assert(strcmp(c.tip, "imbracaminte") == 0);
	//Elemtype c2 = set_expense(&l, 0, create_expense(22, 850.3, "altele"));
	//assert(strcmp(c2.tip, "altele") == 0);
	destroy_list(&l);
	destroy_list(&l2);
}


void run_repo_test4()
{
	Lista l = create_list_vid();
	add_expense(&l, create_expense(20, 900.5, "imbracaminte"));
	add_expense(&l, create_expense(21, 910, "transport"));
	add_expense(&l, create_expense(22, 310, "altele"));
	//sort_repo_by_sum(&l);
	delete_repo_expense(&l, 21);
	Cheltuiala c1 = create_expense(22, 850, "altele");
	Elemtype c2 = set_expense(&l, 0, c1);
	Elemtype c3 = get_expense(&l, 0);
	assert(strcmp(c3.tip, "altele") == 0);
	destroy_expense(&c2);
	destroy_list(&l);
	
}


void run_service_test1() {
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 10, 10.5, "imbracaminte");
	add_service_expense(&expense, 20, 20.5, "transport");

	Lista sortata = sort_by_sum(&expense);
	destroy_list(&sortata);

	Lista sortata2 = sort_by_sum1(&expense);
	destroy_list(&sortata2);
	Lista filtered = get_all_expenses(&expense, NULL);
	assert(size(&filtered) == 2);
	
	destroy_list(&filtered);

	filtered = get_all_expenses(&expense, "mb");
	assert(size(&filtered) == 1);
	destroy_list(&filtered);

	filtered = get_all_expenses(&expense, "tr");
	assert(size(&filtered) == 1);
	destroy_list(&filtered);

	filtered = get_all_expenses(&expense, "a");
	assert(size(&filtered) == 2);
	delete_service_expense(&expense, 20);
	destroy_list(&filtered);

	destroy_expenses(&expense);
}



void run_validate_tests()
{
	Cheltuiala c = create_expense(33, 90.5, "imbracaminte");
	int err = valideaza_expense(c);
	assert(err != 0);
	Cheltuiala c1 = create_expense(3, -90.5, "imbracaminte");
	int err1 = valideaza_expense(c1);
	assert(err1 != 0);
	Cheltuiala c2 = create_expense(3, 90.5, "");
	int err2 = valideaza_expense(c2);
	assert(err2 != 0);
	Cheltuiala c3 = create_expense(3, 90.5, "aaaa");
	int err3 = valideaza_expense(c3);
	assert(err3 != 0);
	destroy_expense(&c);
	destroy_expense(&c1);
	destroy_expense(&c2);
	destroy_expense(&c3);
}

void run_service_test2() {
	Expenses expense = create_service_expense();
	int err = add_service_expense(&expense, -9, 9, "transport");
	assert(err != 0);
	destroy_expenses(&expense);
}

void run_service_test3() {
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 20, 10.5, "imbracaminte");
	add_service_expense(&expense, 10, 20.5, "transport");
	add_service_expense(&expense, 10, 30.5, "altele");
	Cheltuiala c = create_expense(11, 11.5, "mancare");

	Elemtype c1 = set_service_expense(&expense, 0, c);
	destroy_expense(&c1);
	destroy_expenses(&expense);
}

void run_service_test4()
{
	Expenses expense = create_service_expense();
	add_service_expense(&expense, 20, 10.5, "transport");
	add_service_expense(&expense, 10, 20.5, "imbracaminte");

	Lista sortata = sort_by_sum1(&expense);
	destroy_list(&sortata);
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
	run_validate_tests();
	//run_ui_tests();
}
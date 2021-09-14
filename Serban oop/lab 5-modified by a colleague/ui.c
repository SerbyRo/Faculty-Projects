#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"
#include "repo.h"
#include "domain.h"
#include "ui.h"


void add_ui_expense(Expenses* expense, Lista* undo_list) 
{
	printf("Ziua:");
	int zi;
	scanf_s("%d", &zi);
	printf("Suma:");
	float suma;
	scanf_s("%f", &suma);
	printf("Tip:");
	char tip[20];
	scanf_s("%s", tip, 20);
	add_expense(undo_list, copy_list(expense->cheltuieli));
	int err = add_service_expense(expense, zi, suma, tip);
	if (err != 0) {
		printf("Cheltuiala invalida!\n");
	}
	else {
		printf("Cheltuiala adaugata.\n");
		
	}
}

void print_expense(Lista* l) {
	printf("Cheltuieli:\n");
	for (int i = 0; i < size(l); i++) {
		Cheltuiala* c = get_expense(l, i);
		printf("%d\t %f\t %s\n", c->zi, c->suma, c->tip);
	}
}

void print_expenses(Expenses* expense) {
	Lista* l = get_all_expenses(expense, NULL);
	print_expense(l);
	destroy_list(l,destroy_expense);
}

void filter_ui_by_tip(Expenses* expense)
{
	char tip[20];
	printf("Tipul cheltuielilor dupa care facem filtrarea este:");
	scanf_s("%s", tip, 20);
	Lista* l = get_all_expenses(expense, tip);
	print_expense(l);
	destroy_list(l,destroy_expense);
}

void filter_ui_by_sum(Expenses* expense)
{
	float suma;
	printf("Suma cheltuielilor dupa care facem filtrarea este:");
	scanf_s("%f", &suma);
	Lista* l = get_all_expenses_sum(expense, suma);
	print_expense(l);
	destroy_list(l,destroy_expense);
}

void filter_ui_by_day(Expenses* expense)
{
	int zi;
	printf("Afisam cheltuielile facute dupa ziua:");
	scanf_s("%d", &zi);
	Lista* l = get_all_expenses_day(expense, zi);
	print_expense(l);
	destroy_list(l,destroy_expense);
}

/*
* CODE ADDED BY HATNEAN CRISTINA
*/
/*
* Functie ui care citeste o zi si afiseaza toate cheltuielile efectuate inainte de ziua respectiva
* input: expense - Expenses, lista de cheltuieli din service
*/

void filter_ui_by_zi(Expenses* expense)
{
	int zi;
	printf("Introduceti ziua pentru care doriti filtrul: ");
	scanf_s("%d", &zi);
	Lista* l = get_all_expenses_zi(expense, zi);
	if (size(l) == 0)
	{
		printf("Nu s-au efectuat cheltuieli inainte de ziua %d.\n", zi);
	}
	else
	{
		print_expense(l);
	}
	destroy_list(l, destroy_expense);
}

/*functie care realizeaza undo*/
void undo(Expenses* expense, Lista* undo_list)
{
	if (size(undo_list) == 0)
	{
		printf("Nu se mai poate face undo.\n");
	}
	else
	{
		destroy_list(expense->cheltuieli, destroy_expense);
		expense->cheltuieli = copy_list(undo_list->elems[size(undo_list) - 1]);//obtine lista din undo_list
		print_expense(expense->cheltuieli);
		destroy_list(undo_list->elems[size(undo_list) - 1], destroy_expense);//distruge lista de pe ultima pozitie din undo
		undo_list->lg = undo_list->lg - 1;
	}
}

/*functie care sorteaza cheltuielile dintr-o anumita perioada*/
void sort_perioada(Expenses* expense)
{
	int zi1,zi2;
	printf("Introduceti prima zi pentru care doriti filtrul: ");
	scanf_s("%d", &zi1);
	printf("Introduceti a doua zi pentru care doriti filtrul: ");
	scanf_s("%d", &zi2);
	Lista* l = get_all_expenses_perioada(expense, zi1, zi2);
	if (size(l) == 0)
	{
		printf("Nu s-au efectuat cheltuieli in perioada %d - %d.\n", zi1, zi2);
	}
	else
	{
		print_expense(l);
	}
	destroy_list(l, destroy_expense);
}

/*
* END OF CODE ADDED BY HATNEAN CRISTINA
*/

void set_ui_expense(Expenses* expense, Lista* undo_list)
{
	add_expense(undo_list, copy_list(expense->cheltuieli));
	int poz;
	printf("Vom updata cheltuiala cu numarul:");
	scanf_s("%d", &poz);
	int zi;
	printf("Ziua:");
	scanf_s("%d", &zi);
	float suma;
	printf("Suma:");
	scanf_s("%f", &suma);
	char tip[20];
	printf("Tip:");
	scanf_s("%s", tip, 20);
	Cheltuiala* c = create_expense(zi, suma, tip);
	Elemtype c1 = set_service_expense(expense, poz - 1, c);
	//add_expense(undo_list, copy_list(expense->cheltuieli));
	destroy_expense(c1);
}

void delete_ui_expense(Expenses* expense, Lista* undo_list)
{
	add_expense(undo_list, copy_list(expense->cheltuieli));
	int zi;
	printf("Vom sterge cheltuiala efectuata in ziua:");
	scanf_s("%d", &zi);
	delete_service_expense(expense, zi);
}

void sort_ui_expense(Expenses* expense) {
	Lista* l = sort_by_sum(expense);
	print_expense(l);
	destroy_list(l,destroy_expense);
}

void sort_ui_expense1(Expenses* expense) {
	Lista* l = sort_by_sum1(expense);
	print_expense(l);
	destroy_list(l, destroy_expense);
}

void sort_ui_expense2(Expenses* expense) {
	Lista* l = sort_by_sum2(expense);
	print_expense(l);
	destroy_list(l,destroy_expense);
}

void sort_ui_expense3(Expenses* expense) {
	Lista* l = sort_by_sum3(expense);
	print_expense(l);
	destroy_list(l,destroy_expense);
}


void runAppUI()
{
	Expenses expense = create_service_expense();
	Lista* undo_list = create_list_vid(); ////////////
	int rez = 1;
	while (rez)
	{
		printf("MENU\n");
		printf("0-exit\n");
		printf("1-afiseaza cheltuieli\n");
		printf("2-adauga cheltuiala\n");
		printf("3-sterge cheltuiala\n");
		printf("4-modifica cheltuiala\n");
		printf("5-filtrare dupa tip\n");
		printf("6-sortare descrescator in functie de suma\n");
		printf("7-sortare crescator in functie de suma\n");
		printf("8-sortare descrescator in functie de tip\n");
		printf("9-sortare descrescator in functie de tip\n");
		printf("10-filtrare dupa suma\n");
		printf("11-filtrare dupa zi\n");

		printf("12 - filtrare dupa zi, cheltuieli efectuate inaintea unei zile date\n");
		printf("13 - Undo\n");
		printf("14 - cheltuieli din perioada precizata, sortate crescator dupa tip\n");

		int cmd;
		printf("Comanda este:");
		scanf_s("%d", &cmd);
		if (cmd == 0)
		{
			rez = 0;
			break;
		}
		else if (cmd == 2)
		{
			add_ui_expense(&expense, undo_list);
		}
		else if (cmd == 1)
		{
			print_expenses(&expense);
		}
		else if (cmd == 5)
		{
			filter_ui_by_tip(&expense);
		}
		else if (cmd == 4)
		{
			set_ui_expense(&expense,undo_list);
		}
		else if (cmd == 3)
		{
			delete_ui_expense(&expense,undo_list);
		}
		else if (cmd == 6)
		{
			sort_ui_expense(&expense);
		}
		else if (cmd == 7)
		{
			sort_ui_expense1(&expense);
		}
		else if (cmd == 8)
		{
			sort_ui_expense2(&expense);
		}
		else if (cmd == 9)
		{
			sort_ui_expense3(&expense);
		}
		else if (cmd == 10)
		{
			filter_ui_by_sum(&expense);
		}
		else if (cmd == 11)
		{
			filter_ui_by_day(&expense);
		}
		else if (cmd == 12)
		{
			filter_ui_by_zi(&expense);
		}
		else if (cmd == 13)
		{
			undo(&expense, undo_list);
		}
		else if (cmd == 14)
		{
			sort_perioada(&expense);
		}
	}
	destroy_expenses(&expense);
	destroy_list(undo_list, destroy_lista_cheltuieli);
}



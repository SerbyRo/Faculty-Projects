#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"
#include "repo.h"
#include "domain.h"
#include "ui.h"


void add_ui_expense(Expenses* expense) {
	printf("Ziua:");
	int zi;
	scanf_s("%d",&zi);
	printf("Suma:");
	float suma;
	scanf_s("%f", &suma);
	printf("Tip:");
	char tip[20];
	scanf_s("%s", tip,20);
	int err = add_service_expense(expense,zi,suma,tip);
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
		Cheltuiala c = get_expense(l, i);
		printf("%d\t %f\t %s\n", c.zi,c.suma,c.tip);
	}
}

void print_expenses(Expenses* expense) {
	Lista l = get_all_expenses(expense, NULL);
	print_expense(&l);
	destroy_list(&l);
}

void filter_ui_by_tip(Expenses* expense)
{
	char tip[20];
	printf("Tipul cheltuielilor dupa care facem filtrarea este:");
	scanf_s("%s", tip, 20);
	Lista l = get_all_expenses(expense, tip);
	print_expense(&l);
	destroy_list(&l);
}


void set_ui_expense(Expenses* expense)
{
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
	Cheltuiala c = create_expense(zi, suma, tip);
	Elemtype c1 = set_service_expense(expense, poz - 1, c);
	destroy_expense(&c1);
}

void delete_ui_expense(Expenses* expense)
{
	int zi;
	printf("Vom sterge cheltuiala efectuata in ziua:");
	scanf_s("%d", &zi);
	delete_service_expense(expense, zi);
}

void sort_ui_expense(Expenses* expense ) {
	Lista l = sort_by_sum(expense);
	print_expense(&l);
	destroy_list(&l);
}

void sort_ui_expense1(Expenses* expense) {
	Lista l = sort_by_sum1(expense);
	print_expense(&l);
	destroy_list(&l);
}

void runAppUI()
{
	Expenses expense = create_service_expense();
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
			   add_ui_expense(&expense);
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
			set_ui_expense(&expense);
		}
		else if (cmd == 3)
		{
			delete_ui_expense(&expense);
		}
		else if (cmd == 6)
		{
			sort_ui_expense(&expense);
		}
		else if (cmd == 7)
		{
			sort_ui_expense1(&expense);
		}
	}
	destroy_expenses(&expense);
}



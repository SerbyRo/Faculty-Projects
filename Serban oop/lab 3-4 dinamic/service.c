#include "service.h"
#include "validare.h"
#include <string.h>
#include <stdio.h>
int add_service_expense(Expenses* expenses, int zi,float suma,char* tip) {
	Cheltuiala c = create_expense(zi,suma,tip);
	for (int i = 0;i < expenses->cheltuieli.lg;i++)
	{
		if (expenses->cheltuieli.elems[i].zi == c.zi)
		{
			printf("Zi existenta!\n");
			destroy_expense(&c);
			return 1;
		}
	}
	printf("%d\t %f\t %s\n", zi, suma, tip);
	int err = valideaza_expense(c);
	if (err != 0) {
		destroy_expense(&c);
		return err;
	}
	add_expense(&expenses->cheltuieli,c);
	return 0; 
}

Expenses create_service_expense()
{
	Expenses rez;
	rez.cheltuieli = create_list_vid();
	return rez;
}

void destroy_expenses(Expenses* expenses)
{ 
	destroy_list(&expenses->cheltuieli);
}

Lista get_all_expenses(Expenses* expense, char* substring) {
	if (substring == NULL || strlen(substring) == 0) {
		return copy_list(&expense->cheltuieli);
	}
	Lista rez = create_list_vid();
	for (int i = 0; i < size(&expense->cheltuieli); i++) {
		Cheltuiala c = get_expense(&expense->cheltuieli, i);
		if (strstr(c.tip, substring) != NULL) {
			add_expense(&rez, copy_expense(&c));
		}
	}
	return rez;
}



Elemtype set_service_expense(Expenses* l, int poz, Cheltuiala c)
{
	return set_expense(&l->cheltuieli, poz, c);
}
void delete_service_expense(Expenses* expense, int zi)
{
	delete_repo_expense(&expense->cheltuieli, zi);
}

float cmpSum(Cheltuiala* c1, Cheltuiala* c2) {
	return c2->suma - c1->suma;
}

void sort(Lista* l, FunctieComparare cmpF) {
	int i, j;
	for (i = 0; i < size(l)-1; i++) {
		for (j = i + 1; j < size(l); j++) {
			Cheltuiala c1 = get_expense(l, i);
			Cheltuiala c2 = get_expense(l, j);
			if (cmpF(&c1, &c2) > 0) {
				set_expense(l, i, c2);
				set_expense(l, j, c1);
			}
		}
	}
}


void sort1(Lista* l, FunctieComparare cmpF) {
	int i, j;
	for (i = 0; i < size(l) - 1; i++) {
		for (j = i + 1; j < size(l); j++) {
			Cheltuiala c1 = get_expense(l, i);
			Cheltuiala c2 = get_expense(l, j);
			if (cmpF(&c1, &c2) < 0) {
				set_expense(l, i, c2);
				set_expense(l, j, c1);
			}
		}
	}
}


Lista sort_by_sum(Expenses* expense) {
	Lista l = copy_list(&expense->cheltuieli);
	sort(&l, cmpSum);
	return l;
}

Lista sort_by_sum1(Expenses* expense) {
	Lista l = copy_list(&expense->cheltuieli);
	sort1(&l, cmpSum);
	return l;
}


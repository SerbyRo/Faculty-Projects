#include "repo.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
Lista* create_list_vid() {
	Lista* l = malloc(sizeof(Lista));
	l->lg = 0;
	l->cap = 2;
	l->elems = malloc(sizeof(Elemtype) * l->cap);
	return l;
}

void destroy_list(Lista* l, DestroyFunction destrF) {
	for (int i = 0; i < l->lg; i++) {
		destrF(l->elems[i]);
	}
	free(l->elems);
	//l->elems = NULL;
	//l->lg = 0;
	free(l);
}

Elemtype get_expense(Lista* l, int poz) {
	return l->elems[poz];
}

Elemtype set_expense(Lista* l, int poz, Cheltuiala* c) {
	Elemtype* c1 = l->elems[poz];
	l->elems[poz] = c;
	return c1;
}

int size(Lista* l) {
	return l->lg;
}

void ensureCapacity(Lista* l) {
	if (l->lg < l->cap) {
		return;
	}
	int newCapacity = l->cap + 2;
	Elemtype* nElems = malloc(sizeof(Elemtype) * newCapacity);
	for (int i = 0; i < l->lg; i++) {
		nElems[i] = l->elems[i];
	}
	free(l->elems);
	l->elems = nElems;
	l->cap = newCapacity;
}
void add_expense(Lista* l, Elemtype el) {
	ensureCapacity(l);
	l->elems[l->lg] = el;
	l->lg++;
}

Lista* copy_list(Lista* l) {
	Lista* rez = create_list_vid();
	for (int i = 0; i < size(l); i++) {
		Elemtype c = get_expense(l, i);
		add_expense(rez, copy_expense(c));
	}
	return rez;
}

/*void sort_repo_by_sum(Lista* l)
{
	for (int i = 0;i < l->lg;i++)
	{
		for (int j = i + 1;j < l->lg-1;j++)
		{
			if (l->elems[i].suma< l->elems[j].suma)
			{
				float aux;
				aux = l->elems[i].suma;
				l->elems[i].suma = l->elems[j].suma;
				l->elems[j].suma = aux;
			}
		}
	}
}*/

void delete_repo_expense(Lista* l, int zi)
{
	printf("%d", l->lg);
	for (int i = 0; i < l->lg; i++)
	{
		Cheltuiala* c = get_expense(l, i);
		printf("%d\t %d", c->zi, i);
		if (c->zi == zi)
		{
			destroy_expense(c);
			for (int j = i; j < l->lg - 1; j++)
			{
				l->elems[j] = l->elems[j + 1];
			}
			l->lg = l->lg - 1;
			i--;
		}
	}
}

/*
* CODE ADDED BY HATNEAN CRISTINA
*/
/*
* Functie care testeaza operatiile pentru o lista undo
*/
void test_lista_de_liste()
{
	Lista* cheltuieli = create_list_vid();
	add_expense(cheltuieli, create_expense(15, 250, "mancare"));
	add_expense(cheltuieli, create_expense(16, 206, "mancare"));

	Lista* cheltuieli2 = create_list_vid();
	Lista* undo_list = create_list_vid();
	add_expense(undo_list, cheltuieli);
	assert(size(undo_list) == 1);
	add_expense(undo_list, cheltuieli2);
	assert(size(undo_list) == 2);

	destroy_list(undo_list,destroy_lista_cheltuieli);
}

/*
* Functie care distruge o lista de cheltuieli
*/
void destroy_lista_cheltuieli(Lista* l)
{
	destroy_list(l, destroy_expense);
}

#include "domain.h"
#include <string.h>
#include <stdlib.h>

Cheltuiala* create_expense(int zi, float suma, char* tip) {
	Cheltuiala* c = malloc(sizeof(Cheltuiala));
	size_t nrC = strlen(tip) + 1;
	c->tip = malloc(sizeof(char) * nrC);
	strcpy_s(c->tip, nrC, tip);
	c->suma = suma;
	c->zi = zi;
	return c;
}


void destroy_expense(Cheltuiala* c) {
	free(c->tip);
	free(c);
	//c->tip = NULL;
	//c->zi = 0;
	//c->suma = -1;
}

Cheltuiala* copy_expense(Cheltuiala* c) {
	return create_expense(c->zi, c->suma, c->tip);
}

/*
* CODE ADDED BY HATNEAN CRISTINA
*/
/*
* Functie getter pentru zi
* input: c - Cheltuiala*, cheltuiala pentru care vrem sa aflam ziua
* output: int, ziua in care s-a efectuau cheltuiala
*/
int get_zi(Cheltuiala* c)
{
	return c->zi;
}
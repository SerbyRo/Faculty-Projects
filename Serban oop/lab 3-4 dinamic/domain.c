#include "domain.h"
#include <string.h>
#include <stdlib.h>

Cheltuiala create_expense(int zi,float suma,char *tip) {
	Cheltuiala c;
	size_t nrC = strlen(tip) + 1;
	c.tip = malloc(sizeof(char) * nrC);
	strcpy_s(c.tip, nrC, tip);
	c.suma = suma;
	c.zi = zi;
	return c;
}


void destroy_expense(Cheltuiala* c) {
	free(c->tip);
	c->tip = NULL;
	c->zi = 0;
	c->suma = -1;
}

Cheltuiala copy_expense(Cheltuiala* c) {
	return create_expense(c->zi,c->suma,c->tip);
}
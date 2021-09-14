#include "validare.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
int valideaza_expense(Cheltuiala* c)
{
	if (c->zi < 1 || c->zi > 31)
	{
		printf("zi invalida!\n");
		return 1;
	}
	if (c->suma <= 0)
	{
		printf("suma invalida!\n");
		return 1;
	}
	if (strlen(c->tip) == 0)
	{
		printf("tip invalid!\n");
		return 1;
	}
	if (strcmp(c->tip, "imbracaminte") != 0 && strcmp(c->tip, "telefon&internet") != 0 && strcmp(c->tip, "transport") != 0 && strcmp(c->tip, "altele") != 0 && strcmp(c->tip, "mancare") != 0)
	{
		printf("tip invalid!\n");
		return 1;
	}
	return 0;
}

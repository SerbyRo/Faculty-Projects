#ifndef VALIDARE_H
#define VALIDARE_H
#include "domain.h"

/*
* functie de validare a unei cheltuieli
* pre-cheltuiala de tip Cheltuiala
*     zi-numar natural intreg >0 si <32
*     suma-numar natural nenul
*	  ti=un string nevid si care apartine multimii date in problema
* post- 0,daca cheltuiala este valida
*       1,in caz contrar
*/
int valideaza_expense(Cheltuiala c);

#endif /*VALIDARE_H*/

#ifndef DOMAIN_H
#define DOMAIN_H

typedef struct {
	char* tip;
	int zi;
	float suma;
} Cheltuiala;

/*
* functie care creeaza o cheltuiala
* pre-atributele unei cheltuieli
*     zi- un numar natural >0 si <32
*     suma -un numar real pozitiv
*     tip-un string nevid
* post-cheltuiala creata
*/
Cheltuiala* create_expense(int zi, float suma, char* tip);

/*
* functie care distruge o cheltuiala
* pre-cheltuiala care va fi distrusa
* post-dealocarea memoriei
*      tipul devine NULL
*      suma devine -1
*      ziua devine 0
*/
void destroy_expense(Cheltuiala* c);

/*
* functie care copiaza o cheltuiala
* pre-cheltuiala care va fi copiata
* post-copia cheltuielii
*/
Cheltuiala* copy_expense(Cheltuiala* c);

/*
* CODE ADDED BY HATNEAN CRISTINA
*/
/*
* Functie getter pentru zi
* input: c - Cheltuiala*, cheltuiala pentru care vrem sa aflam ziua
* output: int, ziua in care s-a efectuau cheltuiala
*/
int get_zi(Cheltuiala* c);

#endif /*DOMAIN_H*/

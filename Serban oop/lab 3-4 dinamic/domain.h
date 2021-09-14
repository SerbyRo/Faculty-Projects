#ifndef DOMAIN_H
#define DOMAIN_H

typedef struct {
	char* tip;
	int zi;
	float suma;
} Cheltuiala;


Cheltuiala create_expense(int zi,float suma,char *tip);


void destroy_expense(Cheltuiala* c);


Cheltuiala copy_expense(Cheltuiala* c);



#endif /*DOMAIN_H*/

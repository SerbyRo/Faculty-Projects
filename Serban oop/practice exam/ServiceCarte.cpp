#include "ServiceCarte.h"


void ServiceCarte::addService(int id, string titlu, string tip, double pret)
{
	Carte car{ id,titlu,tip,pret };
	val.valideazaCarte(car);
	repocarti.addRepo(car);
}

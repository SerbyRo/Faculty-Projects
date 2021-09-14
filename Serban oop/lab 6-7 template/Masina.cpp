#include "Masina.h"


bool cmpnrinmatriculare(const Masina& mas1, const Masina& mas2)
{
	return mas1.getnrinmatriculare() < mas2.getnrinmatriculare();
}

bool cmptip(const Masina& mas1, const Masina& mas2)
{
	return mas1.gettip() < mas2.gettip();
}

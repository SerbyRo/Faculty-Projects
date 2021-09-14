#pragma once
#include "Masina.h"
#include "RepoMasina.h"
#include "ServiceMasina.h"
class UiMasina
{
private:
	ServiceMasina& servmasini;
	/*
	Citeste datele de la tastatura si adauga masina
	arunca exceptie daca: nu se poate salva, nu e valid
	*/
	void adaugaUI();
	/*
	Tipareste o lista de animale la consola
	*/
	void tipareste(const vector<Masina>& masini);
public:
	UiMasina(ServiceMasina& servmasini) :servmasini{ servmasini } {

	}
	//nu permitem copierea obiectelor
	UiMasina(const UiMasina& ot) = delete;

	void runApp();
};


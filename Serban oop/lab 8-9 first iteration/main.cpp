#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>
#include <iostream>
#include "teste.h"
#include "Masina.h"
#include "RepoMasina.h"
#include "ServiceMasina.h"
#include "UiMasina.h"
#include "Validatori.h"
//#include "VectorTemplate.h"

using std::cout;

void adaugahardcodate(ServiceMasina& servmasini) {
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "passat");
	servmasini.addMasina("bv20lasd", "Opel", "benzina", "Astra");
	servmasini.addMasina("bv09iuj", "Ford", "diesel", "Fiesta");
	servmasini.addMasina("bv43aew", "Wolkswagen", "benzina", "golf");
	servmasini.addMasina("bv90rer", "Nissan", "qashqai", "golf");
	servmasini.addMasina("bv12fuo", "Audi", "electric", "A5");
}

int main()
{
	{
		run_all_tests();
		RepoMasina repomasini;
		ValidateMasina val;
		ManageMasini workmasini;
		ServiceMasina servmasini{ repomasini,val ,workmasini};
		adaugahardcodate(servmasini);
		UiMasina ui{ servmasini };
		ui.runApp();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
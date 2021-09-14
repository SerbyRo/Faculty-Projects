#include "teste.h"
#include "Masina.h"
#include "Validatori.h"
#include "RepoMasina.h"
#include "ServiceMasina.h"
#include <assert.h>
#include <sstream>

using std::stringstream;

void run_constructor_test()
{
	Masina mas{ "bv08lin","Wolkswagen","diesel","B8" };
	assert(mas.getnrinmatriculare() == "bv08lin");
	assert(mas.getproducator() == "Wolkswagen");
	assert(mas.gettip() == "diesel");
	assert(mas.getmodel() == "B8");
	Masina mas1{ "bv20aes","Wolkswagen","benzina","passat" };
	assert(cmpnrinmatriculare(mas, mas1) == true);
	assert(cmptip(mas, mas1) == false);
}

void run_validator_test()
{
	ValidateMasina val;
	Masina mas{ "","","",""};
	try
	{
		val.valideazamasina(mas);
	}
	catch (const ValidateException& ex)
	{
		std::stringstream sout;
		sout << ex;
		auto const mesaj = sout.str();
		assert(mesaj.find("invalid") >= 0);
	}
	
}

void run_repoadauga_test()
{
	RepoMasina masini;
	masini.store(Masina{ "bv08lin","Wolkswagen","diesel","B8" });
	assert(masini.getAll().size() == 1);
	assert(masini.find("bv08lin").getnrinmatriculare() == "bv08lin");
	masini.store(Masina{ "bv20asd","Ford","benzina","fiesta" });
	assert(masini.getAll().size() == 2);
	try
	{
		masini.store(Masina{ "bv08lin","Opel","benzina","Astra" });
		//assert(false);
	}
	catch (const RepoException&)
	{
		assert(true);
	}
	try
	{
		masini.find("sj33qwe");
		//assert(false);
	}
	catch (const RepoException& ex)
	{
		stringstream out;
		out << ex;
		assert(out.str().find("exista") > 0);
	}
}

void run_repocauta_test()
{
	RepoMasina masini;
	masini.store(Masina{ "bv08lin","Wolkswagen","diesel","C7" });
	masini.store(Masina{ "bv20asd","Opel","benzina","Astra" });
	auto mas = masini.find("bv08lin");
	assert(mas.getnrinmatriculare() == "bv08lin");
	try
	{
		masini.find("bv32iof");
		//assert(false);
	}
	catch (const RepoException&)
	{
		assert(true);
	}
}

void run_serviceadauga_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ServiceMasina servmasini{ repomasini,val };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "B8");
	assert(servmasini.getAll().size() == 1);
	try {
		servmasini.addMasina("", "", "", "");
		//assert(false);
	}
	catch (const ValidateException&)
	{
		assert(true);
	}
	/*try {
		servmasini.addMasina("bv08lin", "Ford", "benzina", "C3");
		assert(false);
	}
	catch (const ValidateException&)
	{
		assert(true);
	}*/
}

void run_servicefiltrare_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ServiceMasina servmasini{ repomasini,val };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "B8");
	servmasini.addMasina("bv20lasd", "Opel", "benzina", "Astra");
	servmasini.addMasina("bv09iuj", "Ford", "diesel", "Fiesta");
	assert(servmasini.filterbyproducator("Wolkswagen").size() == 1);
	assert(servmasini.filterbytip("diesel").size() == 2);
}

void run_servicesortare_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ServiceMasina servmasini{ repomasini,val };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "passat");
	servmasini.addMasina("bv20lasd", "Opel", "benzina", "Astra");
	servmasini.addMasina("bv09iuj", "Ford", "diesel", "Fiesta");
	servmasini.addMasina("bv43aew", "Wolkswagen", "benzina", "golf");
	auto mas = servmasini.sortbynrinmatriculare()[0];
	assert(mas.getnrinmatriculare() == "bv08lin");
	auto mas1 = servmasini.sortbytip()[0];
	assert(mas1.gettip() == "benzina");
	auto mas2 = servmasini.sortbyproducatormodel()[2];
	assert(mas2.getmodel() == "golf");

}

void run_all_tests() {
	run_constructor_test();
	run_validator_test();
	run_repoadauga_test();
	run_repocauta_test();
	run_serviceadauga_test();
	run_servicefiltrare_test();
	run_servicesortare_test();
}
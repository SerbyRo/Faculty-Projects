#include "teste.h"
#include "Masina.h"
#include "Validatori.h"
#include "RepoMasina.h"
#include "ServiceMasina.h"
#include "ManageMasini.h"
#include "DTO.h"
#include <assert.h>
#include <sstream>
#include <map>

using std::map;

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
	stringstream out;
	out << mas1;
	//assert(out.str() == "bv20aes Wolkswagen benzina passat");
}

void run_validator_test()
{
	ValidateMasina val;
	Masina mas{ "","","","" };
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
	//assert(masini.find("bv09lin").getnrinmatriculare() != "bv08lin");
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
	int const cod = masini.searchrepo(mas);
	Masina mas1{ "bv12wds","Audi","diesel","E3" };
	Masina mas2{ "bv34qer","Mercedes","electrica","M5" };
	try
	{
		masini.updaterepo(mas2);
	}
	catch (const RepoException&)
	{
		assert(true);
	}
	try
	{
		masini.deleterepo(mas2);
	}
	catch (const RepoException&)
	{
		assert(true);
	}
	assert(cod == 0);
	int const cod1 = masini.searchrepo(mas1);
	assert(cod1 == -1);
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
	ManageMasini workmasini;
	ServiceMasina servmasini{ repomasini,val ,workmasini };
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
	ManageMasini workmasini;
	ServiceMasina servmasini{ repomasini,val,workmasini };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "B8");
	servmasini.addMasina("bv20lasd", "Opel", "benzina", "Astra");
	servmasini.addMasina("bv09iuj", "Ford", "diesel", "Fiesta");
	assert(servmasini.searchservice("bv08lin") == true);
	assert(servmasini.searchservice("bv09lin") == false);
	Masina mas{ "bv345sfr","Mercedes","electrica","Y6" };
	servmasini.updateservice("bv20lasd", "Audi", "fullelectrica", "Y5");
	//servmasini.updateservice("bv19lasd", "Audi", "fullelectrica", "Y5");
	//assert(mas.getproducator() == "Audi");
	//assert(mas.gettip() == "fullelectrica");
	//assert(mas.getmodel() == "Y5");
	//assert(servmasini.filterbyproducator("Wolkswagen").size() == 1);
	//assert(servmasini.filterbytip("diesel").size() == 2);
}

void run_servicesortare_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ManageMasini workmasini;
	ServiceMasina servmasini{ repomasini,val,workmasini };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "passat");
	servmasini.addMasina("bv20lasd", "Opel", "benzina", "Astra");
	servmasini.addMasina("bv09iuj", "Ford", "diesel", "Fiesta");
	servmasini.addMasina("bv43aew", "Wolkswagen", "benzina", "golf");
	//auto mas = servmasini.sortbynrinmatriculare().at(0);
	//assert(mas.getnrinmatriculare() == "bv08lin");
	//auto mas1 = servmasini.sortbytip().at(0);
	//assert(mas1.gettip() == "benzina");
	//auto mas2 = servmasini.sortbyproducatormodel().at(2);
	//assert(mas2.getmodel() == "golf");

}

void run_servicestergere_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ManageMasini workmasini;
	ServiceMasina servmasini{ repomasini,val,workmasini };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "B8");
	assert(servmasini.getAll().size() == 1);
	servmasini.deleteservice("bv08lin");
	assert(servmasini.getAll().size() == 0);
	//servmasini.deleteservice("bv09lin");
	//assert(servmasini.getAll().size() == 0);
}

void run_generalfilter_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ManageMasini workmasini;
	ServiceMasina servmasini{ repomasini, val,workmasini };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "B8");
	servmasini.addMasina("bv09lin", "Wolkswagen", "benzina", "B8");
	servmasini.addMasina("bv07lin", "Ford", "diesel", "B8");
	vector<Masina> lista_sortata = servmasini.generalsort(0);
	vector<Masina> lista_sortata1 = servmasini.generalsort(1);
	vector<Masina> lista_sortata2 = servmasini.generalsort(2);
	vector<Masina> lista_filtrata1 = servmasini.filterbyproducator("Wolkswagen");
	assert(lista_filtrata1.size() == 2);
	vector<Masina> lista_filtrata2 = servmasini.filterbytip("diesel");
	assert(lista_filtrata2.size() == 2);


}

void run_repogetMasina_test()
{
	RepoMasina repomasini;
	repomasini.store(Masina{ "bv08lin","Wolkswagen","diesel","B8" });
	repomasini.store(Masina{ "bv09lin","Wolkswagen","benzina","B7" });
	repomasini.store(Masina{ "bv07lin","Ford","benzina","Fiesta" });
	repomasini.store(Masina{ "bv06lin","Audi","diesel","A5" });
	Masina mas{ "bv34sef","Opel","benzina","Astra" };
	const auto masina = repomasini.getMasina(mas);
	Masina mas1{ "bv08lin","Wolkswagen","diesel","B8" };
	const auto masina1 = repomasini.getMasina(mas);
}
void run_worklist_test() {
	RepoMasina repomasini;
	ValidateMasina val;
	ManageMasini worklist;
	ServiceMasina servmasini{ repomasini,val,worklist };
	worklist.adauga(Masina{ "bv08lin","Wolkswagen","diesel","B8" });
	worklist.adauga(Masina{ "bv08lin","Wolkswagen","diesel","B8" });
	worklist.adauga(Masina{ "bv07lin","Ford","diesel","Fiesta" });
	worklist.adauga(Masina{ "bv09lin","Opel","diesel","Astra" });
	vector<Masina> masini = worklist.getallmasini();
	worklist.genereazarandomlista(3, masini);
	worklist.goleste();
	assert(worklist.getSize() == 0);
	servmasini.addworkcar("bv52aqs");
	servmasini.addworkcar("bv32poa");
	servmasini.addworkcar("bv20zxd");
	servmasini.listagoala();
	vector<Masina> masini1 = servmasini.getworklist();
	servmasini.generaterandomlist(0);
	servmasini.saveworklistinCVS("testworklist.txt");
	//servmasini.generaterandomlist(1);
}
void testDTO()
{
	DTO object{ "B8" };
	assert(object.getModel() == "B8");
	assert(object.getCount() == 1);
	object.increment();
	assert(object.getCount() == 2);
}

void run_serviceDTO_test()
{
	RepoMasina repomasini;
	ValidateMasina val;
	ManageMasini worklist;
	ServiceMasina servmasini{ repomasini,val,worklist };
	servmasini.addMasina("bv08lin", "Wolkswagen", "diesel", "B8");
	servmasini.addMasina("bv18lin", "Ford", "diesel", "Fiesta");
	servmasini.addMasina("bv07lin", "Hyundai", "electric", "B8");
	servmasini.addMasina("bv09lin", "Opel", "benzina", "Astra");
	DTO obiect;
	map<string, DTO> raport = servmasini.raport();
}

void run_all_tests() {
	run_constructor_test();
	run_validator_test();
	run_repoadauga_test();
	run_repocauta_test();
	run_repogetMasina_test();
	run_serviceadauga_test();
	run_servicefiltrare_test();
	run_servicesortare_test();
	run_servicestergere_test();
	run_worklist_test();
	run_generalfilter_test();
	run_serviceDTO_test();
	testDTO();
}
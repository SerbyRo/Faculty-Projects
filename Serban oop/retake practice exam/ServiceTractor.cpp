#include "ServiceTractor.h"
#include <algorithm>
void ServiceTractor::addService(int id,string descriere,string tip,int nrroti)
{
	Tractor trac{ id,descriere,tip,nrroti };
	val.valideazatractor(trac);
	filerepo.addRepo(trac);
}

vector<Tractor> ServiceTractor::sortbydenumire()
{
	vector<Tractor> lista = this->getAllService();
	sort(lista.begin(), lista.end(), [&](const Tractor& t1, const Tractor& t2) {
		return t1.getdenumire() < t2.getdenumire();
		});
	return lista;
}

vector<Tractor> ServiceTractor::filterbytip(string tip)
{
	vector<Tractor> lista = this->getAllService();
	vector<Tractor> listafiltrata;
	for (auto trac : lista)
	{
		if (trac.gettip() == tip)
		{
			listafiltrata.push_back(trac);
		}
	}
	return listafiltrata;
}

vector<string> ServiceTractor::nrtipuri()
{
	vector<string> tipuri;
	for (auto trac : this->getAllService())
	{
		int ok=1;
		for (auto tip : tipuri)
		{
			if (tip == trac.gettip())
			{
				ok = 0;
				break;
			}
		}
		if (ok == 1)
		{
			tipuri.push_back(trac.gettip());
		}
	}
	return tipuri;
}

#include "ServiceArticol.h"
#include "Articol.h"
#include <algorithm>
Articol ServiceArticol::findart(string nume)
{
	for (auto art : filerepo.getAllRepo())
	{
		if (art.getnume() == nume)
		{
			return art;
		}
	}
	return Articol{ "none","none",1,1 };
}

void ServiceArticol::addService(const Articol& art)
{
	filerepo.addrepo(art);
}

vector<Articol> ServiceArticol::filternume(string nume)
{
	vector<Articol> lista;
	for (auto art : filerepo.getAllRepo())
	{
		if (art.getnume() == nume)
		{
			lista.push_back(art);
		}
	}
	return lista;
}

vector<Articol> ServiceArticol::filtermarime(int marime)
{
	vector<Articol> lista;
	for (auto art : filerepo.getAllRepo())
	{
		if (art.getmarime() == marime)
		{
			lista.push_back(art);
		}
	}
	return lista;
}

void ServiceArticol::stergeService(int stoc)
{
	
	vector<Articol> articole = filerepo.getAllRepo();
	int n = rand() % ((int)articole.size());
	//std::shuffle(articole.begin(),articole.end(),
	for (unsigned int i = 0;i < n&& i<articole.size();i++)
	{
		if (stoc == articole.at(i).getstoc())
		{
			stoc = 0;
		}
	}
}

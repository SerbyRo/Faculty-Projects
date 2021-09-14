#include "RepoMasina.h"
#include "Masina.h"
#include <iostream>
#include <sstream>

using std::ostream;
using std::stringstream;

void RepoMasina::store(const Masina& mas)
{
	if (exist(mas))
	{
		throw RepoException("Exista o masina cu numarul de inmatriculare:" + mas.getnrinmatriculare());
	}
	repomasini.push_back(mas);
}

bool RepoMasina::exist(const Masina& mas)
{
	try
	{
		find(mas.getnrinmatriculare());
		return true;
	}
	catch (const RepoException&)
	{
		return false;
	}
}
const Masina& RepoMasina::find(string nrinmatriculare) const {
	
	for (const auto& mas : repomasini)
	{
		if (mas.getnrinmatriculare() == nrinmatriculare)
		{
			return mas;
			
		}
		
	}
	throw RepoException("Nu exista masina cu numarul de inmatriculare" + nrinmatriculare);
}


/*void RepoMasina::deleterepo(const Masina& mas) {
	const int index
}*/


const vector<Masina>& RepoMasina::getAll() const noexcept {
	return repomasini;
}

ostream& operator<<(ostream& out, const RepoException& erori)
{
	out << erori.message;
	return out;
}

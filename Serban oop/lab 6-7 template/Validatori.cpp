#include "Validatori.h"
#include <assert.h>
#include <sstream>

void ValidateMasina::valideazamasina(const Masina& mas)
{
	vector<string>messages;
	if (mas.getnrinmatriculare() == "")
	{
		messages.push_back("Numar de inmatriculare invalid!\n");
	}
	if (mas.getproducator() == "")
	{
		messages.push_back("Producator invalid!\n");
	}
	if (mas.gettip() == "")
	{
		messages.push_back("Tip invalid!\n");
	}
	if (mas.getmodel() == "")
	{
		messages.push_back("Model invalid!\n");
	}
	if (messages.size() > 0)
	{
		throw ValidateException(messages);
	}
}


ostream& operator<<(ostream& out, const ValidateException& ex)
{
	for (const auto& msg : ex.message)
	{
		out << msg << " ";
	}
	return out;
}

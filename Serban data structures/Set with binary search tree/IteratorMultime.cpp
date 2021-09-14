#include "IteratorMultime.h"
#include "Multime.h"

#include <stack>

using namespace std;


IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	//complexitate theta(1)
	PNod curent = m.radacina;
	while (curent != nullptr)
	{
		stiva.push(curent);
		curent = curent->getstanga();
	}
}



void IteratorMultime::prim() {
	 
	while (!stiva.empty()) {
		stiva.pop();
	}
	//complexitate theta(1)
	PNod curent = multime.radacina;
	while (curent != nullptr) {
		stiva.push(curent);
		curent = curent->getstanga();
	}
}

void IteratorMultime::urmator() {
	if (!valid())
		throw exception();
	PNod curent = stiva.top()->getdreapta();
	stiva.pop();
	while (curent != nullptr) {
		stiva.push(curent);
		curent = curent->getstanga();
	}
}


TElem IteratorMultime::element() const {
	if (!valid())
		throw exception();
	//complexitate theta(1)
	return stiva.top()->getelement();
}

bool IteratorMultime::valid() const {
	//complexitate theta(1)
	return !(stiva.empty());
}

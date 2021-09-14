#include "Iterator.h"
#include "Colectie.h"

/*
* v = [1, 2, 3, 3, 4, 2, 1]
*
* D = [1, 2, 3, 4]
* P = [0, 1, 2, 2, 3, 1, 0]
*
*
*/

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	/* de adaugat */
	//complexitate theta(1)
	curent = 0;
}

void IteratorColectie::prim() {
	/*
	* i = 0
	*/
	//complexitate theta(1)
	curent = 0;
}


void IteratorColectie::urmator() {
	/* de adaugat if(valid()) i++*/
	//complexitate theta(1)
	if (valid())
		curent++;

}


bool IteratorColectie::valid() const {
	/* de adaugat  i >= 0 &&i < c.dim()*/
	return curent < col.dim();
}



TElem IteratorColectie::element() const {
	/* de adaugat */
	return col.elems[curent];
}

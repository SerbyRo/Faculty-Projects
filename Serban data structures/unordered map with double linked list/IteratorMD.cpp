#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md) : md(_md) {
	/* de adaugat */
	curent = _md.prim;
}

TElem IteratorMD::element() const {
	/* de adaugat */
	return curent->element();
}

bool IteratorMD::valid() const {
	/* de adaugat */
	return curent != nullptr;
}

void IteratorMD::urmator() {
	/* de adaugat */
	curent = curent->urmator();
}

void IteratorMD::prim() {
	/* de adaugat */
	curent = md.prim;
}


//caz favorabil:theta(1)
//caz defavorabil:O(k)
//caz mediu:O(k)
//overall:O(k)

void IteratorMD::avanseazakpasi(int k)
{
	if (k <= 0)
	{
		//throw("Iterator invalid!\n");
		return;
	}
	else
	{
		for (int i = 0;i < k;i++)
		{
			curent = curent->urmator();
		}
	}
}

/*
* pseudocod
* //functionalitate prin intermediul careia avanseaza k pasi
* sualgoritm avanseazakpasi(k)
*	pre:numar intreg k
*	post:iteratorul se va muta in fata cu k pozitii
*	daca k <= 0 atunci
*		iesim din functie
*	altfel
*		pentru i=0,k-1,1 executa
*			[curent]<-[curent].urmator
*		sfpentru
*	sfsubalgoritm
*/
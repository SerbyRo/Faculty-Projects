#include <iostream>
#include "CP.h"
#include "TestExtins.h"
#include "TestScurt.h"
#include <algorithm>
#include <queue>

using namespace std;


bool rel3(TPrioritate p1, TPrioritate p2) {
	if (p1 <= p2) {
		return true;
	}
	else {
		return false;
	}
}

/*
* caz favorabil: theta(dimensiune)
* caz defavorabil: theta(dimensiune)
* caz mediu: theta(dimensiune)
* overall: theta(dimensiune)
*/
void tiparesteCoadaCuPrioritati(CP& cp)
{
	int length = cp.getdimensiune();
	for (int i = 0;i <length;i++)
	{
		Element elem = cp.sterge();
		cout << elem.first<<" "<<elem.second<< "\n";
	}
	/*Element* elems = cp.getAll();
	while (cp.vida() == false)
	{
	}*/
}
/*
* Subalgoritm tiparestecoadacuprioritati(CP& cp)
*	pre-o coada de prioritati de tipul CP 
*	post- afisarea acesteia
*	length=cp.getdimensiune()
*	pentru i=0,length executa
*		elem=cp.sterge()
*		scrie elem.first , elem.second
*	sfPentru
* sfSubAlgoritm
*	
*/

int main() {
	testAll();
	testAllExtins();
	/*CP queue(rel3);
	queue.adauga(1, 2);
	queue.adauga(1, 3);
	queue.adauga(2, 4);
	queue.adauga(2, 5);
	queue.adauga(3, 6);
	tiparesteCoadaCuPrioritati(queue);*/
	cout << "End";
}





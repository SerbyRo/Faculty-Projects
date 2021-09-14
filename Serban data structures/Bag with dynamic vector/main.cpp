#include <iostream>
#include "testextins.h"
#include "testscurt.h"
using namespace std;

/*7.TAD Colecție–memorată sub forma unui vector cu elementele distincte (D) și a unui  vector de poziții (P) în D ale elementelor colecției.
  Spre  exemplu, colecția [5, 10, -1, 2, 3, 10, 5, 5, -5] va fi reprezentată sub forma vectorilor
  D = [5, 10, -1, 2, 3, -5]
  P = [0, 1, 2, 3, 4, 1, 0, 0, 5]

*/
int main() {
	testAll();
	testAllExtins();
	cout << "End";
	return 0;
}
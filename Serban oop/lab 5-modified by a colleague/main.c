#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "teste.h"
#include "ui.h"
int main()
{

	run_all_tests();
	runAppUI();
	printf("%d\n", _CrtDumpMemoryLeaks());
	_CrtDumpMemoryLeaks();
	return 0;
}
#include <qapplication.h>
#include <qlabel.h>
#include "Masina.h"
#include "MasinaGUI.h"
#include "RepoMasina.h"
#include "ServiceMasina.h"
#include "Validatori.h"
#include "teste.h"

int main(int argc, char* argv[])
{
	run_all_tests();
	{
		QApplication app(argc, argv);
		//MemoryRepo repo;
		RepoFileMasina repo{ "masini.txt" };
		//LabRepo repo{ 0.5 };
		ManageMasini worklist;
		ValidateMasina val;
		ServiceMasina servmasini{ repo,val,worklist };
		MasinaGUI guimasina{ servmasini };
		guimasina.show();
		return app.exec();
	}
}
#include "Ionescu_Serban_214simulare.h"
#include <QtWidgets/QApplication>
#include "Teste.h"
#include "Articol.h"
#include "FileRepoArticol.h"
#include "ServiceArticol.h"
#include "ArticolGUI.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teste teste;
    teste.run_all_tests();
    FileRepoArticol filerepo{ "fisier.txt" };
    ServiceArticol service{ filerepo };
    ArticolGUI gui{ service };
    gui.show();
    return a.exec();
}

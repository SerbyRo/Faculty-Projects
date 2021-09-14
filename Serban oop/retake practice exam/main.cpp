#include "Ionescu_Serban_marire_oop.h"
#include <QtWidgets/QApplication>
#include "Teste.h"
#include "Tractor.h"
#include "FileRepo.h"
#include "ServiceTractor.h"
#include "Validatori.h"
#include "GUITractor.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teste teste;
    teste.run_all_tests();
    FileRepo file{ "tractoare.txt" };
    Validatori val;
    ServiceTractor serv{ file,val };
    GUITractor gui{ serv };
    gui.show();
    return a.exec();
}

#include "ExamenIonescuSerban.h"
#include <QtWidgets/QApplication>
#include "Teste.h"
#include "Carte.h"
#include "FileRepo.h"
#include "ServiceCarte.h"
#include "GUICarte.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teste teste;
    teste.run_all_tests();
    FileRepo file{ "carti.txt" };
    Validatori val;
    ServiceCarte serv{ file,val };
    GUICarte consgui{ serv };
    consgui.show();
    /*ExamenIonescuSerban w;
    w.show();*/
    return a.exec();
}

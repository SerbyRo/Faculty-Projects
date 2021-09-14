#include "UiMasina.h"
#include "Masina.h"
#include "RepoMasina.h"
#include "ServiceMasina.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;

void UiMasina::tipareste(const vector<Masina>& masini)
{
	cout << "Masinile sunt:\n";
	for (const auto& masina : masini)
	{
		cout << masina.getnrinmatriculare() << " " << masina.getproducator() <<" " << masina.gettip() <<" " << masina.getmodel()<<"\n";
	}
}

void UiMasina::adaugaUI() {
	string nrinmatriculare;
	cout << "Numar de inmatriculare:";
	cin >> nrinmatriculare;
	string producator;
	cout << "Producator:";
	cin >> producator;
	string tip;
	cout << "Tipul este:";
	cin >> tip;
	string model;
	cout << "Modelul este:";
	cin >> model;
	servmasini.addMasina(nrinmatriculare, producator, tip, model);
	cout << "Adaugare efectuata cu succes!\n";
}

void UiMasina::runApp()
{
	while (true)
	{
		cout << "MENU\n";
		cout << "1 Adauga masina!\n";
		cout << "2 Tipareste\n";
		cout << "3 Sorteaza dupa numar de inmatriculare\n";
		cout << "4 Sorteaza dupa tip\n";
		cout << "5 Sorteaza dupa producator si model\n";
		cout << "6 Filtreaza dupa producator\n";
		cout << "7 Filtreaza dupa tip\n";
		cout << " 0 Exit\n";
		cout << "Dati comanda\n";
		int cmd;
		cin >> cmd;
		try
		{
			switch (cmd)
			{
			case 1:
			{
				adaugaUI();
				break;
			}
				
			case 2:
			{
				tipareste(servmasini.getAll());
				break;
			}	
			case 3:
			{
				tipareste(servmasini.sortbynrinmatriculare());
				break;
			}
			case 4:
			{
				tipareste(servmasini.sortbytip());
				break;
			}
			case 5:
			{
				tipareste(servmasini.sortbyproducatormodel());
				break;
			}
			case 6:
			{
				string producator;
				cout << "Producatorul dupa care facem filtrarea este:";
				cin >> producator;
				tipareste(servmasini.filterbyproducator(producator));
				break;
			}
			case 7:
			{
				string tip;
				cout << "Tipul dupa care facem filtrarea este:";
				cin >> tip;
				tipareste(servmasini.filterbytip(tip));
				break;
			}
			case 0:
				return;
			default:
				cout << "Comanda invalida\n";
			}
		}
		catch (const RepoException& ex) {
			cout << ex << '\n';
		}
		catch (const ValidateException& ex) {
			cout << ex << '\n';
		}
	}
}

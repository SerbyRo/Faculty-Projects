#pragma once
#include "qwidget.h"
#include "qpushbutton.h"
#include "qlineedit.h"
#include "ServiceCarte.h"
#include "qtablewidget.h"
#include "qslider.h"
#include "MyModelTableView.h"



class GUICarte:public QWidget
{
private:
	ServiceCarte& servcarte;
	QPushButton* btnadauga = new QPushButton{"Adauga carte"};
	QPushButton* btnfiltreaza = new QPushButton{ "Filtreaza carti" };

	QSlider* slider = new QSlider{ Qt::Horizontal };
	QLineEdit* filterbypret = new QLineEdit;
	QLineEdit* lineid = new QLineEdit;
	QLineEdit* linetitlu = new QLineEdit;
	QLineEdit* linetip = new QLineEdit;
	QLineEdit* linepret = new QLineEdit;
	QPushButton* btnrefresh = new QPushButton{"Refresh table"};
	QTableWidget* table = new QTableWidget;

	QTableView* tblview = new QTableView;

	MyModelTableView* model;

	void initGUI();
	void initSemnals();
	void reloadtable(const vector<Carte>);
	void reloadtablewithcolor(const vector<Carte>);

public:
	GUICarte(ServiceCarte& servcarte) :servcarte{ servcarte } {

		initGUI();
		initSemnals();
		model = new MyModelTableView(servcarte);
		tblview->setModel(model);
		reloadtable(servcarte.sortbyliteretip());
	}
};


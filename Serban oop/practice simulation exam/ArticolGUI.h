#pragma once
#include <qwidget.h>
#include <qapplication.h>
#include "ServiceArticol.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
class ArticolGUI:public QWidget
{
private:
	ServiceArticol& service;
	QLineEdit* txtnume = new QLineEdit;
	QLineEdit* txttip = new QLineEdit;
	QLineEdit* txtmarime = new QLineEdit;
	QLineEdit* txtstoc = new QLineEdit;
	QListWidget* list = new QListWidget;
	QPushButton* btnadauga = new QPushButton{ "Adauga" };
	QPushButton* btnfiltreaza = new QPushButton{ "Filter" };
	QLineEdit* txtfnume = new QLineEdit;
	QLineEdit* txtfmarime = new QLineEdit;
	QPushButton* btnsterge = new QPushButton{ "Sterge" };
	void initGUI();
	void initSemnals();
	void reloadlist(const vector<Articol>& articole);
public:
	ArticolGUI(ServiceArticol& service) :service{ service } {
		initGUI();
		initSemnals();
		reloadlist(service.getAllService());
	}

};


#pragma once
#include <qmainwindow.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qmessagebox.h>
#include <qtablewidget.h>
#include <vector>
#include <string>
#include <qlineedit.h>
#include <qwidget.h>
#include <qapplication.h>
#include <qpushbutton.h>
#include "ServiceMasina.h"
#include "MyModelList.h"
#include <qinputdialog.h>
#include <qdir.h>
#include <qboxlayout.h>
#include <qlistview.h>
#include <qspinbox.h>
#include "Observer.h"
using std::vector;


class CosGUI :public QWidget,public Observer {
private:
	ServiceMasina& servmasini;
	QPushButton* btngolestecos = new QPushButton{ "&goleste" };
	QPushButton* btngenereazarandom = new QPushButton("&Generaterandom");
	QPushButton* btnadaugacos = new QPushButton("&adaugacos");
	QPushButton* btnexportalista = new QPushButton("&Exportalist");
	QTableWidget* table = new QTableWidget(1, 1);

	void InitCosGUI()
	{
		QVBoxLayout* hly = new QVBoxLayout;
		this->setLayout(hly);
		QHBoxLayout* butons = new QHBoxLayout;
		QWidget* wid = new QWidget;
		wid->setLayout(butons);

		butons->addWidget(btngenereazarandom);
		butons->addWidget(btngolestecos);
		butons->addWidget(btnadaugacos);
		butons->addWidget(btnexportalista);

		hly->addWidget(wid);
		hly->addWidget(table);
	}
	void InitGUISemnals()
	{
		QObject::connect(btngenereazarandom, &QPushButton::clicked, [&]() {
			bool ok;
			size_t lungime = servmasini.getAll().size();
			int lungime1 = static_cast<int>(lungime);
			int nr = QInputDialog::getInt(this, "Alege:", "Alege numarul de masini:", 0, 0, lungime1, 1, &ok);
			servmasini.generaterandomlist(nr);
			reloadtablecos(servmasini.getworklist());
			});
		QObject::connect(btngolestecos, &QPushButton::clicked, [&]() {
			servmasini.listagoala();
			reloadtablecos(servmasini.getworklist());
			});
		QObject::connect(btnadaugacos, &QPushButton::clicked, [&]()
			{
				//int randomnumber = rand() % 8;
				bool ok;
				QString text1 = QInputDialog::getText(this, tr("QInputDialog::getText()"),
					tr("Numarul de inmatriculare al masinii pe care o adaugam este:"), QLineEdit::Normal,
					QDir::home().dirName(), &ok);
				servmasini.addworkcar(text1.toStdString());
				reloadtablecos(servmasini.getworklist());
			});
		QObject::connect(btnexportalista, &QPushButton::clicked, [&]() {
			bool ok;
			QString text1 = QInputDialog::getText(this, tr("QInputDialog::getText()"),
				tr("Fisierul in care salvam este:"), QLineEdit::Normal,
				QDir::home().dirName(), &ok);
			servmasini.saveworklistinCVS(text1.toStdString());
			reloadtablecos(servmasini.getworklist());
			});

	}
	void reloadtablecos(const vector<Masina>& masini)
	{
		table->setColumnCount(4);
		size_t lungime = masini.size();
		int lungime1 = static_cast<int>(lungime);
		table->setRowCount(lungime1);
		int i = 0;
		for (const auto& mas : masini)
		{
			auto itemName = QString::fromStdString(mas.getnrinmatriculare());
			QTableWidgetItem* item = new QTableWidgetItem(itemName);
			table->setItem(i, 0, item);
			auto itemName1 = QString::fromStdString(mas.getproducator());
			QTableWidgetItem* item1 = new QTableWidgetItem(itemName1);
			table->setItem(i, 1, item1);
			auto itemName2 = QString::fromStdString(mas.gettip());
			QTableWidgetItem* item2 = new QTableWidgetItem(itemName2);
			table->setItem(i, 2, item2);
			auto itemName3 = QString::fromStdString(mas.getmodel());
			QTableWidgetItem* item3 = new QTableWidgetItem(itemName3);
			table->setItem(i, 3, item3);
			i++;
		}
	}
public:
	CosGUI(ServiceMasina& servmasini) :servmasini{ servmasini } {
		servmasini.addObserver(this);
		InitCosGUI();
		InitGUISemnals();
		reloadtablecos(servmasini.getworklist());
	}
	void update() override
	{
		reloadtablecos(servmasini.getworklist());
	}
};

class MasinaGUI :public QWidget,public Observer,public Observable
{
private:
	ServiceMasina& servmasini;
	QHBoxLayout* lymain = new QHBoxLayout{};
	MyModelListView* model;
	QListWidget* list = new QListWidget;
	QTableWidget* table = new QTableWidget;
	QListView* listview = new QListView;
	QLineEdit* txtnrinmatriculare = new QLineEdit;
	QLineEdit* txtproducator = new QLineEdit;
	QLineEdit* txttip = new QLineEdit;
	QLineEdit* txtmodel = new QLineEdit;
	QLineEdit* txtfiltertip = new QLineEdit;
	QLineEdit* txtfilterproducator = new QLineEdit;
	QPushButton* btnadauga = new QPushButton{ "&Adauga" };
	QPushButton* btnexit = new QPushButton{ "&Exit" };
	QPushButton* btnmodifica = new QPushButton{ "&Modifca" };
	QPushButton* btnsterge = new QPushButton{ "&Sterge" };
	QPushButton* btnsortbynri = new QPushButton{ "&Sort by nrinmatriculare" };
	QPushButton* btnsortbytip = new QPushButton{ "&Sort by tip" };
	QPushButton* btnsortbyprodmodel = new QPushButton{ "&Sort by producator & model" };
	QPushButton* btnfilterbyprod = new QPushButton{ "&Filter by producator" };
	QPushButton* btnfilterbytip = new QPushButton{ "&Filter by tip" };
	QPushButton* btnfilter = new QPushButton{ "&Filtreaza" };
	QPushButton* btnundo = new QPushButton{ "&Undo" };
	QPushButton* btnraport = new QPushButton{ "&Raport" };
	QPushButton* btncos = new QPushButton{ "& Cos" };
	QPushButton* btndesen = new QPushButton{ "&Desen" };
	QPushButton* btngolestecos = new QPushButton{ "&goleste" };
	QPushButton* btngenereazarandom = new QPushButton("&Generaterandom");
	QPushButton* btnadaugacos = new QPushButton("&adaugacos");
	QLineEdit* nrelemcos = new QLineEdit;
	QLabel* label = new QLabel{ "Numar de elemente din cos:" };
	QWidget* btndynamic = new QWidget;
	QVBoxLayout* lybtn = new QVBoxLayout;
	QSlider* slider = new QSlider(Qt::Horizontal);	// sliderul
	QLabel* nrOfSlider = new QLabel("1");
	QVBoxLayout* butoanedinamice = new QVBoxLayout;
	QSpinBox* spin = new QSpinBox;
	void loadButtons();
	vector<string>currentButtons;
	//MyModelListView* model;
	void initGUI();
	void loadData(const vector<Masina>&);
	//void adaugabutoane(const vector<Masina>&);
	void loadDataColor(const vector<Masina>&, vector<Masina>);
	void initConnect();
	void adaugaGUI();
	void stergeGUI();
	void modificaGUI();
	void filtreazatipGUI();
	void filtreazaprodGUI();
	void sorteazanrinmatriculareGUI();
	void sorteazatipGUI();
	void sorteazaprodmodelGUI();
	void raportGUI();
	void undoGUI();
	void worklistGUI();
	void desenGUI();
	void update() override
	{
		nrelemcos->setText(QString::number(servmasini.getworklist().size()));
	}
public:
	MasinaGUI(ServiceMasina& servmasini) :servmasini{ servmasini } {
		servmasini.addObserver(this);
		model = new MyModelListView(servmasini.getAll());
		listview->setModel(model);
		initGUI();
		initConnect();
		loadButtons();
		loadData(servmasini.getAll());
		//adaugabutoane(servmasini.getAll());
	};
};



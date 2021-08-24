#include "MasinaGUI.h"
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
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qdebug.h>
#include <qbrush.h>
#include <qspinbox.h>
#include <qobject.h>
#include "ServiceMasina.h"
#include <qinputdialog.h>
#include <algorithm>
#include "CosReadOnlyGUI.h"
using std::vector;





void MasinaGUI::initGUI()
{
	setLayout(lymain);
	//lymain->addWidget(list);
	lymain->addWidget(listview);
	lymain->addWidget(table);
	QWidget* fereastrastanga = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout{};
	fereastrastanga->setLayout(vl);
	vl->addWidget(btnundo);
	lymain->addWidget(fereastrastanga);
	QFormLayout* formdetalii = new QFormLayout;
	formdetalii->addRow(new QLabel("Numar de inmatriculare:"), txtnrinmatriculare);
	formdetalii->addRow(new QLabel("Producator:"), txtproducator);
	formdetalii->addRow(new QLabel("Tip:"), txttip);
	formdetalii->addRow(new QLabel("Model:"), txtmodel);
	QHBoxLayout* butoanecrud = new QHBoxLayout{};
	butoanecrud->addWidget(btnadauga);
	butoanecrud->addWidget(btnsterge);
	butoanecrud->addWidget(btnmodifica);
	QVBoxLayout* cosbuttons = new QVBoxLayout{};
	cosbuttons->addWidget(btnadaugacos);
	cosbuttons->addWidget(btngolestecos);
	cosbuttons->addWidget(btngenereazarandom);
	QVBoxLayout* filterbutons = new QVBoxLayout{};
	QFormLayout* formdetalii1 = new QFormLayout;
	formdetalii1->addRow(new QLabel("Filtram dupa producatorul: "), txtfilterproducator);
	formdetalii1->addRow(new QLabel("Filtram dupa tip: "), txtfiltertip);
	formdetalii1->addRow(label, nrelemcos);
	filterbutons->addWidget(btnfilterbyprod);
	filterbutons->addWidget(btnfilterbytip);
	filterbutons->addWidget(btncos);
	filterbutons->addWidget(btndesen);
	filterbutons->addWidget(btnraport);
	QVBoxLayout* sortbutons = new QVBoxLayout{};
	sortbutons->addWidget(btnsortbynri);
	sortbutons->addWidget(btnsortbytip);
	sortbutons->addWidget(btnsortbyprodmodel);
	sortbutons->addWidget(btnexit);
	lymain->addLayout(formdetalii);
	lymain->addLayout(butoanecrud);
	lymain->addLayout(cosbuttons);
	lymain->addLayout(sortbutons);
	lymain->addLayout(filterbutons);
	lymain->addLayout(formdetalii1);
	btndynamic->setLayout(lybtn);
	lymain->addWidget(btndynamic);
}

void MasinaGUI::worklistGUI()
{
	CosGUI* cosgui = new CosGUI(servmasini);
	cosgui->move(10, 10);
	cosgui->show();

	/*CosGUI* cosgui1 = new CosGUI(servmasini);
	cosgui1->move(10, 300);
	cosgui1->show();

	CosGUI* cosgui2 = new CosGUI(servmasini);
	cosgui2->move(300, 10);
	cosgui2->show();*/
}

void MasinaGUI::adaugaGUI()
{
	try {
		servmasini.addMasina(txtnrinmatriculare->text().toStdString(), txtproducator->text().toStdString(), txttip->text().toStdString(), txtmodel->text().toStdString());
		loadButtons();
		loadData(servmasini.getAll());
	}
	catch (RepoException& msg)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getmesaj()));
	}
	catch (ValidateException&)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString("Date gresite introduse!Reincearca!"));
	}
}

void MasinaGUI::stergeGUI()
{
	try
	{
		servmasini.deleteservice(txtnrinmatriculare->text().toStdString());
		loadData(servmasini.getAll());
		loadButtons();
	}
	catch (RepoException& msg)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getmesaj()));
	}
}


void MasinaGUI::modificaGUI()
{
	try {
		servmasini.updateservice(txtnrinmatriculare->text().toStdString(), txtproducator->text().toStdString(), txttip->text().toStdString(), txtmodel->text().toStdString());
		loadData(servmasini.getAll());
	}
	catch (RepoException& msg)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getmesaj()));
	}
}

void MasinaGUI::desenGUI()
{
	CosReadOnlyGUI* desenGUI = new CosReadOnlyGUI{servmasini};
	desenGUI->show();
}

void MasinaGUI::undoGUI()
{
	try {
		servmasini.undo();
		loadData(servmasini.getAll());
		loadButtons();
		//adaugabutoane(servmasini.getAll());
	}
	catch (RepoException& msg)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getmesaj()));
	}
}

void MasinaGUI::raportGUI()
{
	try
	{

		auto raport = servmasini.raport();
		table->clear();
		size_t lungime = raport.size();
		int lungime1 = static_cast<int>(lungime);
		table->setRowCount(lungime1);
		table->setColumnCount(2);
		int i = 0;
		for (auto iterator : raport)
		{
			table->setItem(i, 0, new QTableWidgetItem(iterator.first.c_str()));
			table->setItem(i, 1, new QTableWidgetItem(QString::number(iterator.second.getCount())));
			i++;
		}
		/*QSpinBox* integerSpinBox = new QSpinBox;
		integerSpinBox->setRange(-20, 20);
		integerSpinBox->setSingleStep(1);
		integerSpinBox->setValue(0);*/
	}
	catch (RepoException& msg)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(msg.getmesaj()));
	}
}


void MasinaGUI::initConnect()
{
	QObject::connect(btnexit, &QPushButton::clicked, [&]() {
		qDebug() << "Exit : buton apasat!";
		QMessageBox::information(nullptr, "Info", "Buton apasat!");
		close();
		});
	QObject::connect(btnadauga, &QPushButton::clicked, this, &MasinaGUI::adaugaGUI);
	QObject::connect(btngolestecos,&QPushButton::clicked,[&](){
		servmasini.listagoala();
		notifyObserver();
	});
	QObject::connect(btnadaugacos, &QPushButton::clicked, [&]() {
		bool ok;
		QString text1 = QInputDialog::getText(this, tr("QInputDialog::getText()"),
			tr("Numarul de inmatriculare al masinii pe care o adaugam este:"), QLineEdit::Normal,
			QDir::home().dirName(), &ok);
		servmasini.addworkcar(text1.toStdString());
		notifyObserver();
		});
	QObject::connect(btngenereazarandom, &QPushButton::clicked, [&]() {
		//bool ok;
		size_t lungime = servmasini.getAll().size();
		int lungime1 = static_cast<int>(lungime);
		//int nr = QInputDialog::getInt(this, "Alege:", "Alege numarul de masini:", 0, 0, lungime1, 1, &ok);
		spin->setRange(1, lungime1);
		int nr = spin->value();
		servmasini.generaterandomlist(nr);
		notifyObserver();
		
		});
	QObject::connect(btnsterge, &QPushButton::clicked, this, &MasinaGUI::stergeGUI);
	QObject::connect(btnmodifica, &QPushButton::clicked, this, &MasinaGUI::modificaGUI);
	QObject::connect(btnundo, &QPushButton::clicked, this, &MasinaGUI::undoGUI);
	QObject::connect(btnraport, &QPushButton::clicked, this, &MasinaGUI::raportGUI);
	QObject::connect(btncos, &QPushButton::clicked, this, &MasinaGUI::worklistGUI);
	QObject::connect(btndesen, &QPushButton::clicked, this, &MasinaGUI::desenGUI);
	//QObject::connect(spAge, &QSpinBox::valueChanged, slAge, &QSlider::setValue);
	//QObject::connect(slAge, SIGNAL(valueChanged(int)), spAge, SLOT(setValue(int)));
	QObject::connect(btnsortbynri, &QPushButton::clicked, [&]() {
		loadData(servmasini.generalsort(0));
		});
	QObject::connect(btnsortbytip, &QPushButton::clicked, [&]() {
		loadData(servmasini.generalsort(1));
		});
	QObject::connect(btnsortbyprodmodel, &QPushButton::clicked, [&]() {
		loadData(servmasini.generalsort(2));
		});
	QObject::connect(btnfilterbyprod, &QPushButton::clicked, [&]() {
		loadDataColor(servmasini.getAll(),servmasini.filterbyproducator(txtfilterproducator->text().toStdString()));
		});
	QObject::connect(btnfilterbytip, &QPushButton::clicked, [&]() {
		loadDataColor(servmasini.getAll(),servmasini.filterbytip(txtfiltertip->text().toStdString()));
		});
	/*QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
		qDebug() << "selectie schimbata!!!";
		auto selected = list->selectedItems();
		if (selected.isEmpty())
		{
			txtnrinmatriculare->setText("");
			txtproducator->setText("");
			txttip->setText("");
			txtmodel->setText("");
		}
		else
		{
			auto selItem = selected.at(0);
			auto nrinmatriculare = selItem->text();
			auto producator = selItem->data(Qt::UserRole).toString();
			txtnrinmatriculare->setText(nrinmatriculare);
			txtproducator->setText(producator);
			auto masina = servmasini.findservice(nrinmatriculare.toStdString());
			txttip->setText(QString::fromStdString(masina.gettip()));
			txtmodel->setText(QString::fromStdString(masina.getmodel()));
		}
		});*/
	QObject::connect(listview->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (listview->selectionModel()->selectedIndexes().isEmpty())
		{
			txtnrinmatriculare->setText("");
			txtproducator->setText("");
			txttip->setText("");
			txtmodel->setText("");
		}
		auto vec = servmasini.getAll();
		auto selItem = listview->selectionModel()->selectedIndexes().at(0);
		QString txt = selItem.data(Qt::DisplayRole).toString();
		Masina mas;
		for (auto m : vec)
		{
			if (m.getnrinmatriculare() == txt.toStdString())
			{
				mas = m;
			}
		}
		txtnrinmatriculare->setText(QString::fromStdString(mas.getnrinmatriculare()));
		txttip->setText(QString::fromStdString(mas.gettip()));
		txtproducator->setText(QString::fromStdString(mas.getproducator()));
		txtmodel->setText(QString::fromStdString(mas.getmodel()));
		});
}



void MasinaGUI::loadData(const vector<Masina>& masini)
{
	//list->clear();

	//for (const auto mas : masini)
	//{
	//	QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(mas.getnrinmatriculare()), list);
	//	item->setData(Qt::UserRole, QString::fromStdString(mas.getproducator()));
	//	//item->setData(Qt::ForegroundRole,)
	//	
	//	//item->setBackground(QBrush{ Qt::blue,Qt::SolidPattern });
	//	list->addItem(item);
	//}
	model->setMasina(masini);
}
void MasinaGUI::loadDataColor(const vector<Masina>& masini1, vector<Masina> strings)
{
	list->clear();
	for (auto& mas : masini1)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(mas.getnrinmatriculare()));
		item->setData(Qt::UserRole,QString::fromStdString( mas.getmodel()));
		bool ok = false;
		for (auto& mas2 : strings)
		{
			if (mas.getproducator() == mas2.getproducator())
			{
				ok = true;
				break;
			}
		}
		if (ok)
		{
			item->setBackground(Qt::blue);
		}
	list->addItem(item);
	}
}

void MasinaGUI::loadButtons()
{
	lymain->addLayout(butoanedinamice);
	map<string, DTO> dict = servmasini.raport();

	for (auto& x : dict)
	{
		bool ok = true;
		for (auto& ss : currentButtons)
		{
			if (ss==x.first)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			QString s = QString::fromStdString(x.first);
			QPushButton* btn = new QPushButton(s);
			currentButtons.push_back(x.first);
			QObject::connect(btn, &QPushButton::clicked, [=]() {
				string txt = btn->text().toStdString();
				auto all = servmasini.getAll();
				for (auto& m : all)
				{
					if (m.getmodel() == txt)
					{
						servmasini.deleteservice(m.getnrinmatriculare());
					}
				}
				unsigned int i = 0;
				for (auto& ss : currentButtons)
				{
					if (ss == txt)
					{
						vector<string> ::iterator it{ currentButtons.erase(currentButtons.begin() + i) };
					}
					i++;
				}
				loadData(servmasini.getAll());
				delete btn;
			});
			butoanedinamice->addWidget(btn);
		}
	}
}



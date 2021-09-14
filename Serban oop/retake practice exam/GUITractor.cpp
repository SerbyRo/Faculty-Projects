#include "GUITractor.h"

void GUITractor::initGUI()
{
	table->setModel(model);
	QVBoxLayout* lymain = new QVBoxLayout;
	setLayout(lymain);

	QVBoxLayout* vly = new QVBoxLayout;
	vly->addWidget(table);
	lymain->addLayout(vly);
	QFormLayout* formdetalii = new QFormLayout;
	formdetalii->addRow(new QLabel{ "Id: " }, idaddline);
	formdetalii->addRow(new QLabel{ "Denumire: " }, denumireaddline);
	formdetalii->addRow(new QLabel{ "Tip: " }, tipaddline);
	formdetalii->addRow(new QLabel{ "Numar roti: " }, nrrotiaddline);
	formdetalii->addRow(btnadauga);
	lymain->addLayout(formdetalii);
	vector<string> tipuri=servtractor.nrtipuri();
	for (auto tip : tipuri)
	{
		combotip->addItem(QString::fromStdString(tip));
	}
	lymain->addWidget(combotip);
	//lymain->addWidget(desentipuri);
}


void GUITractor::initSemnals()
{
	QObject::connect(btnadauga,&QPushButton::clicked, [&]() {
		int id = idaddline->text().toInt();
		string denumire = denumireaddline->text().toStdString();
		string tip = tipaddline->text().toStdString();
		int nrroti = nrrotiaddline->text().toInt();
		try {
			servtractor.addService(id, denumire, tip, nrroti);
			reloadtable(servtractor.sortbydenumire());
		}
		catch (FileRepoException& ex)
		{
			QMessageBox::warning(this, "Eroare", QString::fromStdString(ex.geterori()));
		}
		catch (ValidateException& ex)
		{
			QMessageBox::warning(this, "Eroare", QString::fromStdString(ex.geterori()));
		}
		});
	QObject::connect(combotip, &QComboBox::currentTextChanged, [&]() {
		string tip = combotip->currentText().toStdString();
		if (tip == "")
		{
			reloadtable(servtractor.sortbydenumire());
		}
		else
		{
			reloadtablewithcolor(servtractor.sortbydenumire(), tip);
		}
		});
	QObject::connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		int selrow = table->selectionModel()->selectedIndexes().at(0).row();
		auto cell4row = table->model()->index(selrow, 4);
		auto cell = table->model()->data(cell4row, Qt::UserRole).toInt();
		desenare(cell);
		});
}

void GUITractor::reloadtable(vector<Tractor> tractoare)
{
	MyTableModel* newmodel = new MyTableModel(tractoare);
	delete model;
	model = newmodel;
	table->setModel(model);
	//desenare();
}

void GUITractor::reloadtablewithcolor(vector<Tractor> tractoare,string tip)
{
	MyTableModel* newmodel = new MyTableModel(tractoare,tip);
	delete model;
	model = newmodel;
	table->setModel(model);
	//desenare();
}

void GUITractor::desenare(int nr)
{
	desentipuri->setnr(nr);
	desentipuri->repaint();
}



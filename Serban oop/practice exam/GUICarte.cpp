#include "GUICarte.h"

#include "qboxlayout.h"
#include "qwidget.h"
#include "qformlayout.h"
#include "qlabel.h"
#include "qmessagebox.h"

void GUICarte::initGUI()
{
	QVBoxLayout* lymain = new QVBoxLayout{};
	setLayout(lymain);
	QWidget* windowstanga = new QWidget;
	QVBoxLayout* layout1 = new QVBoxLayout{};
	lymain->addWidget(table);
	windowstanga->setLayout(layout1);
	layout1->addWidget(btnadauga);
	layout1->addWidget(btnfiltreaza);
	layout1->addWidget(btnrefresh);
	lymain->addWidget(windowstanga);
	QFormLayout* formdetalii = new QFormLayout;
	formdetalii->addRow(new QLabel{ "Id : " }, lineid);
	formdetalii->addRow(new QLabel{ "Titlu : " }, linetitlu);
	formdetalii->addRow(new QLabel{ "Tip : " }, linetip);
	formdetalii->addRow(new QLabel{ "Pret : " }, linepret);
	formdetalii->addRow(new QLabel{ "Filtrare dupa pret:" }, filterbypret);
	QHBoxLayout* sliderbox = new QHBoxLayout{};
	sliderbox->addWidget(slider);
	slider->setValue(1);
	slider->setMinimum(1);
	slider->setMaximum(100);
	lymain->addLayout(sliderbox);
	lymain->addLayout(formdetalii);
}

void GUICarte::initSemnals()
{
	QObject::connect(btnadauga, &QPushButton::clicked, [&]() {
		int id = lineid->text().toInt();
		string titlu = lineid->text().toStdString();
		string tip = linetip->text().toStdString();
		double pret = linepret->text().toDouble();
		try {
			servcarte.addService(id, titlu, tip, pret);
		}
		catch (RepoException& ex)
		{
			QMessageBox::warning(this, "Eroare", QString::fromStdString(ex.geterori()));
		}
		catch (ValidateException& ex)
		{
			QMessageBox::warning(this, "Eroare", QString::fromStdString(ex.geterori()));
		}
		reloadtable(servcarte.sortbyliteretip());
		});
	QObject::connect(slider, &QSlider::valueChanged, [&](int valoare) {
		filterbypret->setText(QString::number(valoare));
		});

	QObject::connect(btnfiltreaza, &QPushButton::clicked, [&]() {
		int filtru = filterbypret->text().toInt();
		if (filtru >= 50)
		{
			reloadtablewithcolor(servcarte.sortbyliteretip());
		}
		else
		{
			reloadtable(servcarte.sortbyliteretip());
		}
		});
	QObject::connect(tblview, &QTableView::setSelectionModel, [&]() {
		model->setCarte(servcarte.sortbyliteretip());
		
		});
	QObject::connect(btnrefresh, &QPushButton::clicked, [&]() {
		reloadtable(servcarte.sortbyliteretip());
		});

}

void GUICarte::reloadtable(const vector<Carte> carti)
{
	table->clear();
	table->setColumnCount(5);
	table->setRowCount(carti.size());
	int i = 0;
	for (auto carte : carti)
	{
		QTableWidgetItem* item = new QTableWidgetItem(QString::number(carte.getid()));
		table->setItem(i, 0, item);
		QTableWidgetItem* item1 = new QTableWidgetItem(QString::fromStdString(carte.gettitlu()));
		table->setItem(i, 1, item1);
		QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(carte.gettip()));
		table->setItem(i, 2, item2);
		QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(carte.getpret()));
		table->setItem(i, 3, item3);
		QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(carte.gettip().size()));
		table->setItem(i, 4, item4);
		i++;
	}
	vector<Carte> carti1 = servcarte.getAllService();
	vector<Carte> filtrucarti;
	int ok = 0;
	for (int i = 0;i < carti1.size();i++)
	{
		for (int j = 0;j < filtrucarti.size();j++)
		{
			if (servcarte.getAllService().at(i).gettip() == filtrucarti.at(i).gettip())
			{
				ok = 1;
			}
			if (ok == 0)
			{
				filtrucarti.push_back(carti1.at(i));
				QWidget* newwindow = new QWidget;
				newwindow->show();
			}
		  }

	}

	//model->setCarte(carti);
}

void GUICarte::reloadtablewithcolor(const vector<Carte> carti)
{
	table->clear();
	table->setColumnCount(5);
	table->setRowCount(carti.size());
	int i = 0;
	for (auto carte : carti)
	{
		if (carte.getpret() < 50)
		{
			auto item = new QTableWidgetItem(QString::number(carte.getid()));
			table->setItem(i, 0, item);
			item = new QTableWidgetItem(QString::fromStdString(carte.gettitlu()));
			table->setItem(i, 1, item);
			item = new QTableWidgetItem(QString::fromStdString(carte.gettip()));
			table->setItem(i, 2, item);
			item = new QTableWidgetItem(QString::number(carte.getpret()));
			table->setItem(i, 3, item);
			item = new QTableWidgetItem(QString::number(carte.gettip().size()));
			table->setItem(i, 4, item);
			i++;
		}
		

		/*if (carte.getpret() < 50)
		{
			table->item(i, 0)->setBackground(QBrush{ Qt::red });
			table->item(i, 1)->setBackground(Qt::red);
			table->item(i, 2)->setBackground(Qt::red);
			table->item(i, 3)->setBackground(Qt::red);
			table->item(i, 4)->setBackground(Qt::red);
			????????
		}*/
	}
}



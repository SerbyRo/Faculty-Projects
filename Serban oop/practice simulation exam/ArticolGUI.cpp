#include "ArticolGUI.h"
#include "qboxlayout.h"
#include "qformlayout.h"
#include "qlabel.h"
void ArticolGUI::initGUI()
{
	QHBoxLayout* lymain = new QHBoxLayout{};
	setLayout(lymain);
	lymain->addWidget(list);
	QWidget* fereastra = new QWidget;
	QVBoxLayout* vly = new QVBoxLayout{};
	fereastra->setLayout(vly);
	vly->addWidget(btnadauga);
	vly->addWidget(btnfiltreaza);
	vly->addWidget(btnsterge);
	QFormLayout* formdetalii = new QFormLayout;
	formdetalii->addRow(new QLabel("Nume:"), txtnume);
	formdetalii->addRow(new QLabel("Tip:"), txttip);
	formdetalii->addRow(new QLabel("Marime:"), txtmarime);
	formdetalii->addRow(new QLabel("Stoc:"), txtstoc);
	lymain->addLayout(formdetalii);
	lymain->addWidget(fereastra);
}


void ArticolGUI::reloadlist(const vector<Articol>& articole)
{
	list->clear();
	for (auto art : articole)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(art.getnume()), list);
		item->setData(Qt::UserRole, QString::fromStdString(art.gettip()));
		list->addItem(item);
	}
}

void ArticolGUI::initSemnals()
{
	QObject::connect(btnadauga, &QPushButton::clicked, [&]() {
		auto nume = txtnume->text().toStdString();
		auto tip = txtnume->text().toStdString();
		auto marime = txtmarime->text().toInt();
		auto stoc = txtstoc->text().toInt();
		Articol art(nume, tip, marime, stoc);
		service.addService(art);
		reloadlist(service.getAllService());
		});
	QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
			auto selected = list->selectedItems();
			auto selItem = selected.at(0);
			auto nume = selItem->text();
			auto art = service.findart(nume.toStdString());
			txttip->setText(QString::fromStdString(art.gettip()));
			txtmarime->setText(QString::number(art.getmarime()));
			txtstoc->setText(QString::number(art.getstoc()));

		});
	QObject::connect(btnfiltreaza, &QPushButton::clicked, [&]() {
		reloadlist(service.filternume(txtfnume->text().toStdString()));
		});

}

#pragma once
#include "Tractor.h"
#include "FileRepo.h"
#include "ServiceTractor.h"
#include "Validatori.h"
#include "qwidget.h"
#include "qpushbutton.h"
#include "qlineedit.h"
#include "qlabel.h"
#include "qcombobox.h"
#include "qtableview.h"
#include "qboxlayout.h"
#include "qpainter.h"
#include "qformlayout.h"
#include "qmessagebox.h"
class MyTableModel :public QAbstractTableModel
{
private:
	vector<Tractor> tractoare;
	string tip;
public:
	MyTableModel(vector<Tractor> tractoare) :tractoare{ tractoare } { tip = ""; }

	MyTableModel(vector<Tractor> tractoare, string tip):tractoare{tractoare},tip{tip}{}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return (int)tractoare.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole)
		{
			Tractor trac = tractoare.at(index.row());
			int nrtip = 0;
			for (auto tr : tractoare)
			{
				if (tr.getid() != trac.getid() && tr.gettip() == trac.gettip())
				{
					nrtip++;
				}
			}
			switch (index.column())
			{
			case 0:
				return QString::number(trac.getid());
			case 1:
				return QString::fromStdString(trac.getdenumire());
			case 2:
				return QString::fromStdString(trac.gettip());
			case 3:
				return QString::number(trac.getnrroti());
			case 4:
				return QString::number(nrtip);
			}
		}
		if (role == Qt::BackgroundRole)
		{
			Tractor trac = tractoare.at(index.row());
			if (trac.gettip() == tip)
			{
				return QBrush(Qt::red);
			}
		}
		return QVariant{};
	}
};

class Desenare :public QWidget
{
private:
	int numar;
	QVBoxLayout* lay = new QVBoxLayout;
public:
	Desenare(int numar):numar{numar}{
		setLayout(lay);
		setFixedSize(200, 150);
		show();
	}
	void paintEvent(QPaintEvent* ev) override
	{
		QPointF punct(100, 50);
		QPainter p{ this };
		int raza = 5;
		for (int i = 0;i < numar;i++)
		{
			p.drawEllipse(punct, raza, raza);
			raza += 5;
		}
	}
	void setnr(int nr)
	{
		numar = nr;
	}
};


class GUITractor:public QWidget
{
private:
	ServiceTractor& servtractor;
	QTableView* table = new QTableView;
	MyTableModel* model = new MyTableModel(servtractor.sortbydenumire());
	void initGUI();
	void initSemnals();
	void reloadtable(vector<Tractor>);
	void reloadtablewithcolor(vector<Tractor>, string tip);
	QLineEdit* idaddline = new QLineEdit;
	QLineEdit* denumireaddline = new QLineEdit;
	QLineEdit* tipaddline = new QLineEdit;
	QLineEdit* nrrotiaddline = new QLineEdit;
	QPushButton* btnadauga = new QPushButton{"Adauga tractor"};
	QComboBox* combotip = new QComboBox;
	Desenare* desentipuri = new Desenare(0);
	void desenare(int nr);
public:
	GUITractor(ServiceTractor& servtractor) :servtractor{ servtractor } {
		initGUI();
		initSemnals();
		reloadtable(servtractor.sortbydenumire());
	}
};


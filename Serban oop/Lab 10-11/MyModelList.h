#pragma once

#include "QAbstractListModel"
#include "Masina.h"
#include <qdebug.h>
#include <vector>

using std::vector;


class MyModelListView:public QAbstractListModel {
private:
	vector<Masina> masini;
public:
	MyModelListView(const vector<Masina> masini) :masini{ masini } {

	}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		size_t lungime = masini.size();
		int lungime1 = static_cast<int>(lungime);
		return lungime1;
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 4;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole)
		{
			auto sp = masini[index.row()].getnrinmatriculare();
			return QString::fromStdString(sp);
		}
		if (role == Qt::BackgroundRole)
		{
			if (index.row() % 4 == 0)
			{
				return QBrush(Qt::red);
			}
			if (index.row()%4==1)
			{
				return QBrush(Qt::yellow);
			}
			if (index.row() % 4 == 2)
			{
				return QBrush(Qt::green);
			}
			if (index.row() % 4 == 3)
			{
				return QBrush(Qt::blue);
			}
		}
		return QVariant{};
	}
	void setMasina(const vector<Masina> masini)
	{
		this->masini = masini;
		auto topleft = createIndex(0, 0);
		size_t lungime = masini.size();
		int lungime1 = static_cast<int>(lungime);
		auto bottomright = createIndex(lungime1, 1);
		emit dataChanged(topleft, bottomright);
	}
};



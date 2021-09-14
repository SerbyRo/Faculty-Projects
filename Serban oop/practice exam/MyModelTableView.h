#pragma once
#include "QAbstractTableModel"
#include "ServiceCarte.h"

class MyModelTableView: public QAbstractTableModel
{
private:
	ServiceCarte& servcarte;
public:
	MyModelTableView(ServiceCarte& servcarte) :servcarte{ servcarte } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const
	{
		return servcarte.getAllService().size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const
	{
		return 5;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const
	{
		if (role == Qt::DisplayRole)
		{
			int row = index.row();
			int column = index.column();
			switch (column)
			{
			case 0:
				return QString(QString::number(servcarte.getAllService()[row].getid()));
			case 1:
				return QString(QString::fromStdString(servcarte.getAllService()[row].gettitlu()));
			case 2:
				return QString(QString::fromStdString(servcarte.getAllService()[row].gettip()));
			case 3:
				return QString(QString::number(servcarte.getAllService()[row].getpret()));
			case 4:
				return QString(QString::number(servcarte.getAllService()[row].gettip().size()));
			}
		}
		return QVariant{};
	}
	void setCarte(vector<Carte> carti)
	{
		QModelIndex topleft = createIndex(0, 0);
		QModelIndex bottomright = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		emit dataChanged(topleft,bottomright);
	}
};


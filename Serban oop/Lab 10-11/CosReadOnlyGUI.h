#pragma once
#include "ServiceMasina.h"
#include "qwidget.h"
#include "qboxlayout.h"
#include "Observer.h"
#include "Observable.h"
#include <qpainter.h>
class CosReadOnlyGUI:public QWidget,public Observer
{
private:
	ServiceMasina& servmasini;
public:
	CosReadOnlyGUI(ServiceMasina& servmasini) :servmasini{ servmasini } {
		servmasini.addObserver(this);
	}
	void update() override {
		repaint();
	}
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		int x = 10;
		int i = 0;
		for (const auto& mas : servmasini.getworklist())
		{
			if (i % 2 == 0)
			{
				p.drawRect(x, x, 20, 30);
				//p.drawImage(x, x, QImage("pozaoop.jpg"));
			}
			if(i % 2 == 1)
			{
				p.drawEllipse(x, x, 20, 50);
			}
			
			x = x + 40;
			i++;
		}
	}
	~CosReadOnlyGUI() {
		servmasini.removeObserver(this);
	}
};


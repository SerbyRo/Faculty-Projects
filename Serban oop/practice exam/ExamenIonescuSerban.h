#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamenIonescuSerban.h"

class ExamenIonescuSerban : public QMainWindow
{
    Q_OBJECT

public:
    ExamenIonescuSerban(QWidget *parent = Q_NULLPTR);

private:
    Ui::ExamenIonescuSerbanClass ui;
};

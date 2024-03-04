#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_types.insert("Fish", 20);
    m_types.insert("Cat", 4);
    m_types.insert("Dog", 3);
    m_types.insert("Mice", 15);

    ui->cbType->addItems(m_types.keys());
    ui->cbType->setCurrentIndex(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cbType_currentIndexChanged(int index)
{
    Q_UNUSED(index);

    int m = m_types.value(ui->cbType->currentText());
    ui->leMultiplier->setText(QString::number(m));
}


void Dialog::on_btnCalculate_clicked()
{
    bool ok = false;
    int value = ui->leValue->text().toInt(&ok);

    if (!ok)
    {
        ui->leValue->setText("0");
    }

    int multiplier = ui->leMultiplier->text().toInt(&ok);

    if (!ok)
    {
        ui->leMultiplier->setText("0");
    }

    int res = value * multiplier;
    ui->leResult->setText(QString::number(res));
}


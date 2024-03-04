#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_cbType_currentIndexChanged(int index);

    void on_btnCalculate_clicked();

private:
    Ui::Dialog *ui;
    QMap<QString, int> m_types;
};
#endif // DIALOG_H

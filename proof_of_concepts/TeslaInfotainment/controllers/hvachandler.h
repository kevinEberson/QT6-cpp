#ifndef HVACHANDLER_H
#define HVACHANDLER_H

#include <QObject>

class HVACHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int targetTemperature READ targetTemperature WRITE setTargetTemperature NOTIFY targetTemperatureChanged FINAL)

public:
    explicit HVACHandler(QObject *parent = nullptr);

    int targetTemperature() const;

    Q_INVOKABLE void changeTargetTemperature(const int &value);

public slots:
    void setTargetTemperature(int newTargetTemperature);

signals:

    void targetTemperatureChanged();

private:
    int m_targetTemperature;
};

#endif // HVACHANDLER_H

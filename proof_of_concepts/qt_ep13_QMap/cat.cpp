#include "cat.h"

Cat::Cat(QObject *parent)
    : QObject{parent}
{}

Cat::~Cat()
{
    qInfo() << this << "Deconstructed";
}

QString Cat::name() const {
    return m_name;
}

void Cat::setName(const QString &name) {
    m_name = name;
    setObjectName(name);
}

int Cat::age() const {
    return m_age;
}

void Cat::setAge(int age) {
    m_age = age;
}



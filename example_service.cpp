#include "example_service.h"

#include <QDebug>
#include <QtGlobal>


ExampleService::ExampleService() = default;

ExampleService::~ExampleService() = default;

int ExampleService::getRandomInt(int limit)
{
    return qrand() % limit;
}

QString ExampleService::printMessage(const QString& msg)
{
    qDebug().noquote() << QString("-> printMessage: '%1'").arg(msg);
    return QString("Return: '%1'").arg(msg);
}

void ExampleService::printNotification(const QString &msg) {
    qDebug().noquote() << QString("-> printNotification: '%1'").arg(msg);
}

QString ExampleService::callLsy(const QString& msg)
{
    qDebug().noquote() << QString("-> callLsy: '%1'").arg(msg);
    return QString("Return: '%1'").arg(msg);
}


QString ExampleService::getJsonData()
{
    //简单的QTJson数据
    QJsonObject simp_ayjson;
    simp_ayjson.insert("name", "LLH");
    simp_ayjson.insert("age", 20);
    simp_ayjson.insert("myAccounts", QString::fromLocal8Bit("ShenZhen.China"));
    QJsonDocument document;
    document.setObject(simp_ayjson);
    QByteArray simpbyte_array = document.toJson(QJsonDocument::Compact);
    QString simpjson_str(simpbyte_array);


    return simpjson_str;
}

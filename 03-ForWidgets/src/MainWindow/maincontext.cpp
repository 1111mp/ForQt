#include "maincontext.h"

MainContext::MainContext(const QVariantMap& info, QObject *parent)
    : m_Info(info), QObject{parent}
{

}

void MainContext::setInfo(const QVariantMap &info)
{
    foreach (auto key, info.keys()) {
        qInfo() << key << ":" << info.value(key);
    }

    m_Info = info;
    emit onInfoChanged(info);
}

void MainContext::request(qint32 id, QString message)
{
    qInfo() << "MainContext: request with id" << id;
    qInfo() << "message" << message;

    // other logic

    QVariantMap data;
    data["code"] = 200;
    data["message"] = "from native";

    emit onResponse(id, data);
}

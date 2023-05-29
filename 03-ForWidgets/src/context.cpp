#include "context.h"

Context::Context(QObject *parent)
    : QObject{parent}
{

}

void Context::onLogin(const QVariantMap &info)
{
    emit onLoginHandler(info);
}

//void Context::setInfo(const QVariantMap &info)
//{
//    foreach( auto key, info.keys())
//    {
//        qInfo() << key << ":" << info.value(key);
//    }

//    m_Info = info;

//    emit onInfoChanged(m_Info);
//}

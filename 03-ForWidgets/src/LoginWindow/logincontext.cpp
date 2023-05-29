#include "logincontext.h"

LoginContext::LoginContext(QObject *parent)
    : QObject{parent}
{

}

void LoginContext::onLogin(const QVariantMap& info)
{
    qInfo() << "Context: onLogin";

    emit onLoginHandler(info);
}

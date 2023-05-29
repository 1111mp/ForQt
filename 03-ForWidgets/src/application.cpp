#include "application.h"

Application::Application(QObject *parent)
    : QObject{parent}
{
    m_LoginContext = QSharedPointer<LoginContext>(new LoginContext(this));

    m_Login = QSharedPointer<LoginWindow>(new LoginWindow(m_LoginContext.data()));
    m_Login->show();

    QObject::connect(m_LoginContext.data(), &LoginContext::onLoginHandler, this, &Application::onLoginSuccessful);
}

Application::~Application()
{
    m_Login = nullptr;
    m_Main = nullptr;
}

void Application::onLoginSuccessful(const QVariantMap& info)
{
    qInfo() << "[Application]: onLoginSuccessful";

    m_Login->hide();

    m_MainContext = QSharedPointer<MainContext>(new MainContext(info, this));
    m_Main = QSharedPointer<MainWindow>(new MainWindow(m_MainContext.data()));
    m_Main->show();

    m_Login->close();
    m_Login = nullptr;
}

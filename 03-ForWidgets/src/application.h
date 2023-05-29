#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QSharedPointer>
#include <QVariantMap>
#include <QDebug>

#include "LoginWindow/loginwindow.h"
#include "LoginWindow/logincontext.h"
#include "MainWindow/mainwindow.h"
#include "MainWindow/maincontext.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);
    ~Application();

public slots:
    void onLoginSuccessful(const QVariantMap& info);

private:
    QSharedPointer<LoginContext> m_LoginContext = nullptr;
    QSharedPointer<LoginWindow> m_Login = nullptr;
    QSharedPointer<MainWindow> m_Main = nullptr;
    QSharedPointer<MainContext> m_MainContext = nullptr;

};

#endif // APPLICATION_H

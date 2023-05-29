#ifndef LOGINCONTEXT_H
#define LOGINCONTEXT_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>

class LoginContext : public QObject
{
    Q_OBJECT
public:
    explicit LoginContext(QObject *parent = nullptr);

public slots:
    void onLogin(const QVariantMap& info);

signals:
    void onLoginHandler(const QVariantMap& info);
};

#endif // LOGINCONTEXT_H

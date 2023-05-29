#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>
#include <QVariantMap>

class Context : public QObject
{
    Q_OBJECT

//    Q_PROPERTY(QVariantMap info MEMBER m_Info NOTIFY onInfoChanged)

public:
    explicit Context(QObject *parent = nullptr);

public slots:
    void onLogin(const QVariantMap& info);

//    void setInfo(const QVariantMap& info);

signals:
    void onLoginHandler(const QVariantMap& info);
//    void onInfoChanged(const QVariantMap& info);

//private:
//    QVariantMap m_Info;

};

#endif // CONTEXT_H

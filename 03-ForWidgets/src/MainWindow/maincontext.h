#ifndef MAINCONTEXT_H
#define MAINCONTEXT_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>

class MainContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantMap info MEMBER m_Info NOTIFY onInfoChanged)

public:
    explicit MainContext(const QVariantMap& info, QObject *parent = nullptr);

public slots:
    void setInfo(const QVariantMap& info);
    void request(qint32 id, QString message);

signals:
    void onInfoChanged(const QVariantMap& info);
    void onResponse(qint32 id, const QVariantMap& data);

private:
    QVariantMap m_Info;
};

#endif // MAINCONTEXT_H

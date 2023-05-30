#ifndef APPSCHEMEHANDLER_H
#define APPSCHEMEHANDLER_H

#include <QObject>
#include <QWebEngineUrlSchemeHandler>
#include <QWebEngineUrlRequestJob>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QScopedPointer>
#include <QDebug>

class AppSchemeHandler : public QWebEngineUrlSchemeHandler
{
    Q_OBJECT
public:
    explicit AppSchemeHandler(QObject *parent = nullptr);

    void requestStarted(QWebEngineUrlRequestJob* job) override;

public slots:
    void onFinished();
    void onDownload();

signals:

private:
    QNetworkAccessManager* m_Manager;
    QScopedPointer<QNetworkReply> m_Reply;

};

#endif // APPSCHEMEHANDLER_H

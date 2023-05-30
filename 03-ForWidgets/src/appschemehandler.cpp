#include "appschemehandler.h"

#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QMimeType>

AppSchemeHandler::AppSchemeHandler(QObject *parent)
    : QWebEngineUrlSchemeHandler{parent}
{
    m_Manager = new QNetworkAccessManager(this);
}

void AppSchemeHandler::requestStarted(QWebEngineUrlRequestJob *job)
{
    qInfo() << "method:" << job->requestMethod();

    auto url = job->requestUrl().toString();

    qInfo() << "url:" << url;

    qInfo() << job->requestHeaders();

    if(url == "app://upload-images.jianshu.io/upload_images/5809200-a99419bb94924e6d.jpg")
    {
        auto file = new QFile("./5809200-a99419bb94924e6d.jpg");

        if(file->exists())
        {
            qInfo() << "exist";
            file->setParent(job);
            file->open(QIODevice::ReadOnly);

            connect(job, &QObject::destroyed, file, &QObject::deleteLater);

            job->reply("image/webp", file);
        }
        else
        {
            auto realUrl = url.replace(0, 3, "https");
            qInfo() << "real url" << realUrl;

            QNetworkRequest request;
            request.setUrl(realUrl);

            m_Reply.reset(m_Manager->get(request));
            m_Reply->setParent(job);

            connect(m_Reply.data(), &QNetworkReply::finished, this, &AppSchemeHandler::onDownload);
        }

        file->close();
        return;
    }

    QByteArray requestMethod = job->requestMethod();
    if (requestMethod != "GET") {
        job->fail(QWebEngineUrlRequestJob::RequestDenied);
        return;
    }

    QUrl requestUrl = job->requestUrl();
    QString requestPath = requestUrl.path();
    QFile* file(new QFile(":/main.html", job));
    if (!file->exists() || file->size() == 0) {
        qWarning("QResource '%s' not found or is empty", qUtf8Printable(requestPath));
        job->fail(QWebEngineUrlRequestJob::UrlNotFound);
        return;
    }
    QFileInfo fileInfo(*file);
    QMimeDatabase mimeDatabase;
    QMimeType mimeType = mimeDatabase.mimeTypeForFile(fileInfo);

    connect(job, &QObject::destroyed, file, &QObject::deleteLater);

    if (mimeType.name() == QStringLiteral("application/x-extension-html"))
        job->reply("text/html", file);
    else
        job->reply(mimeType.name().toUtf8(), file);
}

void AppSchemeHandler::onFinished()
{
    qInfo() << "finished";

    QWebEngineUrlRequestJob *job = qobject_cast<QWebEngineUrlRequestJob *>(m_Reply->parent());

    if (!job) {
        return;
    }

    if (m_Reply->error()) {
        job->fail(QWebEngineUrlRequestJob::UrlNotFound);
        return;
    }

    QVariant contentMimeType = m_Reply->header(QNetworkRequest::ContentTypeHeader);
    QByteArray mime = contentMimeType.toByteArray();
    const int pos = mime.indexOf(';');
    if (pos != -1) {
        mime = mime.left(pos);
    }

    auto file = new QFile("./5809200-a99419bb94924e6d.jpg");
    file->setParent(job);
    file->open(QIODeviceBase::ReadOnly);
    file->close();

    connect(job, &QObject::destroyed, file, &QObject::deleteLater);

    job->reply(mime, file);
}

void AppSchemeHandler::onDownload()
{
    qInfo() << "onDownload";

    QFile file("./5809200-a99419bb94924e6d.jpg");
    file.open(QIODeviceBase::WriteOnly);
    file.write(m_Reply->readAll());
    file.close();

    onFinished();
}

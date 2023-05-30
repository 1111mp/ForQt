#include "maincontext.h"

MainContext::MainContext(const QVariantMap& info, QObject *parent)
    : m_Info(info), QObject{parent}
{

}

QFuture<qint32> MainContext::setInfo(const QVariantMap &info)
{
    foreach (auto key, info.keys()) {
        qInfo() << key << ":" << info.value(key);
    }

    QPromise<qint32> promise;
    QFuture<int> future = promise.future();

    m_Info = info;
    emit onInfoChanged(info);

    QScopedPointer<QThread> thread(QThread::create([] (QPromise<int> promise) {
                                       promise.start();   // notifies QFuture that the computation is started
                                       promise.addResult(42);
                                       QThread::sleep(5);
                                       promise.finish();  // notifies QFuture that the computation is finished
                                   }, std::move(promise)));
    thread->start();

    future.waitForFinished();  // blocks until QPromise::finish is called
    future.result();

    return future;
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

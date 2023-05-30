#include <QApplication>
#include <QWebEngineUrlScheme>
#include <QWebEngineProfile>
#include <QDir>

#include "src/application.h"
#include "src/appschemehandler.h"

int main(int argc, char *argv[])
{
    QWebEngineUrlScheme scheme("app");
    scheme.setSyntax(QWebEngineUrlScheme::Syntax::HostAndPort);
    scheme.setDefaultPort(2345);
    scheme.setFlags(
        QWebEngineUrlScheme::SecureScheme |
        QWebEngineUrlScheme::LocalAccessAllowed |
        QWebEngineUrlScheme::ViewSourceAllowed |
        QWebEngineUrlScheme::ContentSecurityPolicyIgnored |
        QWebEngineUrlScheme::CorsEnabled |
        QWebEngineUrlScheme::FetchApiAllowed); // Qt 6.6 supported
    QWebEngineUrlScheme::registerScheme(scheme);

    QApplication a(argc, argv);
    //    QApplication::setQuitOnLastWindowClosed(false);

    Application app;

    auto handler = QScopedPointer<AppSchemeHandler>(new AppSchemeHandler());
    QWebEngineProfile::defaultProfile()->installUrlSchemeHandler("app", handler.data());

    return a.exec();
}

#include "loginwindow.h"
#include "./ui_loginwindow.h"

LoginWindow::LoginWindow(LoginContext* context, QWidget *parent)
    : m_Context(context), QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "8080");

    m_WebChannel = new QWebChannel(this);
    m_WebChannel->registerObject("Context", m_Context);

    m_View = new QWebEngineView(this);
//    QString path = QCoreApplication::applicationDirPath() + "/login.html";
//    m_View->load(QUrl("file:///" + path));
    m_View->load(QUrl("qrc:/login.html"));
    m_View->page()->setWebChannel(m_WebChannel);

    setCentralWidget(m_View);
}

LoginWindow::~LoginWindow()
{
//    m_WebChannel->deregisterObject(m_Context);
    delete ui;
    m_Context = nullptr;
}

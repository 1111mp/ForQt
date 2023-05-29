#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(MainContext* context, QWidget *parent) :
    m_Context(context), QMainWindow(parent), ui(new Ui::MainWindow)
{
    //    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "8080");

    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);

    m_WebChannel = new QWebChannel(this);
    m_WebChannel->registerObject("Context", m_Context);

    m_View = new QWebEngineView(this);
    m_View->load(QUrl("qrc:/main.html"));
    m_View->page()->setWebChannel(m_WebChannel);

    setCentralWidget(m_View);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_Context = nullptr;
}

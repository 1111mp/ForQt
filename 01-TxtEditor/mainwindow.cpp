#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    m_filename = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString openFile = QFileDialog::getOpenFileName(this, "Open a file");

    if (!openFile.isEmpty())
    {
        QFile file(openFile);
        if (file.open(QIODevice::ReadOnly))
        {
            m_filename = openFile;
            QTextStream stream(&file);

            ui->textEdit->setPlainText(stream.readAll());

            file.close();
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(m_filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);

        stream << ui->textEdit->toPlainText();

        file.flush();
        file.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString chooseFile = QFileDialog::getSaveFileName(this, "Choose a file");

    if (!chooseFile.isEmpty())
    {
        m_filename = chooseFile;

        on_actionSave_triggered();
    }
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


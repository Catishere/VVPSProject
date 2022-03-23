#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->optionGroup->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chooseButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,
                                            tr("Open Excel file"),
                                            "C:/Users/vikto/Desktop",
                                            tr("Excel Files (*.xlsx)"));
    ui->fileName->setText(filePath);
    XlsxUtils xlsx(filePath);
    if (!xlsx.loaded()) {
        if (!filePath.isEmpty())
            ui->error->setText("File couldn't be opened");
        return;
    }

    users = xlsx.getUsers();
    calculateStatistics();

    ui->optionGroup->show();
}

void MainWindow::on_populationRadio_toggled(bool checked)
{
    stats.setComplete(checked);
    if (!filePath.isEmpty()) {
        calculateStatistics();
    }
}

void MainWindow::calculateStatistics()
{
    ui->average->setText(QString::number(stats.calculateAverage(users)));

    auto modes = stats.calculateMode(users);
    if (modes.isEmpty())
        ui->mode->setText("Няма");
    else {
        QString modeString;
        ui->mode->setText(modeString);
        for (auto mode : modes) {
            modeString += QString::number(mode) + ' ';
        }
    }

    ui->median->setText(QString::number(stats.calculateMedian(users)));
    ui->variance->setText(QString::number(stats.calculateVariance(users)));
    ui->deviation->setText(QString::number(stats.calculateDeviation(users)));
    ui->scope->setText(QString::number(stats.calculateScope(users)));
}


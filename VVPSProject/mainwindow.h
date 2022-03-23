#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "xlsxutils.h"
#include "statisticsutils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class UITest;

    QString filePath;
    QList<int> users;
    StatisticsUtils stats;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_chooseButton_clicked();
    void on_populationRadio_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    void calculateStatistics();
};
#endif // MAINWINDOW_H

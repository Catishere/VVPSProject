#include <QtTest>
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
// add necessary includes here

class UITest : public QObject
{
    Q_OBJECT

    friend class MainWindow;

    MainWindow* mainWindow;

public:
    UITest();
    ~UITest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testLoadWrongFile();
    void testUILoadFile();
    void testResultsSample();
    void testResultsComplete();
};

UITest::UITest()
{

}

UITest::~UITest()
{

}

void UITest::initTestCase()
{
    mainWindow = new MainWindow();
    mainWindow->show();
}

void UITest::testUILoadFile()
{
    mainWindow->on_chooseButton_clicked();
    QCOMPARE(mainWindow->ui->fileName->text(),
             "C:/Users/vikto/Desktop/Logs_Course A_StudentsActivities.xlsx");
}

void UITest::testResultsSample()
{
    mainWindow->on_populationRadio_toggled(false);
    QCOMPARE(mainWindow->ui->scope->text(), "576");
    QCOMPARE(mainWindow->ui->mode->text(), "8422");
    QCOMPARE(mainWindow->ui->median->text(), "8413");
    QCOMPARE(mainWindow->ui->average->text(), "8374.23");
    QCOMPARE(mainWindow->ui->variance->text(), "19890.2");
    QCOMPARE(mainWindow->ui->deviation->text(), "141.033");
}

void UITest::testResultsComplete()
{
    mainWindow->on_populationRadio_toggled(true);
    QCOMPARE(mainWindow->ui->scope->text(), "576");
    QCOMPARE(mainWindow->ui->median->text(), "8413");
    QCOMPARE(mainWindow->ui->mode->text(), "8422");
    QCOMPARE(mainWindow->ui->average->text(), "8374.23");
    QCOMPARE(mainWindow->ui->variance->text(), "19855.7");
    QCOMPARE(mainWindow->ui->deviation->text(), "140.91");
}

void UITest::cleanupTestCase()
{
    delete mainWindow;
}

void UITest::testLoadWrongFile()
{
    mainWindow->on_chooseButton_clicked();
    QVERIFY(!mainWindow->ui->error->text().isEmpty());
}

QTEST_MAIN(UITest)

#include "tst_uitest.moc"

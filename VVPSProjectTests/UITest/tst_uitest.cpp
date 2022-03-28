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
    void testUILoadFile();
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
    QVERIFY(true);
}

void UITest::cleanupTestCase()
{
    delete mainWindow;
}

QTEST_MAIN(UITest)

#include "tst_uitest.moc"

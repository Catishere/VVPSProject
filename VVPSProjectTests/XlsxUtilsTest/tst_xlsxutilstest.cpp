#include <QtTest>

#include "xlsxutils.h"

class XlsxUtilsTest : public QObject
{
    Q_OBJECT

public:
    XlsxUtilsTest();
    ~XlsxUtilsTest();

private slots:
    void testLoad();
    void testGetUsers();

};

XlsxUtilsTest::XlsxUtilsTest()
{

}

XlsxUtilsTest::~XlsxUtilsTest()
{

}

void XlsxUtilsTest::testLoad()
{
    XlsxUtils xlsx(":/test.xlsx");
    QVERIFY(xlsx.loaded());
    XlsxUtils xlsx2("./Makefile");
    QCOMPARE(xlsx2.loaded(), false);
    QCOMPARE(xlsx2.getUsers().size(), 0);
}

void XlsxUtilsTest::testGetUsers()
{
    XlsxUtils xlsx(":/test.xlsx");
    QCOMPARE(xlsx.getUsers().size(), 25);
}

QTEST_APPLESS_MAIN(XlsxUtilsTest)

#include "tst_xlsxutilstest.moc"

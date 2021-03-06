#pragma once

#include <QObject>
#include <QList>
#include <QDir>
#include <QFile>
#include <QUuid>
#include <QDateTime>
#include <QMap>


bool rmTree(QString completePath);

class TestBase : public QObject
{
    Q_OBJECT

protected:
    QString m_tempPath;
    QMap<QString, quint64> selfCreateEvents;
    void createTemporaryDirectory();
    QString createRandomFile(int size=4096);
    QString createRandomFile(bool randomParent, int size=4096);
    virtual void stopTest(bool passed);

public:
    //virtual TestBase(QObject *parent) = 0;
    virtual void setUp() = 0;
    virtual void tearDown() = 0;
    virtual void runTest() = 0;

public slots:
    virtual void stopTest() = 0;
    
signals:
    void testStop(TestBase*, bool);
};


class TestRunner: public QObject
{
    Q_OBJECT

    int m_current;
    int m_passed;
    QList<TestBase*> m_tests;
    void runNextTest();

private slots:
    void testResult(TestBase* test, bool result);


public:
    TestRunner();
    TestRunner& operator<<(TestBase*);
    void run();


};

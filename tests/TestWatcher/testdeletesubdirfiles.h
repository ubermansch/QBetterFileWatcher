#pragma once
#include <QDir>
#include <QBetterFileWatcher>
#include <QTimer>
#include <QDateTime>
#include "testbase.h"

class DeleteSubdirFilesTestCase : public TestBase
{
    Q_OBJECT
    QBetterFileWatcher* m_fwatcher;
    bool m_running;
    QTimer timeout;
public:
    QMap<QString, quint64> deltaEvents;
    int delEvents;
    explicit DeleteSubdirFilesTestCase();
    void setUp();
    void tearDown();
    void runTest();
    
signals:
    
public slots:
   void onFileDeleted(QString path);
   void stopTest();
};


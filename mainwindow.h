/*
    Copyright 2012 Dario Casalinuovo. All rights reserved.

    This file is part of CDRipper.

    Faber is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Faber is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CDRipper.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qfile.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QDesktopServices>
#include <QThread>
#include <QProcess>

namespace Ui {
    class MainWindow;
}

class Project;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void start();
    void stop();
    void cleanAll();
    void rename();
    void cdparanoia();

    void upFile();
    void upRippedFile();

    void downFile();
    void downRippedFile();

    void addFile();
    void addRippedFile();

    void removeFile();
    void removeRippedFile();

    void newProject();
    void saveProject();
    void loadProject();

    void settings();
    void readFromStderr();
    void readFromStdout();
    void dfinish();
    void dreadFromStderr();
    void dreadFromStdout();

    void paranoiaFinish();
    void convertFinish();
    void _calculateDuration();

    void _calculate(int);

private:
    bool _checkSave();
    QString _renameFile(QString name, int i, QDir& dir);
    void _launchCmd(QString command);
    QString _convertMp3(QString path, QString filename);
    QString _copyWav(QString path, QString filename);
    void _setDuration();
    void slotProcessError(QProcess::ProcessError error);

    Ui::MainWindow* ui;
    //bool sem;
    bool saved;
    QString albumName;
    QString saveDir;
    QString projDir;
    QString destDir;
    Project* projectFile;

    QProcess* process;
    QProcess* durProc;
    bool cfinished;
    int calcIndex;
    int totalDuration;
};

/*
class CmdThread : public QThread
{
    Q_OBJECT
public:
    CmdThread(QString f, MainWindow* window, Ui::MainWindow* interface)
        : stop(false), file(f), win(window), ui(interface) { }
    bool stop;
    void Stop();
public slots:
        void readFromStdout();
protected:
    void run();
private:
QString file;
MainWindow  *win;
Ui::MainWindow *ui;
int pID;

};
*/
#endif // MAINWINDOW_H

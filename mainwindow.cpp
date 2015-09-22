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
#include <stdio.h>
#include <QFileDialog>
#include <QDesktopServices>
#include <QProcess>
#include <QMessageBox>
#include <signal.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "project.h"

const char* kPrefix = "/opt/local/bin/";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    saved(false),
    projectFile(NULL),
    process(NULL),
    cfinished(true),
    totalDuration(0)
    //proc(NULL)
{
    printf("Start window\n");
    ui->setupUi(this);

    // Menus
    ui->actionExit->setShortcuts(QKeySequence::Quit);
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->actionAddfile, SIGNAL(triggered()), this, SLOT(addFile()));
    connect(ui->actionAddripped, SIGNAL(triggered()), this, SLOT(addRippedFile()));

    connect(ui->actionNewProject, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveProject()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadProject()));

    connect(ui->actionCDTracks, SIGNAL(triggered()), this, SLOT(cdparanoia()));

    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(start()));
    connect(ui->actionStop, SIGNAL(triggered()), this, SLOT(stop()));

    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(settings()));

    // Buttons
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stop()));

    connect(ui->removeFile, SIGNAL(clicked()), this, SLOT(removeFile()));
    connect(ui->removeRippedFile, SIGNAL(clicked()), this, SLOT(removeRippedFile()));
    connect(ui->upFile, SIGNAL(clicked()), this, SLOT(upFile()));
    connect(ui->upRippedFile, SIGNAL(clicked()), this, SLOT(upRippedFile()));
    connect(ui->downFile, SIGNAL(clicked()), this, SLOT(downFile()));
    connect(ui->downRippedFile, SIGNAL(clicked()), this, SLOT(downRippedFile()));
    connect(ui->durationButton, SIGNAL(clicked()), this, SLOT(_calculateDuration()));

    
    connect(ui->manualRename, SIGNAL(clicked()), this, SLOT(rename()));
    connect(ui->cleanAll, SIGNAL(clicked()), this, SLOT(cleanAll()));

    /* Files views */
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList labels;
    labels << "File Name";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setShowGrid(false);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_2->setHorizontalHeaderLabels(labels);
    ui->tableWidget_2->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->setShowGrid(false);

    cfinished = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::start()
{
    if (!_checkSave())
        return;

    QString filesPath = destDir;
    QDir dir(projDir);
    dir.mkdir(filesPath);

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        sleep(3);
        QTableWidgetItem* item = ui->tableWidget->item(i, 0);
        QString file = item->text();
        int l = file.lastIndexOf("/");
        QString filename = file.mid(l+1);
        l = filename.lastIndexOf(".");
        printf("%s\n", filename.toStdString().c_str());
        QString ext = filename.mid(l+1, 3);
        printf("%s\n", ext.toStdString().c_str());
        if (ext == "mp3") {
            QString s = ".wav";
            filename.replace(l, s.length(), s);
            QDir filePath = destDir+filename;
            printf("%s\n", filePath.path().toStdString().c_str());
            _convertMp3(file, filePath.path());
            ui->tableWidget->removeRow(i);

            QTableWidgetItem* newItem = new QTableWidgetItem(filePath.path());
            newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);
            ui->tableWidget_2->setItem(row, 0, newItem);
        } else if (ext  == "wav") {
            ui->tableWidget->removeRow(i);
            QDir filePath = destDir+filename;
            printf("%s\n", filePath.path().toStdString().c_str());
            _copyWav(file, filePath.path());
            QTableWidgetItem* newItem = new QTableWidgetItem(filePath.path());
            newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);
            ui->tableWidget_2->setItem(row, 0, newItem);
        }
        i = i-1;
    }

    if (ui->autoRename->checkState() == 2)
       rename();
}

void MainWindow::stop()
{
    printf("stop\n");
    if (!_checkSave())
        return;

    process->kill();

    ui->textBrowser->append("Stopped CDParanoia\n");
    ui->textBrowser->moveCursor(QTextCursor::EndOfBlock, QTextCursor::MoveAnchor);
}

void MainWindow::cleanAll()
{
    int count = ui->tableWidget->rowCount();
    for (int i = 0; i < count; i++) {
        ui->tableWidget->removeRow(0);
    }
    count = ui->tableWidget_2->rowCount();
    for (int i = 0; i < count; i++) {
        ui->tableWidget_2->removeRow(0);
    }
    ui->albumName->clear();
    ui->textBrowser->clear();
}

void MainWindow::rename()
{
    if (!_checkSave())
        return;

    QDir dir(destDir);
    printf("1\n");
   for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
        QTableWidgetItem* item = ui->tableWidget_2->item(i, 0);

        QString rename = _renameFile(item->text(),i, dir);
        printf("%s\n", rename.toStdString().c_str());
        item->setText(rename);
     }
}

QString MainWindow::_renameFile(QString name, int i, QDir& dir)
{
    QString ren = name;
    QString y = "/";
    int cindex = ren.lastIndexOf(y);
    QString str = "/"+ui->albumName->text();
    str += "_1_"+QString::number(i+1)+".wav";
    ren.replace(cindex, ren.length(), "");
    ren.replace(cindex, str.length(), str);
    dir.rename(name, ren);

    printf("%s\n", ren.toStdString().c_str());
    return ren;
}

void MainWindow::upFile()
{
    int current = ui->tableWidget->currentRow();
    if (current == 0)
        return;

    QTableWidgetItem* item = ui->tableWidget->takeItem(current, 0);
    ui->tableWidget->removeRow(current);
    ui->tableWidget->insertRow(current-1);
    ui->tableWidget->setItem(current-1, 0, item);
    ui->tableWidget->selectRow(current-1);
}

void MainWindow::upRippedFile()
{
    int current = ui->tableWidget_2->currentRow();
    if (current == 0)
        return;

    QTableWidgetItem* item = ui->tableWidget_2->takeItem(current, 0);
    ui->tableWidget_2->removeRow(current);
    ui->tableWidget_2->insertRow(current-1);
    ui->tableWidget_2->setItem(current-1, 0, item);
    ui->tableWidget_2->selectRow(current-1);
}

void MainWindow::downFile()
{
    int current = ui->tableWidget->currentRow();
    if (current+1 == ui->tableWidget->rowCount())
        return;

    QTableWidgetItem* item = ui->tableWidget->takeItem(current, 0);
    ui->tableWidget->removeRow(current);
    ui->tableWidget->insertRow(current+1);
    ui->tableWidget->setItem(current+1, 0, item);
    ui->tableWidget->selectRow(current+1);
}
void MainWindow::downRippedFile()
{

    int current = ui->tableWidget_2->currentRow();
    if (current+1 == ui->tableWidget_2->rowCount())
        return;

    QTableWidgetItem* item = ui->tableWidget_2->takeItem(current, 0);
    ui->tableWidget_2->removeRow(current);
    ui->tableWidget_2->insertRow(current+1);
    ui->tableWidget_2->setItem(current+1, 0, item);
    ui->tableWidget_2->selectRow(current+1);
}

void MainWindow::addFile()
{
    QString str;
    if (saveDir == "")
        str = QDesktopServices::storageLocation(QDesktopServices::DesktopLocation);
    else
        str = saveDir;

    QStringList files = QFileDialog::getOpenFileNames(this, "Select Files",
         str, "Audio Files (*.wav *.mp3)" );

    QStringList list = files;
    QStringList::Iterator it = list.begin();
    while(it != list.end()) {
        QString str = it[0];
        printf("%s\n", str.toStdString().c_str());

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(str);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, fileNameItem);
        ++it;
    }
}

void MainWindow::addRippedFile()
{
    QString str;
    if (saveDir == "")
        str = QDesktopServices::storageLocation(QDesktopServices::DesktopLocation);
    else
        str = saveDir;

    QStringList files = QFileDialog::getOpenFileNames(this, "Select Files",
         str, "Audio Files (*.wav)" );

    if (files.isEmpty())
        return;

    QStringList list = files;
    QStringList::Iterator it = list.begin();
    while(it != list.end()) {
        QString str = it[0];
        printf("%s\n", str.toStdString().c_str());

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(str);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);

        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, fileNameItem);
        ++it;
    }
}

void MainWindow::removeFile()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}
void MainWindow::removeRippedFile()
{
    ui->tableWidget_2->removeRow(ui->tableWidget_2->currentRow());
}

void MainWindow::saveProject()
{

    if (ui->albumName->text() == "") {
        QMessageBox msgBox;
        msgBox.setText("Set the album name before to save");
        msgBox.exec();
        return;
    }

    if (albumName != ui->albumName->text()) {
        QString str;
        if (saveDir == "") {
            str = QDesktopServices::storageLocation(QDesktopServices::DesktopLocation);
            saveDir = str;
        } else {
            str = saveDir;
        }
        QString save = QFileDialog::getExistingDirectory(this, "Select a Directory", str);

        if (save == "")
            return;

        saveDir = save;
        albumName = ui->albumName->text();
    }

    projDir = saveDir+"/"+albumName+"/";
    destDir = projDir+"/converted/";

    printf("%s\n", projDir.toStdString().c_str());
    QDir dir(saveDir);
    dir.mkdir(projDir);

    if (projectFile == NULL)
        projectFile = new Project(new QFile(projDir+"/"+albumName), albumName);
    else
        projectFile->reset();

    projectFile->setAlbumName(ui->albumName->text());

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
         QTableWidgetItem* item = ui->tableWidget->item(i, 0);
         projectFile->addTrack(item->text());
     }

    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
         QTableWidgetItem* item = ui->tableWidget_2->item(i, 0);
         projectFile->addConvertedTrack(item->text());
     }

    projectFile->save();

    saved = true;
}

void MainWindow::loadProject()
{
    cleanAll();
    QString str;
    if (saveDir == "") {
        str = QDesktopServices::storageLocation(QDesktopServices::DesktopLocation);
    } else {
        str = saveDir;
    }

    QString save = QFileDialog::getExistingDirectory(this, "Select a Directory", str);

    if (save == "")
        return;

    projDir = save;
    int l = save.lastIndexOf("/");
    save.remove(l, save.count()-l);
    saveDir = save;
    destDir = projDir+"/converted/";

    l = projDir.lastIndexOf("/");
    albumName = projDir.mid(l);

    printf("%s\n", saveDir.toStdString().c_str());
    projectFile = new Project(new QFile(projDir+"/"+albumName), albumName);

    projectFile->load();
    albumName = projectFile->albumName;

    ui->albumName->setText(projectFile->albumName);

    QStringListIterator tracks(projectFile->trackList);
    while (tracks.hasNext()) {        
        QTableWidgetItem *fileNameItem = new QTableWidgetItem(tracks.next().toLocal8Bit().constData());
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, fileNameItem);
    }

    QStringListIterator convTracks(projectFile->convTrackList);
    while (convTracks.hasNext()) {
        QTableWidgetItem *fileNameItem = new QTableWidgetItem(convTracks.next().toLocal8Bit().constData());
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, fileNameItem);
    }

    saved = true;
}

void MainWindow::newProject()
{
    MainWindow* win = new MainWindow();
    win->show();
}

void MainWindow::settings()
{
    printf("settings\n");
}

void MainWindow::cdparanoia()
{
    if (!_checkSave())
        return;

    QString filesPath = destDir;

    QDir dir(saveDir);
    dir.mkdir(filesPath);
    dir = QDir(filesPath);

    int val = rand();

    process = new QProcess();
    process->setReadChannel(QProcess::StandardOutput);

    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(readFromStderr()));
    connect(process, SIGNAL(finished(int)), this, SLOT(paranoiaFinish()));

    QString str = kPrefix;
    _launchCmd(str+"cdparanoia -B 1:- --stderr-progress --output-wav "+filesPath+QString::number(val%100)+".wav");
}

void MainWindow::paranoiaFinish()
{
    QString filesPath = destDir;

    printf("%s\n", filesPath.toStdString().c_str());
    QDir dir(filesPath);
    QStringList filters ("*.wav");
    QFileInfoList list = dir.entryInfoList (filters);

    printf("%s\n", filesPath.toStdString().c_str());
    for (int i = 0; i < list.size(); ++i) {
            QFileInfo fInfo = list.at(i);
            QString fPath = fInfo.absoluteFilePath();
            bool exist = false;
            for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
                 QTableWidgetItem* item = ui->tableWidget_2->item(i, 0);
                 if (fPath == item->text()) {
                     exist = true;
                     break;
                 }
             }
            if (exist)
                continue;

            QTableWidgetItem *fileNameItem = new QTableWidgetItem(fPath);
            fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);

            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);
            ui->tableWidget_2->setItem(row, 0, fileNameItem);
    }

    if (ui->autoRename->checkState() == 2)
       rename();
}

void MainWindow::convertFinish()
{
    printf("finish convert\n");
}

QString MainWindow::_convertMp3(QString path, QString filename)
{
    process = new QProcess();
    // process->setReadChannel(QProcess::StandardOutput);
    path.replace("'","\\\'");
    path.replace("\"","\\\"");
    path.replace(" ","\\ ");
    path.replace("(","\\(");
    path.replace(")","\\)");
    filename.replace("'","\\\'");
    filename.replace("\"","\\\"");
    filename.replace(" ","\\ ");
    filename.replace("(","\\(");
    filename.replace(")","\\)");
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(readFromStderr()));
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromStdout()));
    connect(process, SIGNAL(finished(int)), this, SLOT(convertFinish()));
    QString str = kPrefix;
    str += "mpg123 -v -w "+filename+" "+path;
    printf("%s\n", str.toStdString().c_str());
    //_launchCmd(str);
    system(str.toStdString().c_str());
    return filename;
}

QString MainWindow::_copyWav(QString path, QString filename)
{
    process = new QProcess();
    //process->setReadChannel(QProcess::StandardOutput);
    path.replace("'","\\\'");
    path.replace("\"","\\\"");
    path.replace(" ","\\ ");
    path.replace("(","\\(");
    path.replace(")","\\)");
    filename.replace("'","\\\'");
    filename.replace("\"","\\\"");
    filename.replace(" ","\\ ");
    filename.replace("(","\\(");
    filename.replace(")","\\)");
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(readFromStderr()));
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromStdout()));
    connect(process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(slotProcessError(QProcess::ProcessError)));
    QString str = "/bin/cp "+path+" "+filename;
    printf("%s\n", str.toStdString().c_str());
  //  system(str.toStdString().c_str());
    _launchCmd(str);
    return filename;
}

void MainWindow::_calculateDuration()
{
        totalDuration = 0;
        calcIndex = 0;

        printf("%d\n", calcIndex);

        cfinished = false;
        _calculate(calcIndex);
}


void MainWindow::_calculate(int i)
{
    QTableWidgetItem* item = ui->tableWidget_2->item(i, 0);
    durProc = new QProcess();
    connect(durProc, SIGNAL(readyReadStandardError()), this, SLOT(dreadFromStderr()));
    connect(durProc, SIGNAL(readyReadStandardOutput()), this, SLOT(dreadFromStdout()));
    connect(durProc, SIGNAL(finished(int)), this, SLOT(dfinish()));
    QString prefix = kPrefix;
    prefix +="mplayer -frames 0 -identify \"";
    QString str = item->text();
    str+="\"";
    /*path.replace("\"","\\\"");
    path.replace("'","\\\'");
    path.replace(" ","\\ ");
    path.replace("(","\\(");
    path.replace(")","\\)");*/
    //printf("%s\n", dir.absoluteFilePath().toStdString().c_str());
    durProc->start(prefix+str);
}

void MainWindow::dfinish()
{
    printf("calc finish\n");
    calcIndex += 1;
    if (calcIndex < ui->tableWidget_2->rowCount()) {
        _calculate(calcIndex);
    } else {
        ui->durationView->display(totalDuration);
        printf("duration %d\n", totalDuration);
    }
}

void MainWindow::dreadFromStderr()
{/*
    QString str = durProc->readAllStandardError();
    //printf("%s\n", str.toStdString().c_str());
    ui->textBrowser->append(str);
    ui->textBrowser->moveCursor(QTextCursor::EndOfBlock, QTextCursor::MoveAnchor);*/
}

void MainWindow::dreadFromStdout()
{
    QString str = durProc->readAllStandardOutput();
    //printf("%s\n", str.toStdString().c_str());
    int a = str.lastIndexOf("ID_LENGTH=");
    a+=10;
    if (a != -1) {
        QString dur;
        for (int i = a; i < str.size(); ++i) {
            if (str.at(i) == QChar('\n'))
                break;
            dur.append(str.at(i));
        }
        dur.remove(".00");
        totalDuration += dur.toInt()/60;
        printf("%s %d\n", dur.toStdString().c_str(), totalDuration);
    }
    ui->textBrowser->append(str);
    ui->textBrowser->moveCursor(QTextCursor::EndOfBlock, QTextCursor::MoveAnchor);
}

void MainWindow::_setDuration()
{

}

bool MainWindow::_checkSave()
{
    if (!saved) {
        QMessageBox msgBox;
        msgBox.setText("Save the project first");
        msgBox.exec();
    }
    printf("saved checked\n");
    return saved;
}

void MainWindow::_launchCmd(QString command)
{
    process->start(command);
}

void MainWindow::readFromStderr()
{
    QString str = process->readAllStandardError();
    if (str.contains("##: -2 [wrote]"))
        return;
    if (str.contains("##: 0 [read]"))
        return;
    printf("%s\n", str.toStdString().c_str());
    ui->textBrowser->append(str);
    ui->textBrowser->moveCursor(QTextCursor::EndOfBlock, QTextCursor::MoveAnchor);
    printf("received\n");
}

void MainWindow::readFromStdout()
{
    QString str = process->readAllStandardOutput();
    if (str.contains("##: -2 [wrote]"))
        return;
    if (str.contains("##: 0 [read]"))
        return;
    printf("%s\n", str.toStdString().c_str());
    ui->textBrowser->append(str);
    ui->textBrowser->moveCursor(QTextCursor::EndOfBlock, QTextCursor::MoveAnchor);
    printf("received\n");
}

void MainWindow::slotProcessError(QProcess::ProcessError error)
{
    switch (error) {
        case QProcess::FailedToStart :
           ui->textBrowser->append(trUtf8("The process failed to start. Either the invoked program is missing, or you may have insufficient permissions to invoke the program."));
            break;
    case QProcess::Crashed :
       ui->textBrowser->append(trUtf8("An error crashed the subprocess."));
        break;
    }
}

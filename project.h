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
#ifndef PROJECT_H
#define PROJECT_H

#include <QFile>
#include <QString>
#include <QStringList>

class Project {
public:
    Project(QFile* file, QString proj);
    ~Project();

    void load();
    bool save();

    void setAlbumName(QString name);

    void addTrack(QString track);
    void addConvertedTrack(QString track);
    void cleanUp();
    void reset();
//private:
    QFile* pFile;
    //QString projName;
    QString albumName;
    QStringList trackList;
    QStringList convTrackList;
};

#endif // PROJECT_H

/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#include <QThread>
#include <QProcess>

class RecordProcess : public QThread
{
    Q_OBJECT
    
    
public:
    static const int RECORD_TYPE_VIDEO = 0;
    static const int RECORD_TYPE_GIF = 1;
    
    RecordProcess(QObject *parent = 0);
    
    void setRecordInfo(int recordX, int recordY, int record_width, int recordHeight, QString areaName);
    void setRecordType(int recordType);
    void stopRecord();
    void recordGIF();
    void recordVideo();
    void initProcess();

protected:
    void run();

private:
    QProcess* process;

    int recordX;
    int recordY;
    int recordWidth;
    int recordHeight;
    int recordType;
    
    QString savePath;
    QString saveBaseName;
    QString saveTempDir;
    QString saveDir;
    QString saveAreaName;
};

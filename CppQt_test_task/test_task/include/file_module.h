#ifndef FILEMODULE_H
#define FILEMODULE_H

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QDate>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>


class FileModule : public QObject {
    Q_OBJECT
public:
    explicit FileModule(QObject *parent = nullptr);

public slots:
    void setDirPath(QString dir_path);
    void setFilePath(QString file_path);
    QString getDirPath() const {return dir_path_;};
    void setTime(int time);
    void setDistance(int distance);
    void seveResult();

signals:
    void appendNotify(QString message);
    void setPreviousTime(int time);
    void setPreviousResult(int distance);
private:
    QString dir_path_ = "";
    QString distance_ = "";
    QString time_ = "";
};

#endif // FILEMODULE_H

#include "file_module.h"

FileModule::FileModule(QObject *parent) : QObject(parent) {

}

void FileModule::setDirPath(QString dir_path) {
    dir_path.remove("file://");
    dir_path_ = dir_path;
}

void FileModule::setFilePath(QString file_path) {
    file_path.remove("file://");
    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream text_stream(&file);
        QString first_line = text_stream.readLine();
        QString second_line = text_stream.readLine();
        if (!first_line.contains("time=")
                or !second_line.contains("distance=")) {
            emit appendNotify("Неверный файл");
            file.close();
            return;
        }
        first_line.remove("time=");
        second_line.remove("distance=");
        if (first_line.isEmpty()) {
            emit setPreviousTime(0);
        } else
            emit setPreviousTime(first_line.toInt());

        if (second_line.isEmpty()) {
            emit setPreviousResult(0);
        } else
            emit setPreviousResult(second_line.toInt());

        file.close();
        return;
    }
    emit appendNotify("Невзможно открыть файл");
}

void FileModule::setTime(int time) {
    time_ = QString::number(time);
}

void FileModule::setDistance(int distance) {
    distance_ = QString::number(distance);
}

void FileModule::seveResult() {
    // Строка с текущими датой и временем
    QString datetime_string(QDateTime::currentDateTime().
                            toString("yyyy-MM-dd_hh:mm:ss"));
    // Создаем файл в папке
    QString file_path = dir_path_ + "/" + datetime_string +".txt";
    QFile result_file(file_path);
    // Открываем файл
    if (result_file.open(QIODevice::WriteOnly)) {
      // Создаём текстовый поток, в который будем писать данные
      QTextStream textStream(&result_file);

      textStream << "time=" + time_ + "\n";
      textStream << "distance=" + distance_ + "\n";

      result_file.close();
      qDebug() << "Результыты сохранены в" << file_path;
      return;
    }
    emit appendNotify("Невозможно сохранить файл");
}

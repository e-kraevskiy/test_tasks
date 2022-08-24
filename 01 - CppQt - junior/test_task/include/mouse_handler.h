#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <iostream>
#include <cmath>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QDebug>

class MouseHandler : public QObject {
    Q_OBJECT
    Q_PROPERTY(int distance MEMBER distance_ NOTIFY updateDistance)
    Q_PROPERTY(int time MEMBER time_ NOTIFY updateTime)
public:
    explicit MouseHandler(QObject *parent = nullptr);

    void writeTimeToFile();


public slots:
    void setTime(int time);
    void setDistance(int distance);
    void startTimer();
    bool isTimerRunning();
    void calcMouseDist(int x, int y);
    void initMousePos(int x, int y);

signals:
    void updateDistance(int distance);
    void updateTimeLeft(float time_left);
    void updateTime(int time);

private:
    QTimer timer_;
    bool timer_running_ = false;
    int distance_ = 0;
    int time_ = 0;
    float time_left_ = 0;
    int x_mouse_;
    int y_mouse_;
};

#endif // MOUSEHANDLER_H

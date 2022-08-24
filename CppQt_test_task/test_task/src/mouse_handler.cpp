#include "mouse_handler.h"

MouseHandler::MouseHandler(QObject *parent) : QObject(parent) {
    timer_.setSingleShot(true);
}

void MouseHandler::setTime(int time) {
    time_ = time;
    timer_.setInterval(time * 1000);
//    qDebug() << "time = " << time;
    emit updateTime(time);
}

void MouseHandler::setDistance(int distance) {
    distance_ = distance;
//    qDebug() << "distance = " << distance_;
    emit updateDistance(distance_);
}

void MouseHandler::startTimer() {
    timer_.start();
    timer_running_ = true;
}

bool MouseHandler::isTimerRunning() {
    if (!timer_.isActive()) {
        emit updateTimeLeft(0);
        timer_running_ = false;
        distance_ = 0;
        return false;
    }
    emit updateTimeLeft(timer_.remainingTime() / 1000.0);
    return true;
}

void MouseHandler::initMousePos(int x, int y) {
    distance_ = 1;
    x_mouse_ = x;
    y_mouse_ = y;
}

void MouseHandler::calcMouseDist(int x, int y) {
    int x_diff = std::abs(x - x_mouse_);
    int y_diff = std::abs(y - y_mouse_);
    x_mouse_ = x;
    y_mouse_ = y;
    int dist = (int)std::sqrt(x_diff * x_diff + y_diff * y_diff);
    distance_ += dist;
    emit updateDistance(distance_);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

//#include "my_qlabel.h"

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidgetWindow *parent = 0);

    ~MainWindow();
    void SetupGame();

private slots:
    void TimerTick();
    void ButtonClicked();
    void Mouse_Pressed();

private:
    Ui::MainWindow *ui;
    int matchesFound;
    int tensthsOfSecondsElapsed;
    QTimer* timer;
    QPushButton* lastEmojiClicked;
    bool finding_match;
};
#endif // MAINWINDOW_H

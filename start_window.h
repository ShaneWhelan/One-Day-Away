#ifndef START_WINDOW_H
#define START_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "game_window.h"


namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();
    gamewindow game;
    
private slots:
    void startGameEasyClicked();
    void startGameHardClicked();

private:
    Ui::StartWindow *ui;
};

#endif // START_WINDOW_H

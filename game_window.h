#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "command.h"
#include "command_words.h"
#include "engine.h"
#include "item.h"
#include "player.h"

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QKeyEvent>
#include <QIcon>
#include <QSplashScreen>
#include <QScrollBar>
#include <string>
#include <algorithm>
#include <sstream>
#include <QPixmap>
#include <QDebug>
#include <QSound>
#include <QApplication>
#include <QDesktopWidget>

using namespace std;

namespace Ui {
class gamewindow;
}

class gamewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();
    void setDifficultyHard(bool difficultyHard);

private slots:
    void userInputReturnPressed();
    void infoButtonClicked();
    void mapClicked();
    void northButtonClicked();
    void southButtonClicked();
    void eastButtonClicked();
    void westButtonClicked();
    void itemInRoomIsClicked(QListWidgetItem * item);
    void itemInInventoryIsClicked(QListWidgetItem * item);
    void takeItemIsClicked();
    void dropItemIsClicked();
    void resetGameIsClicked();
    void textBasedSelected(int tabNumber);
    void keyReleaseEvent(QKeyEvent * event);
    void toggleSound(bool soundDisabled);
    void toggleFullScreen(bool fullScreenEnabled);
    void changeEvent(QEvent *event);

private:
    Ui::gamewindow *ui;
    bool difficultyHard;
    bool soundDisabled;
    bool isGameOver;
    int tabSelected;
    void updateGameText(string userCommand, QString gameOutput);
    void refreshAllItems();
    void gameState(bool isGameOver);
    void addToCommandHistory(QString command);
    void displayCommandHistory(string key);
    vector<QString> commandHistory;
    int commandHistoryIndex;
    Engine *eng = new Engine();
    QIcon north;
    QIcon south;
    QIcon east;
    QIcon west;
    QWidget map;
    QPixmap *sittingRoom;
    QPixmap *kitchen;
    QPixmap *bedroom;
    QPixmap *hallway;
    QPixmap *office;
    QPixmap *ensuite;
    QPixmap *diningRoom;
    QPixmap *garage;
    QPixmap *exitWin;
    QPixmap *exitLoose;
    QSound *mapSound;
    QSound *doorClose;
    QSound *doorCreaking;
    QSound *winFreedom;
};

#endif // GAME_WINDOW_H

#include "start_window.h"
#include "ui_startwindow.h"
#include <Qt>

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow){
    ui->setupUi(this);
    ui->gameLogo->setPixmap(QPixmap(":/images/misc/logo.png"));
    ui->centralwidget->setStyleSheet("QWidget{background-color: #555555;}");
    ui->startGameEasy->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/easy.png);border:0px;}"
                                     "QPushButton:hover{border-image:url(:/images/actionbuttons/easy_mouse_over.png);border:0px}"
                                     "QPushButton:pressed{border-image:url(:/images/actionbuttons/easy_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->startGameHard->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/hard.png);border:0px;}"
                                     "QPushButton:hover{border-image:url(:/images/actionbuttons/hard_mouse_over.png);border:0px}"
                                     "QPushButton:pressed{border-image:url(:/images/actionbuttons/hard_pressed.png); position: relative;top: 1px; left: 1px;}");
    connect(ui->startGameEasy, SIGNAL(clicked()), this, SLOT(startGameEasyClicked()));
    connect(ui->startGameHard, SIGNAL(clicked()), this, SLOT(startGameHardClicked()));
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::startGameEasyClicked(){
    game.setDifficultyHard(0);
    game.show();
    QSplashScreen *splash = new QSplashScreen(QPixmap(":/images/misc/intro.png"));
    splash->setWindowModality(Qt::ApplicationModal);
    splash->setWindowFlags(Qt::FramelessWindowHint);
    splash->show();
    this->close();
}

void StartWindow::startGameHardClicked(){
    game.setDifficultyHard(1);
    game.show();
    QSplashScreen *splash = new QSplashScreen(QPixmap(":/images/misc/intro.png"));
    splash->setWindowModality(Qt::ApplicationModal);
    splash->setWindowFlags(Qt::FramelessWindowHint);
    splash->show();
    this->close();
}

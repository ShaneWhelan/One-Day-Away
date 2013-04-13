#include "game_window.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::gamewindow){
    ui->setupUi(this);

    // Load all GUI Multimedia elements to improve performance.
    sittingRoom = new QPixmap(":/images/rooms/sitting_room.png");
    *sittingRoom = sittingRoom->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    kitchen = new QPixmap(":/images/rooms/kitchen.png");
    *kitchen = kitchen->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    bedroom = new QPixmap(":/images/rooms/bedroom.png");
    *bedroom = bedroom->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    office = new QPixmap(":/images/rooms/office.png");
    *office = office->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    hallway = new QPixmap(":/images/rooms/hallway.png");
    *hallway = hallway->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    ensuite = new QPixmap(":/images/rooms/ensuite.png");
    *ensuite = ensuite->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    diningRoom = new QPixmap(":/images/rooms/dining_room.png");
    *diningRoom = diningRoom->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    garage = new QPixmap(":/images/rooms/garage.png");
    *garage = garage->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    exitLoose = new QPixmap(":/images/rooms/exit_loose.png");
    *exitLoose = exitLoose->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);
    exitWin = new QPixmap(":/images/rooms/exit.png");
    *exitWin = exitWin->scaled(777,333, Qt::KeepAspectRatio, Qt::FastTransformation);

    mapSound = new QSound(":/sounds/map.wav");
    doorClose = new QSound(":/sounds/doorClose.wav");
    doorCreaking = new QSound(":/sounds/doorCreaking.wav");
    winFreedom = new QSound(":/sounds/freedom.wav");
    map.setFixedSize(500,500);
    map.setWindowFlags(Qt::Dialog);
    map.setWindowModality(Qt::ApplicationModal);
    map.setStyleSheet("border-image:url(:/images/misc/map_blueprints.png);border:0px;");

    ui->northButton->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/arrows/north.png);border:0px;}"
                                   "QPushButton:hover{border-image:url(:/images/actionbuttons/arrows/north_mouse_over.png);border:0px}"
                                   "QPushButton:pressed{border-image:url(:/images/actionbuttons/arrows/north_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->southButton->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/arrows/south.png);border:0px;}"
                                   "QPushButton:hover{border-image:url(:/images/actionbuttons/arrows/south_mouse_over.png);border:0px}"
                                   "QPushButton:pressed{border-image:url(:/images/actionbuttons/arrows/south_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->eastButton->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/arrows/east.png);border:0px;}"
                                  "QPushButton:hover{border-image:url(:/images/actionbuttons/arrows/east_mouse_over.png);border:0px}"
                                  "QPushButton:pressed{border-image:url(:/images/actionbuttons/arrows/east_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->westButton->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/arrows/west.png);border:0px;}"
                                  "QPushButton:hover{border-image:url(:/images/actionbuttons/arrows/west_mouse_over.png);border:0px}"
                                  "QPushButton:pressed{border-image:url(:/images/actionbuttons/arrows/west_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->takeItem->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/pickup.png);border:0px;}"
                                "QPushButton:hover{border-image:url(:/images/actionbuttons/pickup_mouse_over.png);border:0px}"
                                "QPushButton:disabled{border-image:url(:/images/actionbuttons/pickup_disabled.png);border:0px}"
                                "QPushButton:pressed{border-image:url(:/images/actionbuttons/pickup_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->dropItem->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/drop.png);border:0px;}"
                                "QPushButton:hover{border-image:url(:/images/actionbuttons/drop_mouse_over.png);border:0px}"
                                "QPushButton:disabled{border-image:url(:/images/actionbuttons/drop_disabled.png);border:0px}"
                                "QPushButton:pressed{border-image:url(:/images/actionbuttons/drop_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->mapButton->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/map.png);border:0px;}"
                                 "QPushButton:hover{border-image:url(:/images/actionbuttons/map_mouse_over.png);border:0px}"
                                 "QPushButton:disabled{border-image:url(:/images/actionbuttons/map_disabled.png);border:0px}"
                                 "QPushButton:pressed{border-image:url(:/images/actionbuttons/map_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->infoButton->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/info.png);border:0px;}"
                                  "QPushButton:hover{border-image:url(:/images/actionbuttons/info_mouse_over.png);border:0px}"
                                  "QPushButton:pressed{border-image:url(:/images/actionbuttons/info_pressed.png); position: relative;top: 1px; left: 1px;}");
    ui->resetGame->setStyleSheet("QPushButton{border-image:url(:/images/actionbuttons/restart.png);border:0px;}"
                                 "QPushButton:hover{border-image:url(:/images/actionbuttons/restart_mouse_over.png);border:0px}");

    ui->centralwidget->setStyleSheet("QWidget{background-color: #969696;}"
                                     "QTabWidget::pane{border: 2px solid #aaaaaa; border-radius: 5px;}"
                                     "QTabBar::tab {background: #939393; color: white; padding: 5px;}"
                                     "QTabBar::tab:selected {background: #454545;}"
                                     "QTabBar::tab:hover{background: #cecece;}"
                                     "QGroupBox{border: 2px solid #d1d1d1; border-radius: 5px;}"
                                     "QTextEdit{border: 2px solid #d1d1d1; border-radius: 5px;}"
                                     "QListWidget{color: white; border: 2px solid #d1d1d1; border-radius: 5px;}"
                                     "QListWidget:hover{color: black;}"
                                     "QLineEdit{border: 2px solid #d1d1d1; border-radius: 5px;}"
                                     "QLabel{color: white; font-weight:bold; font-size: 15px; font-family: Arial;}"
                                     "QLabel#gameImage{border: 4px solid #d1d1d1; border-radius: 5px;}"
                                     "QCheckBox{color: white; font-size: 15px; font-family: Arial;}");
    ui->GUI->setStyleSheet("QTextEdit{color: white; font-size: 16px;}");
    ui->textBased->setStyleSheet("QTextEdit{color: white;}");
    ui->currentRoom->setStyleSheet("QLabel{font-weight:bold; color: #484848; qproperty-alignment: AlignCenter; font-size: 16px; font-family: Arial;}");

    // Event handling code
    connect(ui->userInput, SIGNAL(returnPressed()), this, SLOT(userInputReturnPressed()));
    connect(ui->infoButton, SIGNAL(clicked()), this, SLOT(infoButtonClicked()));
    connect(ui->mapButton, SIGNAL(clicked()), this, SLOT(mapClicked()));
    connect(ui->northButton, SIGNAL(clicked()), this, SLOT(northButtonClicked()));
    connect(ui->southButton, SIGNAL(clicked()), this, SLOT(southButtonClicked()));
    connect(ui->eastButton, SIGNAL(clicked()), this, SLOT(eastButtonClicked()));
    connect(ui->westButton, SIGNAL(clicked()), this, SLOT(westButtonClicked()));
    connect(ui->takeItem, SIGNAL(clicked()), this, SLOT(takeItemIsClicked()));
    connect(ui->dropItem, SIGNAL(clicked()), this, SLOT(dropItemIsClicked()));
    connect(ui->resetGame, SIGNAL(clicked()), this, SLOT(resetGameIsClicked()));
    connect(ui->itemsInRoom, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(itemInRoomIsClicked(QListWidgetItem *)));
    connect(ui->inventory, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(itemInInventoryIsClicked(QListWidgetItem *)));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(textBasedSelected(int)));
    connect(ui->soundDisabled, SIGNAL(toggled(bool)), this, SLOT(toggleSound(bool)));
    connect(ui->fullScreen, SIGNAL(toggled(bool)), this, SLOT(toggleFullScreen(bool)));

    // Update GUI state
    updateGameText("", QString::fromStdString(eng->getCurrentRoomDescription()));
    ui->welcomeText->setText("This is is the old way of playing for grognards.\nType \"info\" for help!");

    // Disable Loudness and Weight Sliders from user input
    ui->loudness->setEnabled(0);
    ui->weight->setEnabled(0);
    ui->loudness->setMaximum(eng->player->getGameOverLoud());
    ui->weight->setMaximum(eng->player->getGameOverWeight());
    ui->weight->setMinimum(0);

    soundDisabled = false;
    tabSelected = 0;
}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::updateGameText(string userCommand, QString gameOutput) {
    QString oldOutput = ui->textBasedOutput->toPlainText();
    QString currentRoomName = QString::fromStdString(eng->getCurrentRoomName());
    // Do game over checks
    if(gameOutput.compare("Game Over") == 0){
        if(tabSelected == 0 && soundDisabled == false){
            doorCreaking->play();
        }
        // Change game output from just game over to explaining why player lost
        // this line is the difference between an ensuite game over and exit game over
        gameOutput = QString::fromStdString(eng->player->getGameEndingReason());
        QSplashScreen *splash = new QSplashScreen(QPixmap(":/images/misc/game_over.png"));
        //Cant interact with any other part of the application until splashscreen is dismissed
        splash->setWindowModality(Qt::ApplicationModal);
        splash->setWindowFlags(Qt::FramelessWindowHint);
        splash->show();
    }else if(currentRoomName.compare("Ensuite") == 0){
        if(tabSelected == 0 && soundDisabled == false){
            doorCreaking->play();
        }
        QSplashScreen *splash = new QSplashScreen(QPixmap(":/images/misc/game_over.png"));
        splash->setWindowModality(Qt::ApplicationModal);
        splash->setWindowFlags(Qt::FramelessWindowHint);
        splash->show();
    }else if(gameOutput.compare("You Win") == 0){
        if(tabSelected == 0 && soundDisabled == false){
            winFreedom->play();
        }
        QSplashScreen *splash = new QSplashScreen(QPixmap(":/images/misc/win.png"));
        splash->setWindowModality(Qt::ApplicationModal);
        splash->setWindowFlags(Qt::FramelessWindowHint);
        splash->show();
    }
    //Update Text Based tab
    if (oldOutput == "") {
        ui->textBasedOutput->setText(currentRoomName + ":\n" + gameOutput);
    }else{
        if(userCommand.compare("go") == 0){
            if(eng->getGameState() != true && tabSelected == 0 && soundDisabled == false &&
                    gameOutput.compare("It's just a wall. You cant travel through walls.") != 0 &&
                    gameOutput.compare("Christ. Learn your way round your own damn house.") != 0){
                doorClose->play();
            }
            ui->textBasedOutput->setText(oldOutput + "\n\n" + currentRoomName + ":\n" + gameOutput);
        }else{
            ui->textBasedOutput->setText(oldOutput + "\n\n" + gameOutput);
        }
    }
    QScrollBar *vSB = ui->textBasedOutput->verticalScrollBar(); // Pointer to the always visable ScrollBar
    vSB->triggerAction(QScrollBar::SliderToMaximum); // Set to always at bottom

    //Update Visual tab
    if(userCommand.compare("take") == 0 || userCommand.compare("drop") == 0 || userCommand.compare("map") == 0){
        //Do nothing to Visual Mode
    }else if(userCommand.compare("info") == 0){
        ui->guiOutput->setText("Run! Your screwed!");
    }else if(userCommand.compare("quit") == 0){
        exit(0);
    }else{
        ui->guiOutput->setText(gameOutput);
    }

    ui->currentRoom->setText(currentRoomName);

    if(currentRoomName.compare("Hallway") == 0){
        ui->gameImage->setPixmap(*hallway);
    }else if(currentRoomName.compare("Sitting Room") == 0){
        ui->gameImage->setPixmap(*sittingRoom);
    }else if(currentRoomName.compare("Ensuite") == 0){
        ui->gameImage->setPixmap(*ensuite);
    }else if(currentRoomName.compare("Office") == 0){
        ui->gameImage->setPixmap(*office);
    }else if(currentRoomName.compare("Dining Room") == 0){
        ui->gameImage->setPixmap(*diningRoom);
    }else if(currentRoomName.compare("Kitchen") == 0){
        ui->gameImage->setPixmap(*kitchen);
    }else if(currentRoomName.compare("Master Bedroom") == 0){
        ui->gameImage->setPixmap(*bedroom);
    }else if(currentRoomName.compare("Exit") == 0){
        if(eng->getGameState() == false){
            ui->gameImage->setPixmap(*exitWin);
        }else{
            ui->gameImage->setPixmap(*exitLoose);
        }
    }else if(currentRoomName.compare("Garage") == 0){
        ui->gameImage->setPixmap(*garage);
    }

    refreshAllItems();
}

void gamewindow::refreshAllItems() {
    ui->itemsInRoom->clear();
    vector<string> itemsInCurrentRoom = eng->currentRoom->getRoomItems();
    int itemsListSize = itemsInCurrentRoom.size();
    if(itemsListSize != 0){
        for(int i = 0; i < itemsListSize; i++) {
            ui->itemsInRoom->addItem(QString::fromStdString(itemsInCurrentRoom[i]));
            ui->itemsInRoom->item(i)->setToolTip(QString::fromStdString(eng->getItemHint(itemsInCurrentRoom[i])));
        }
    }

    ui->inventory->clear();
    vector<string> currentInventory = eng->player->getPlayerItems();
    int playerItemsListSize = currentInventory.size();
    if(playerItemsListSize != 0){
        for(int i = 0; i < playerItemsListSize; i++) {
            ui->inventory->addItem(QString::fromStdString(currentInventory[i]));
            ui->inventory->item(i)->setToolTip(QString::fromStdString(eng->getItemHint(currentInventory[i])));
        }
    }

    ui->takeItem->setDisabled(1);
    ui->dropItem->setDisabled(1);
    ui->loudness->setSliderPosition(eng->player->getLoudness());
    ui->weight->setSliderPosition(eng->player->getCurrentWeight());
}

void gamewindow::userInputReturnPressed(){
    string userIn = ui->userInput->text().toStdString();
    transform(userIn.begin(), userIn.end(), userIn.begin(), ::tolower);
    if(userIn.compare("") != 0){
        vector<string> wordList;
        std::stringstream ss(userIn);
        string token;
        char delimiter = ' ';
        while(getline(ss, token, delimiter)) {
            wordList.push_back(token);
        }

        string word1;
        string word2;
        int wordListSize = wordList.size();
        if (wordListSize == 1) {
            word1 = wordList[0];
        }else if(wordListSize == 2){
            word1 = wordList[0];
            word2 = wordList[1];
        }else if (wordListSize >= 3) {
            word1 = wordList[0];
            word2 = wordList[1];
            for(int i = 2; i < wordListSize; i++){
                word2 += " " +  wordList[i];
            }
        }
        Command command(word1, word2);
        addToCommandHistory(QString::fromStdString(word1) + " " + QString::fromStdString(word2));
        QString gameOutput = QString::fromStdString(eng->processCommand(command));
        updateGameText(word1, gameOutput);
        ui->userInput->clear();
    }
}


void gamewindow::infoButtonClicked() {
    Command command("info", "");
    addToCommandHistory("info");
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("info", gameOutput);
}

void gamewindow::mapClicked() {
    if(soundDisabled == false){
        mapSound->play();
    }
    map.show();
    Command command("map", "");
    addToCommandHistory("map");
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("map", gameOutput);
}

void gamewindow::northButtonClicked() {
    Command command("go", "north");
    addToCommandHistory("go north");
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("go", gameOutput);
}

void gamewindow::southButtonClicked() {
    Command command("go", "south");
    addToCommandHistory("go south");
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("go", gameOutput);
}

void gamewindow::eastButtonClicked() {
    Command command("go", "east");
    addToCommandHistory("go east");
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("go", gameOutput);
}

void gamewindow::westButtonClicked() {
    Command command("go", "west");
    addToCommandHistory("go west");
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("go", gameOutput);
}


void gamewindow::itemInRoomIsClicked(QListWidgetItem * itemClicked) {
    ui->itemsInRoom->setCurrentItem(itemClicked);
    ui->takeItem->setEnabled(1);
}

void gamewindow::itemInInventoryIsClicked(QListWidgetItem * itemClicked) {
    ui->inventory->setCurrentItem(itemClicked);
    ui->dropItem->setEnabled(1);
}

void gamewindow::takeItemIsClicked() {
    QListWidgetItem *itemToTake = ui->itemsInRoom->currentItem();
    ui->itemsInRoom->takeItem(ui->itemsInRoom->currentRow());
    ui->inventory->addItem(itemToTake);
    // process command
    Command command("take", itemToTake->text().toStdString());
    QString cmd = "take " + itemToTake->text();
    addToCommandHistory(cmd);
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("take", gameOutput);
    if(ui->itemsInRoom->count() == 0){
        ui->takeItem->setDisabled(1);
    }
}

void gamewindow::dropItemIsClicked(){
    QListWidgetItem *itemToDrop = ui->inventory->currentItem();
    ui->inventory->takeItem(ui->inventory->currentRow());
    ui->itemsInRoom->addItem(itemToDrop);
    //process Command
    Command command("drop", itemToDrop->text().toStdString());
    QString cmd = "drop " + itemToDrop->text();
    addToCommandHistory(cmd);
    QString gameOutput = QString::fromStdString(eng->processCommand(command));
    updateGameText("drop", gameOutput);
    if(ui->inventory->count() == 0){
        ui->dropItem->setDisabled(1);
    }
}

void gamewindow::resetGameIsClicked(){
    eng->resetGame();
    updateGameText("", QString::fromStdString(eng->getCurrentRoomDescription()));
    //ui->loudness->setEnabled(0);
    //ui->weight->setEnabled(0);
    // ui->loudness->setMaximum(eng->player->getGameOverLoud());
    //ui->weight->setMaximum(eng->player->getGameOverWeight());
    //ui->weight->setMinimum(0);
    soundDisabled = false;
    tabSelected = 0;
}

void gamewindow::textBasedSelected(int tabNumber){
    // Give focus to the user input entry in old school when tab is changed.
    if(tabNumber == 1){
        tabSelected = 1;
        QScrollBar *vSB = ui->textBasedOutput->verticalScrollBar(); // Pointer to the always visable ScrollBar
        vSB->triggerAction(QScrollBar::SliderToMaximum); // Set to always at bottom
        ui->userInput->setFocus();
    }else{
        tabSelected = 0;
    }
}

void gamewindow::keyReleaseEvent(QKeyEvent *event) {
    if(ui->tabWidget->currentIndex() == 0){
        if(event->key() == Qt::Key_Up) {
            northButtonClicked();
        }else if(event->key() == Qt::Key_Down) {
            southButtonClicked();
        }else if(event->key() == Qt::Key_Left) {
            westButtonClicked();
        }else if(event->key() == Qt::Key_Right) {
            eastButtonClicked();
        }else if(event->key() == Qt::Key_M){
            mapClicked();
        }else if(event->key() == Qt::Key_I){
            infoButtonClicked();
        }else if(event->key() == Qt::Key_T || event->key() == Qt::Key_P){
            if(ui->takeItem->isEnabled() != 0){

                takeItemIsClicked();
            }
        }else if(event->key() == Qt::Key_D){
            if(ui->dropItem->isEnabled() != 0){
                dropItemIsClicked();
            }
        }
    }else if(ui->tabWidget->currentIndex() == 1){
        if(event->key() == Qt::Key_Up) {
            displayCommandHistory("up");
        }else if(event->key() == Qt::Key_Down) {
            displayCommandHistory("down");
        }
    }
}

void gamewindow::toggleSound(bool soundDisabled){
    this->soundDisabled = soundDisabled;
}

void gamewindow::toggleFullScreen(bool fullScreenEnabled){
    if(fullScreenEnabled == true){
        int width = QApplication::desktop()->width();
        int height = QApplication::desktop()->height();
        ui->tabWidget->move((width-1000)/2 ,(height-651)/2);
        QWidget::showFullScreen();
    }else{
        QWidget::showNormal();
        ui->tabWidget->move(10, 0);
    }
}

void gamewindow::changeEvent(QEvent *event){
    if(QEvent::WindowStateChange == event->type()){
        if(isMaximized() == true){
            QSize windowSize = ui->centralwidget->size();
            int width = windowSize.width();
            int height = windowSize.height();
            ui->tabWidget->move((width-1000)/2 ,(height-651)/2);
        }else if(ui->fullScreen->isChecked() == false){
            QWidget::showNormal();
            ui->tabWidget->move(10, 0);
        }
    }
}

void gamewindow::setDifficultyHard(bool difficultyHard){
    this->difficultyHard = difficultyHard;
    if(this->difficultyHard == 1){
        ui->loudness->setVisible(0);
        ui->weight->setVisible(0);
        ui->loudnessLabel->setVisible(0);
        ui->weightLabel->setVisible(0);
    }
}

void gamewindow::addToCommandHistory(QString command){
    commandHistory.push_back(command);
    commandHistoryIndex = commandHistory.size();
}

void gamewindow::displayCommandHistory(string key){
    int commandHistorySize = commandHistory.size();
    if(key.compare("up") == 0){
        if(commandHistorySize > 1 && commandHistoryIndex > 0){
            ui->userInput->clear();
            ui->userInput->setText(commandHistory[commandHistoryIndex-1]);
            commandHistoryIndex--;
        }
    }else{
        if(commandHistorySize > commandHistoryIndex+1){
            ui->userInput->clear();
            ui->userInput->setText(commandHistory[commandHistoryIndex+1]);
            commandHistoryIndex++;
        }else{
            ui->userInput->clear();
        }
    }
}

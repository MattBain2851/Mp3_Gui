#include "player.h"
#include "ui_player.h"
#include <iostream>
#include <string>
Player::Player(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);
    playlist = new QMediaPlaylist;
    player = new QMediaPlayer;



}

Player::~Player()
{
    delete ui;
    delete player;
    delete playlist;

}


void Player::on_playButton_clicked()
{

    std::cout << "Player State is: " << player->state() << std::endl;
    this->on_songLabel_windowIconTextChanged(this->getCurrentSong());
    if( player->state() == 0 ){
        player->setVolume(50);
        player->play();
        std::cout << "Player State is: " << player->state() << std::endl;
    }
    else if(player->state() == 2 ){
        player->play();
        std::cout << "Player State is: " << player->state() << std::endl;
    }
    else{
        player->pause();
        std::cout << "Player State is: " << player->state() << std::endl;
    }
}

void Player::on_skipButton_clicked()
{
    playlist->next();
    this->on_songLabel_windowIconTextChanged(this->getCurrentSong());
}

void Player::on_backButton_clicked()
{
    playlist->previous();
    this->setSongName(this->getCurrentSong());
}

void Player::on_loadSong_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open a File","","Audio File(*.*)");
    for(const QString & filename: filenames){
        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(filename)));
        QStringList lst = filename.split('/'); // this might be a bad idea inside a for loop
        ui->listOfSongs->addItem(lst[lst.count()-1]);
    }


    player->setPlaylist(playlist);
}


QString Player::getCurrentSong(){
    QUrl URL = playlist->media(playlist->currentIndex()).request().url();
    QString URLstring =  URL.toString();
    QStringList lst = URLstring.split('/');
    return lst[lst.count()-1];
}

void Player::on_songLabel_windowIconTextChanged(const QString &iconText)
{
    ui->songLabel->setText(iconText);
}

void Player::setSongName(const QString &iconText){
    this->on_songLabel_windowIconTextChanged(iconText);
}



void Player::on_listOfSongs_clicked(const QModelIndex &index)
{
    playlist->setCurrentIndex(index.row());
    this->on_songLabel_windowIconTextChanged(this->getCurrentSong());

}

#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QMediaPlayer>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class Player; }
QT_END_NAMESPACE

class Player : public QMainWindow
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QString getCurrentSong();
    void setSongName(const QString &iconText);
    ~Player();

private slots:
    void on_playButton_clicked();

    void on_skipButton_clicked();

    void on_loadSong_clicked();

    void on_backButton_clicked();



    void on_songLabel_windowIconTextChanged(const QString &iconText);


    void on_listOfSongs_clicked(const QModelIndex &index);

private:
    Ui::Player *ui;

};
#endif // PLAYER_H

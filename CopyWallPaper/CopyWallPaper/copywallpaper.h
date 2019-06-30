#ifndef COPYWALLPAPER_H
#define COPYWALLPAPER_H

#include <QMainWindow>
#include<QLabel>

namespace Ui {
class CopyWallPaper;
}

class CopyWallPaper : public QMainWindow
{
    Q_OBJECT

public:
    explicit CopyWallPaper(QWidget *parent = nullptr);
    ~CopyWallPaper();
protected:
    void getOpenedDirName();
    void getSrcDir();
    void copy();

private slots:
    void on_open_clicked();

    void on_save_clicked();

    void on_pushButton_clicked();

private:
    QLabel              *status;
    std::string         dstdirname;
    std::string         srcdirname;
    Ui::CopyWallPaper   *ui;
};

#endif // COPYWALLPAPER_H

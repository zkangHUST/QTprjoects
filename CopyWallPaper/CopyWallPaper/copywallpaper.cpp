#include "copywallpaper.h"
#include "ui_copywallpaper.h"
#include<QFileDialog>
#include<QMessageBox>
#include<windows.h>
#include<QDebug>
#include<iostream>
#include<dirent.h>
#include <sys/stat.h>
#define ONE_Hundred_KB  100*1024

CopyWallPaper::CopyWallPaper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CopyWallPaper)
{
    ui->setupUi(this);
    this->status = new QLabel();
    ui->statusBar->addPermanentWidget(status);
    this->status->setText("Ready");
}

CopyWallPaper::~CopyWallPaper()
{
    delete ui;
}

void CopyWallPaper::on_open_clicked()
{
    this->getSrcDir();
    this->getOpenedDirName();
}

void CopyWallPaper::getOpenedDirName()
{
    QString dirName;

    dirName = QFileDialog::getExistingDirectory(this,tr("打开文件夹"),"/home", QFileDialog::ShowDirsOnly);
    this->dstdirname = std::string(dirName.toLocal8Bit());
    qDebug()<<this->dstdirname.c_str();
    ui->location->setText(dirName);
}

void CopyWallPaper::getSrcDir()
{
    char *localappdata;
    // win10壁纸保存的文件夹
    std::string src_dir = "\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets";
    localappdata = getenv("localappdata");
    src_dir = localappdata + src_dir;
    this->srcdirname = src_dir;
    qDebug() << src_dir.c_str();
}

void CopyWallPaper::copy()
{
    DIR             *dir;
    int             cnt = 0, result;
    char            buf[1024];
    std::string     newfilename;
    struct stat64   buffer;

    if (this->dstdirname.empty()) {
        QMessageBox::warning(this,"警告","请指定文件保存目录",QMessageBox::NoButton);
        return ;
    }
    SetCurrentDirectoryA(this->srcdirname.c_str());
    GetCurrentDirectoryA(1024, buf);
    qDebug() << "current dir is "<<buf;
    struct dirent *f;
    if ((dir = opendir(".")) == nullptr) {
        QMessageBox::warning(this,"警告","文件夹打开失败",QMessageBox::NoButton);
        return;
    }
    this->status->setText("Working......");
    while ((f = readdir(dir)) != nullptr) {
        qDebug()<< f->d_name;
        // 排除.和..文件夹
        if((strcmp(f->d_name, ".") == 0) || (strcmp(f->d_name, "..") == 0))
            continue;
        result = stat64(f->d_name, &buffer);
        // 文件小于100kb的可能是缩略图，不要了
        if (result != 0 || buffer.st_size < ONE_Hundred_KB)
            continue;
        newfilename = this->dstdirname + "\\" + std::string(f->d_name) + ".jpg";
        qDebug()<<newfilename.c_str();
        CopyFileA(f->d_name, newfilename.c_str(), FALSE);
        cnt++;
    }
    closedir(dir);
    this->status->setText("Ready");
    std::string tmp = std::to_string(cnt) + " pictures were saved!";
    QMessageBox::information(this,"INFO",tmp.c_str());
}

// 点击保存动作
void CopyWallPaper::on_save_clicked()
{
    this->copy();
}

// 显示软件信息
void CopyWallPaper::on_pushButton_clicked()
{
    QMessageBox::about(this,"about","BY 二丽&&郑康\n:-)\t2018.10.23");

}

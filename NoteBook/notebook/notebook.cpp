#include "notebook.h"
#include "ui_notebook.h"

#include <QDialog>
#include <QFileDialog>
#include<QFontDialog>
#include<QColorDialog>
#include <cstdio>
#include <sys/stat.h>
#include<cstdio>
#include<QCloseEvent>

NoteBOOK::NoteBOOK(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NoteBOOK)
{
    ui->setupUi(this);
    this->setWindowTitle("无标题");
    this->setWindowIcon(QIcon(":/image/notebook.png"));
    connect(ui->actionopen,&QAction::triggered,this,&NoteBOOK::OpenFileAction);
    connect(ui->actionnew,&QAction::triggered,this,&NoteBOOK::CreateNewFileAction);
    connect(ui->actionsave,&QAction::triggered,this,&NoteBOOK::SaveFileAction);
    connect(ui->actionsaveas,&QAction::triggered,this,&NoteBOOK::SaveFileAsAction);
    connect(ui->actionreplace,&QAction::triggered,this,&NoteBOOK::ReplaceAction);
    connect(ui->actionfont,&QAction::triggered,this,&NoteBOOK::FontAction);
    connect(ui->actionfind,&QAction::triggered, this, &NoteBOOK::FindAction);
    connect(ui->actioninfo,&QAction::triggered, this, &NoteBOOK::InfoAction);
    ui->status->setText("Ready");//设置状态栏默认内容
    ui->statusBar->addPermanentWidget(ui->status);//添加到状态栏，在窗口的右下角
}

NoteBOOK::~NoteBOOK()
{
    delete ui;
}

// 打开文件
void NoteBOOK::OpenFileAction()
{
    FILE        *pFile_Opened;
    char        buf[1024] = {0};
    QString     filename;

    if (this->file_saved == false) {
        this->file_unsaved_warning();
        if (this->button == QMessageBox::No) {
            return ;
        }
    }

    filename = QFileDialog::getOpenFileName(this, tr("打开文件","/home", QFileDialog::DontResolveSymlinks));
    if (filename.isEmpty())
        return ;
    //Qstring 转换成std::string
    this->filename = std::string(filename.toLocal8Bit());
    this->setWindowTitle(filename);

    pFile_Opened = fopen(filename.toLocal8Bit(), "r");
    if(pFile_Opened == nullptr) {
       QMessageBox::warning(this,"警告","文件打开失败", QMessageBox::Ok);
        return ;
    }

    // 读取文件内容，写入文本框
    ui->textedit->clear();
    while(!feof(pFile_Opened)){
        fgets(buf, 1024, pFile_Opened);
        ui->textedit->moveCursor(QTextCursor::End);
        // 编码转换，解决中文乱码问题
        QString x = QString::fromLocal8Bit(buf);
        ui->textedit->insertPlainText(x);
    }
    fclose(pFile_Opened);
    // 置标志位
    this->file_saved = true;
}

//创建新文件
void NoteBOOK::CreateNewFileAction()
{
    //检查是否有文件打开没有保存
    if (this->file_saved == false) {
        this->file_unsaved_warning();
    }
    if (this->button == QMessageBox::No) {
        return ;
    }
    this->filename.clear();
    this->setWindowTitle("无标题");
    ui->textedit->clear();
    this->file_saved = true;
}

//保存文件
void NoteBOOK::SaveFileAction()
{
    FILE *fp;
    if (this->filename.empty()) {
        this->SaveFileAsAction();
        return ;
    }
    QString detail = ui->textedit->toPlainText();
    std::string temp = q2s(detail);

    fp = fopen(this->filename.c_str(), "w");
    if(fp == nullptr) {
       QMessageBox::warning(this,"warning","保存失败", QMessageBox::Ok);
        return ;
    }

    fwrite(temp.c_str(),sizeof(char), temp.length(),fp);
    fclose(fp);
    this->file_saved = true;
}

//另存文件
void NoteBOOK::SaveFileAsAction()
{
     FILE *fp;
     char filenamebuf[1024];
     QString filename = QFileDialog::getSaveFileName(this,tr("另存为"), ":/res.txt",
                                                    tr("文本文档(*.txt)"),
                                                    Q_NULLPTR,
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
     if(filename.isEmpty()) {
         return ;
     }
     this->filename =std::string(filename.toLocal8Bit());

     strcpy(filenamebuf, q2s(filename).c_str());
     QString detail = ui->textedit->toPlainText();
     std::string temp = q2s(detail);
     fp = fopen(filenamebuf, "w");
     if(fp == nullptr) {
        QMessageBox::warning(this,"warning","另存为失败", QMessageBox::Ok);
         return ;
     }
     this->setWindowTitle(filename);
     fwrite(temp.c_str(),sizeof(char), temp.length(),fp);
     fclose(fp);
     this->file_opening = true;
     this->file_saved = true;
}

//替换操作
void NoteBOOK::ReplaceAction()
{
    // TODO
}
void NoteBOOK::FindAction()
{
    this->finddialog.setWindowTitle("Find");
    this->finddialog.show();
    // TODO

}

//设置字体
void NoteBOOK::FontAction()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok,this);
    if(ok) {
        ui->textedit->setFont(f);
    }
}

//设置颜色
void NoteBOOK::ColorAction()
{
    QColor color = QColorDialog::getColor();
    ui->textedit->document();
    //    QFont f = QFontDialog::getFont(&ok,this);
    if(color.isValid()) {
      ;
    }
}

//显示信息
void NoteBOOK::InfoAction()
{
    QMessageBox::about(this,tr("关于"),tr("BY 二丽&&郑康\n:-)\t2018.10.21"));
}

//获取文件大小
long GetFileSzie(FILE *pFile)
{
    long lsize = 0;
    if (pFile == nullptr)
        return -1;
    fseek (pFile , 0 , SEEK_END);
    lsize = ftell (pFile);
    rewind (pFile);
    return lsize;
}

//QString 转换成string
std::string q2s(const QString &s)
{
    return std::string((const char *)s.toLocal8Bit());
}



void NoteBOOK::on_textedit_cursorPositionChanged()
{
    QTextCursor textCursor =ui->textedit->textCursor();//获得鼠标光标
    int lineNum = textCursor.blockNumber();//行数
    int colNum = textCursor.columnNumber();//列数
    ui->status->setText(tr("行:%1,列:%2").arg(lineNum+1).arg(colNum));//显示在Label上，注意：行数是从0开始的
}

//关闭事件，点击右上角的X时调用
void NoteBOOK::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    if(this->file_saved == true) {
        event->accept();
        return ;
    }

    button = QMessageBox::question(this, tr("退出程序"),
          QString(tr("警告：文件未保存，是否结束程序")),
          QMessageBox::Yes | QMessageBox::No);

     if (button == QMessageBox::No) {
         event->ignore();  //忽略退出信号，程序继续运行
     }
     else if (button == QMessageBox::Yes) {
         event->accept();  //接受退出信号，程序退出
     }
}

void NoteBOOK::on_textedit_textChanged()
{
    this->file_saved = false;
}

//文件未保存警告
void NoteBOOK::file_unsaved_warning()
{
     this->button = QMessageBox::question(this, tr("NoteBook"),
              QString(tr("警告：文件未保存，是否放弃更改？")),
              QMessageBox::Yes | QMessageBox::No);
}


// 关闭文件(实际操作与新建文件一样)
void NoteBOOK::on_actionclose_triggered()
{
    this->CreateNewFileAction();
}

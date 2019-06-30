#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>
#include <find.h>
#include <QMessageBox>
long GetFileSzie(FILE *pFile);
namespace Ui {
class NoteBOOK;
}

std::string q2s(const QString &s);

class NoteBOOK : public QMainWindow
{
    Q_OBJECT

public:
    explicit NoteBOOK(QWidget *parent = nullptr);
    ~NoteBOOK();
protected:
    void OpenFileAction();
    void CreateNewFileAction();
    void SaveFileAction();
    void SaveFileAsAction();
    void ReplaceAction();
    void FontAction();
    void ColorAction();
    void FindAction();
    void InfoAction();
    void closeEvent(QCloseEvent *event);
    void file_unsaved_warning();
private slots:

    void on_textedit_cursorPositionChanged();
    void on_textedit_textChanged();
    void on_actionclose_triggered();

private:
    Ui::NoteBOOK                *ui; //界面
    char                        *filebuf;
    FILE                        *pFile_Opened;
    std::string                 filename;//打开的文件名称，包含路径
    class find                  finddialog;//查找框类
    bool                        file_opening = false;  //文件打开状态
    bool                        file_saved = true;//文件保存状态
    QMessageBox::StandardButton button = QMessageBox::Yes;
};

#endif // NOTEBOOK_H

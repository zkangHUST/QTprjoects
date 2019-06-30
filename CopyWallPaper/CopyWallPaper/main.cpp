#include "copywallpaper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CopyWallPaper w;
    w.show();
     QFont font( "Microsoft YaHei");
    w.setFont(font);
    return a.exec();
}

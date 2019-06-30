#include "notebook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoteBOOK w;
    w.show();

    return a.exec();
}

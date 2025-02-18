#include "userpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    userpage w;
    w.show();
    return a.exec();
}

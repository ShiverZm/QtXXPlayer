#include "XXPlayMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XXPlayMainWindow w;
	//Ìí¼Ó´°¿ÚÍ¼±ê
	w.setWindowIcon(QIcon(":/XXPlayMainWindow/Resources/logo.ico"));
    w.show();
    return a.exec();
}

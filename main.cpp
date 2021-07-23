#include "Service.h"
#include "Repository.h"

#include "MainGUI.h"
#include <QApplication>

int main(int argc, char **argv)
{
	QApplication a(argc,argv);
	Repository personsRepo;
	Service service(personsRepo);
	MainGUI mainWindow(service);
	mainWindow.show();
	return a.exec();
}


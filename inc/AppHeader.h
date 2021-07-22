#ifndef H_APP_HEADER
#define H_APP_HEADER
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class AppHeader: public QWidget
{
private:
	QLabel *headerTxt;
	QHBoxLayout *mainLayout;
public:
	AppHeader();
	~AppHeader();
	
};
#endif
#include <QApplication>
#include <QTranslator>
#include <QtSql>

#include <IoNetClient.h>

#include "mainform.h"
#ifdef WIN32

#include <QtPlugin>
Q_IMPORT_PLUGIN(qsvg)
#endif
int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QCoreApplication::setOrganizationName("Rabitsa");
    QCoreApplication::setApplicationName("aparat");

    QSettings s;
    
    IoNetClient net(s.value("/ioserv/hostname","localhost").toString());

    
    QStackedWidget main;
    QColor cl;
    QPalette pal;
    cl.setRgb(90,132,201);
    pal.setColor(QPalette::Background,cl);
    main.setPalette(pal);

    //QTranslator translator;
    //translator.load("scada_"+QLocale::system().name(),":/translate");
    //app.installTranslator(&translator);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    
    mMainForm *mainForm = new mMainForm(net);
    
    main.addWidget(mainForm);
    main.setCurrentWidget(mainForm);

    //QObject::connect(mainForm->Exit,SIGNAL(clicked()),&main,SLOT(close()));

    if(QApplication::desktop()->size().width()>1280 && QApplication::desktop()->size().height()> 1024)
    {
        main.resize(1280,1024);
        main.show();
    }
    else
    {
        main.showFullScreen();
    }
    return app.exec();
}



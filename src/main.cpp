#include <QApplication>
#include <QFileSystemModel>
#include <QListView>
#include <QSplitter>
#include <QTreeView>
#include <iostream>

#include "MainWindow.hpp"
#include "PersonalModel.hpp"
#include "PersonalWidget.hpp"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    std::shared_ptr< QAbstractTableModel > model = std::make_shared< PersonalModel >();
    QWidget* modelWidget = new PersonalWidget();

    MainWindow mainWindow;
    mainWindow.setModel( model );
    mainWindow.setModelWidget( modelWidget );
    mainWindow.show();

    return app.exec();
}

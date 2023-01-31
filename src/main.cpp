#include <QApplication>
#include <QFileSystemModel>
#include <QListView>
#include <QSplitter>
#include <QTreeView>
#include <iostream>
#include "PersonalModel.hpp"
#include "MainWindow.hpp"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    std::shared_ptr< QAbstractTableModel > model = std::make_shared< PersonalModel >();

    MainWindow mainWindow;
    mainWindow.setModel( model );
    mainWindow.show();
    
    return app.exec();
}

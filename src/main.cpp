#include <QApplication>
#include <iostream>

#include "MainWindow.hpp"
#include "PersonalModel.hpp"
#include "PersonalWidget.hpp"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    auto model = std::make_shared< PersonalModel >();
    PersonalWidget* modelWidget = new PersonalWidget();

    MainWindow mainWindow;
    mainWindow.setModel( model, modelWidget );
    mainWindow.show();

    return app.exec();
}

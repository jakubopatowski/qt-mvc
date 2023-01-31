#include "MainWindow.hpp"

MainWindow::MainWindow( QWidget* parent, Qt::WindowFlags flags ) : QMainWindow( parent, flags ) {
    ui.setupUi( this );
}

void MainWindow::setModel( std::shared_ptr< QAbstractTableModel >& model ) {
    m_model = model;
    ui.tableView->setModel( m_model.get() );
}
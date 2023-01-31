#include "MainWindow.hpp"

MainWindow::MainWindow( QWidget* parent, Qt::WindowFlags flags ) : QMainWindow( parent, flags ) {
    ui.setupUi( this );
}

void MainWindow::setModel( std::shared_ptr< QAbstractTableModel >& model ) {
    m_model = model;
    m_sortFilter.setSourceModel( m_model.get() );
    ui.tableView->setModel( &m_sortFilter );
    ui.tableView->setSortingEnabled( true );
}
#include "MainWindow.hpp"

MainWindow::MainWindow( QWidget* parent, Qt::WindowFlags flags ) : QMainWindow( parent, flags ) {
    ui.setupUi( this );

    //setup context menu
    ui.tableView->setContextMenuPolicy( Qt::CustomContextMenu );
    tableMenu = new QMenu( ui.tableView );
    tableMenu->addAction( ui.actionAdd );
    tableMenu->addAction( ui.actionDelete );
    connect( ui.tableView, &QTableView::customContextMenuRequested, this,
             &MainWindow::slotCustomMenuRequested );
}

void MainWindow::setModel( std::shared_ptr< QAbstractTableModel >& model ) {
    m_model = model;
    m_sortFilter.setSourceModel( m_model.get() );
    ui.tableView->setModel( &m_sortFilter );
    ui.tableView->setSortingEnabled( true );
    ui.tableView->setSelectionBehavior( QAbstractItemView::SelectionBehavior::SelectRows );
}

void MainWindow::slotCustomMenuRequested( QPoint pos ) {
    tableMenu->popup( ui.tableView->viewport()->mapToGlobal( pos ) );
}

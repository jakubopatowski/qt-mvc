#include "MainWindow.hpp"

MainWindow::MainWindow( QWidget* parent, Qt::WindowFlags flags )
    : QMainWindow( parent, flags ), m_modelWidget( nullptr ) {
    ui.setupUi( this );

    //setup context menu
    ui.tableView->setContextMenuPolicy( Qt::CustomContextMenu );
    tableMenu = new QMenu( ui.tableView );
    tableMenu->addAction( ui.actionAdd );
    tableMenu->addAction( ui.actionDelete );
    connect( ui.tableView, &QTableView::customContextMenuRequested, this,
             &MainWindow::slotCustomMenuRequested );
    connect( ui.actionAdd, &QAction::triggered, this, &MainWindow::onAdd );
}

void MainWindow::setModel( std::shared_ptr< PersonalModel >& model, PersonalWidget* widget ) {
    setModel( model );
    setModelWidget( widget );

    m_modelWidget->setModel( m_model, 0 );

    //m_sortFilter.setFilterRegExp( QRegExp( "Jakub" ) );
    //m_sortFilter.setFilterKeyColumn( 1 );
}

void MainWindow::setModel( std::shared_ptr< PersonalModel >& model ) {
    m_model = model;
    m_sortFilter.setSourceModel( m_model.get() );
    ui.tableView->setModel( &m_sortFilter );
    ui.tableView->setSortingEnabled( true );
    ui.tableView->setSelectionBehavior( QAbstractItemView::SelectionBehavior::SelectRows );
}

void MainWindow::setModelWidget( PersonalWidget* widget ) { m_modelWidget = widget; }

void MainWindow::slotCustomMenuRequested( QPoint pos ) {
    tableMenu->popup( ui.tableView->viewport()->mapToGlobal( pos ) );
}

void MainWindow::onAdd() {
    if ( m_modelWidget ) {
        m_modelWidget->show();
    }
}
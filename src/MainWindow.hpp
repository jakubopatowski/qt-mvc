#pragma once

#include "PersonalModel.hpp"
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <memory>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow( QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags() );
    void setModel( std::shared_ptr< QAbstractTableModel >& model );

  private:
    Ui::MainWindow ui;
    std::shared_ptr< QAbstractTableModel > m_model;
    QSortFilterProxyModel m_sortFilter;
    QMenu* tableMenu;

  private slots:
    void slotCustomMenuRequested( QPoint pos );
};
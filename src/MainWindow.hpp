#pragma once

#include "PersonalModel.hpp"
#include "PersonalWidget.hpp"
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <memory>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow( QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags() );
    void setModel( std::shared_ptr< PersonalModel >& model, PersonalWidget* widget );

  private:
    void setModel( std::shared_ptr< PersonalModel >& model );
    void setModelWidget( PersonalWidget* widget );

    Ui::MainWindow ui;
    std::shared_ptr< PersonalModel > m_model;
    QSortFilterProxyModel m_sortFilter;
    QMenu* tableMenu;
    PersonalWidget* m_modelWidget;

  private slots:
    void slotCustomMenuRequested( QPoint pos );
    void onAdd();
};
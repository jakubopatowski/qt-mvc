#pragma once

#include "PersonalModel.hpp"
#include "ui_PersonalWidget.h"
#include <QWidget>

class PersonalWidget : public QWidget
{
    Q_OBJECT
  public:
    PersonalWidget( QWidget* parent = nullptr, Qt::WindowFlags f = {} );
    virtual void setModel( std::shared_ptr< PersonalModel >& model, unsigned int id = 0 );

  private:
    Ui::PersonalWidget ui;
    std::shared_ptr< PersonalModel > m_model;

  private slots:
    void onAdd();
};
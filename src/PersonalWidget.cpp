#include "PersonalWidget.hpp"

PersonalWidget::PersonalWidget( QWidget* parent, Qt::WindowFlags f ) : QWidget( parent, f ) {
    ui.setupUi( this );

    connect( ui.savePushButton, &QPushButton::clicked, this, &PersonalWidget::onAdd );
}

void PersonalWidget::setModel( std::shared_ptr< PersonalModel >& model, unsigned int id ) {
    m_model = model;

    if ( id != 0 ) {
        auto item = std::find_if( m_model->getData().begin(), m_model->getData().end(),
                                  [ id ]( PersonalInfo item ) { return item.id == id; } );
        ui.idSpinBox->setValue( item->id );
        ui.nameLineEdit->setText( QString::fromStdString( item->name ) );
        ui.surnameLineEdit->setText( QString::fromStdString( item->surname ) );
        ui.ageSpinBox->setValue( item->age );
    }
    else {
        ui.idSpinBox->setValue( m_model->getData().size() + 1 );
    }


}

void PersonalWidget::onAdd() {
    PersonalInfo item;
    item.id = ui.idSpinBox->value();
    item.name = ui.nameLineEdit->text().toStdString();
    item.surname = ui.surnameLineEdit->text().toStdString();
    item.age = ui.ageSpinBox->value();

    m_model->addItem( item );
    //m_model->insertRows( item.id - 1, 1 );
}
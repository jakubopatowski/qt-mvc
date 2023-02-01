#pragma once

#include "PersonalInfo.hpp"
#include <QAbstractTableModel>

class PersonalModel : public QAbstractTableModel
{
    Q_OBJECT

  public:
    PersonalModel( QObject* parent = nullptr );

    void createData();
    std::vector< PersonalInfo > getData();
    void addItem( PersonalInfo& item );

    virtual int rowCount( const QModelIndex& ) const override;
    virtual int columnCount( const QModelIndex& ) const override;
    virtual QVariant headerData( int section, Qt::Orientation orientation,
                         int role = Qt::DisplayRole ) const override;
    virtual QVariant data( const QModelIndex&, int ) const override;
    virtual bool insertRows( int row, int count, const QModelIndex& parent = QModelIndex() );
    virtual bool removeRows( int row, int count, const QModelIndex& parent = QModelIndex() );

  private:
    std::vector< PersonalInfo > m_Data;

};
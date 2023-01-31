#include "PersonalModel.hpp"

PersonalModel::PersonalModel( QObject* parent ) : QAbstractTableModel( parent ) { createData(); }

void PersonalModel::createData() { m_Data = PersonalInfo::getSomePersonalInfo(); }

int PersonalModel::rowCount( const QModelIndex& ) const { return 4; }
int PersonalModel::columnCount( const QModelIndex& ) const { return 4; }

QVariant PersonalModel::headerData( int section, Qt::Orientation orientation, int role ) const {
    if ( role == Qt::DisplayRole && orientation == Qt::Horizontal ) {
        switch ( section ) {
        case 0:
            return "Id";
        case 1:
            return "Name";
        case 2:
            return "Surname";
        case 3:
            return "Age";
        }
    }

    return QVariant();
}

QVariant PersonalModel::data( const QModelIndex& index, int role ) const {
    int row = index.row();
    int col = index.column();
    auto& item = m_Data[ row ];

    switch ( role ) {
    case Qt::DisplayRole:
        switch ( col ) {
        case 0:
            return item.id;
        case 1:
            return QString::fromStdString( item.name );
        case 2:
            return QString::fromStdString( item.surname );
        case 3:
            return item.age;
        }
        break;
    }
    return QVariant();
}
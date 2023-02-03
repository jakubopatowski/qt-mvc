#include "PersonalModel.hpp"

PersonalModel::PersonalModel( QObject* parent ) : QAbstractTableModel( parent ) { createData(); }

void PersonalModel::createData() { m_Data = PersonalInfo::getSomePersonalInfo(); }
std::vector< PersonalInfo > PersonalModel::getData() { return m_Data; }
void PersonalModel::addItem( PersonalInfo& item ) {
    auto parent = QModelIndex();
    auto row = m_Data.size();
    beginInsertRows( parent, row, row + 1 );
    m_Data.push_back( item );
    endInsertRows();
}

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

bool PersonalModel::insertRows( int row, int count, const QModelIndex& parent ) {
    beginInsertRows( parent, row, row + count );
    endInsertRows();
    return true;
}

bool PersonalModel::removeRows( int row, int count, const QModelIndex& parent ) { return true; }
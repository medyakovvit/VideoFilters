#include "filtersmodel.h"

#include <QDebug>

#include "thresholdvideofilter.h"
#include "rgb2grayvideofilter.h"

FiltersModel::FiltersModel(QObject *parent) : QAbstractListModel(parent)
{

    m_roles.insert(NAME, "filterName");
    m_roles.insert(QML_FILE, "qmlFile");
    m_roles.insert(FILTER, "filter");

    m_filters.append(new RGB2GrayVideoFilter("rgb", this));
}

FiltersModel::~FiltersModel()
{
}

QQmlListProperty<VideoFilter> FiltersModel::filters()
{
    return QQmlListProperty<VideoFilter>(this, m_filters);
}

void FiltersModel::addFilter()
{
    int pos = m_filters.size();
    beginInsertRows(QModelIndex(), pos, pos);
    m_filters.append(new ThresholdVideoFilter("Thresh", this));
    endInsertRows();
    emit filtersChanged(this->filters());
}

int FiltersModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_filters.size();
}

QVariant FiltersModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(index.row() < 0 || index.row() >= m_filters.size())
        return QVariant();

    switch (role) {
    case NAME:
        return m_filters.at(index.row())->name();

    case QML_FILE:
        return m_filters.at(index.row())->qmlFile();

    case FILTER:
        return QVariant::fromValue(m_filters.at(index.row()));

    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> FiltersModel::roleNames() const
{
    return m_roles;
}

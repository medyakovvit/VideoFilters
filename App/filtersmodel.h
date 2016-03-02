#ifndef FILTERSMODEL_H
#define FILTERSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QQmlListProperty>

#include "videofilter.h"

class FiltersModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<VideoFilter> filters READ filters NOTIFY filtersChanged)

    enum{
        NAME = Qt::UserRole + 1,
    };

public:
    FiltersModel(QObject *parent = 0);
    ~FiltersModel();
    QQmlListProperty<VideoFilter> filters();

signals:
    void filtersChanged(QQmlListProperty<VideoFilter>);

public slots:
    void addFilter();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

protected:
    QList<VideoFilter*> m_filters;
    QHash<int, QByteArray> m_roles;
    QQmlListProperty<VideoFilter>* filters_property;
};

#endif // FILTERSMODEL_H

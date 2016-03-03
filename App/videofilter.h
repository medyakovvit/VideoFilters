#ifndef VIDEOFILTER_H
#define VIDEOFILTER_H

#include <QAbstractVideoFilter>

class VideoFilter : public QAbstractVideoFilter
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString qmlFile READ qmlFile WRITE setQmlFile NOTIFY qmlFileChanged)

public:
    VideoFilter(QString name, QObject *parent = 0);
    virtual ~VideoFilter();

    QString name(){return m_name;}
    QString qmlFile(){return m_qmlFile;}

public slots:
    void setName(QString name);
    void setQmlFile(QString file);

signals:
    void nameChanged(QString name);
    void qmlFileChanged(QString file);

protected:
    QString m_name;
    QString m_qmlFile;
    QVideoFilterRunnable *p_runnable;
};

#endif // VIDEOFILTER_H

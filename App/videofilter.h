#ifndef VIDEOFILTER_H
#define VIDEOFILTER_H

#include <QAbstractVideoFilter>

class VideoFilter : public QAbstractVideoFilter
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    VideoFilter(QString name, QObject *parent = 0);
    virtual ~VideoFilter();

    QString name(){return m_name;}

public slots:
    void setName(QString name);

signals:
    void nameChanged(QString name);

protected:
    QString m_name;
    QVideoFilterRunnable *p_runnable;
};

#endif // VIDEOFILTER_H

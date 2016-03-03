#include "videofilter.h"

VideoFilter::VideoFilter(QString name, QObject *parent) : QAbstractVideoFilter(parent),
    m_name(name)
{

}

VideoFilter::~VideoFilter()
{
//    if(p_runnable)
//    {
//        delete p_runnable;
//        p_runnable = 0;
//    }
}

void VideoFilter::setName(QString name)
{
    if(m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void VideoFilter::setQmlFile(QString file)
{
    if(m_qmlFile == file)
        return;

    m_qmlFile = file;
    emit qmlFileChanged(m_qmlFile);
}


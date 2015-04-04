#include "htmlpaser.h"
#include <QDebug>

HtmlPaser::HtmlPaser(const QByteArray& arr)
{
       const char *data = arr.data();
        while(*data){
            qDebug()<<*data;
            data++;
        }
}

HtmlPaser::~HtmlPaser()
{

}


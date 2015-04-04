#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QMap>

class Node
{
public:
    Node(const QString data);
    ~Node();
    QString getName();
    QString getAttribute(QString key);
    QString getValue();
private:
    QString name;
    QString mValue;
    QMap<QString,QString> *attributes;
};

#endif // NODE_H

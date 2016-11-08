#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
private:
    /** The name of the node*/
    QString name;
    /** The number where the node should be*/
    int num;
public:
    Node(QString nm, int number);
    int getNum();
    QString getName();
    void setNum(int n);

};

#endif // NODE_H

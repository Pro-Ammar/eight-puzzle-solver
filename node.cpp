#include "node.h"

Node::Node(QString nm, int number)
{
    this->name =nm;
    this->num = number;
}

int Node::getNum()
{
    return this->num;
}

QString Node::getName()
{
    return this->name;
}

void Node::setNum(int n)
{
    this->num=n;
}

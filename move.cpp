#include "move.h"

Move::Move():cost(0),spacePosition(0)
{}

Move::~Move()
{
    this->move.clear();
}

Move::Move(std::vector<Node> mv)
{
    this->move= mv;
    this->estimateTotalCost();
    this->estimateSpacePosition();
    mv.clear();
    this->estimateKey();
}


int Move::getCost(){
    return this->cost;
}
QString Move::getKey(){
    return this->key;
}
void Move::estimateKey(){
    this->key="";
    for(short j=0;j<move.size();j++)
        this->key+=(this->move[j].getName().isEmpty())?" ":this->move[j].getName();
}
int Move::countInversions(){
    unsigned char inversions =0;
    for(short i=0;i<9;i++){
        if(this->move[i].getName().isEmpty() || (this->move[i].getNum()==i&&inversions==0))
            continue;
        for(short j=i+1;j<9;j++){
            if(this->move[j].getName().isEmpty())
                continue;
            if(this->move[j].getNum() < this->move[i].getNum())
                inversions++;
        }
    }
    return (int) inversions;
}
void Move::estimateTotalCost(){
    short error = 0;
    short sum=0;
    short count=0;
    for(short i=0;i<9;i++){
        sum = this->move[i].getNum()-i;
        if(sum!=0)
            count++;
        error+=(sum<0)?-1*sum : sum;
    }
    this->cost = (this->countInversions()/2+count)/2/*+error*/;
}
void Move::estimateSpacePosition()
{
    for(short i=0;i<move.size();i++)
        if(this->move[i].getName().isEmpty()){
            this->spacePosition=i;
            return;
        }
}
bool Move::checkReach(){
    for(short j=0;j<9;j++)
        if(this->move[j].getNum() != j)
            return false;
    return true;
}
void Move::showMove(QLabel* moveLabels[9]){
    for(short j=0;j<9;j++)
        moveLabels[j]->setText(this->move[j].getName());
}
short Move::getSpacePosition(){
    return this->spacePosition;
}
std::vector<Node> *Move::getMove()
{
    return &this->move;
}
std::vector<Node >::iterator Move::getBegin()
{
    return this->move.begin();
}
void Move::copy(Move &mv)
{
    this->move.clear();
    this->cost=mv.getCost();
    this->spacePosition=mv.getSpacePosition();
    this->copyNodes(*mv.getMove());
}

void Move::copyNodes(std::vector<Node > &n){
    for(int j=0;j<n.size();j++)
        this->move.push_back(n[j]);
}

#include "path.h"

Path::Path():cost(0){}

Path::Path(Path *p)
{
    this->cost=p->getCost();
    this->lastSpacePosition=p->lastSpacePosition;
    this->path=*(p->getPath());
}

double Path::getCost(){
    return this->cost;
}

void Path::addMove(Move move){
    this->path.push_back(move);
    this->cost =this->path.size()+move.getCost();
    this->lastSpacePosition = move.getSpacePosition();
}

std::vector<Move> *Path::getPath(){
    return &this->path;
}

bool Path::checkReach(){
    if(!this->path.empty())
        return this->path.back().checkReach();
    else
        return false;
}

int Path::getSpacePosition(){
    return this->path.back().getSpacePosition();
}

void Path::showMove(QLabel *moveLabels[], short moveNum){
    this->path[moveNum].showMove(moveLabels);
}

void Path::copy(Path &p)
{
    this->path.clear();
    this->cost=p.getCost();
    this->lastSpacePosition=p.lastSpacePosition;
    this->copyMoves(*p.getPath());
}

void Path::copyMoves(std::vector<Move > &m){
    for(int j=0;j<m.size();j++)
        this->path.push_back(m[j]);
}

short Path::getLastSpacePosition()
{
    return this->lastSpacePosition;
}



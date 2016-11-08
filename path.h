#ifndef PATH_H
#define PATH_H

#include <vector>
#include "move.h"
#include <QLabel>

class Path
{
private:
    /** Represent the path as a vector of moves*/
    std::vector<Move > path;
    /** The Total cost of the path*/
    double cost;
    /** The apce position of the last move*/
    short lastSpacePosition;
    void copyMoves(std::vector<Move> &m);
public:
    Path();
    Path(Path*p);
    double getCost();
    short getLastSpacePosition();
    /** Adds move to this path*/
    void addMove(Move move);
    std::vector<Move >* getPath();
    bool checkReach();
    /** Returns the space postition of the last move */
    int getSpacePosition();
    void showMove(QLabel* moveLabels[9],short moveNum);
    void copy(Path &p);
};

#endif // PATH_H

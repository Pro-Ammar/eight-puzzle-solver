#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <QLabel>
#include "node.h"
#include <iostream>

class Move
{
private:
    /** Represents the cost of the move*/
    double cost;
    /** Represents the permutation of the nodes as a vector*/
    std::vector<Node > move;
    /** Represents the space position of the move*/
    short spacePosition;
    /** Represents the move as a string value*/
    QString key;
    void copyNodes(std::vector<Node> &n);
public:
    Move();
    ~Move();
    /** @param mv : is the permutation of nodes that makes the move
     * Initialize the move with mv
     *  and calculate the move's cost, space position
     * and the representation of the move in String*/
    Move(std::vector<Node> mv);
    /** Estimate the total cost*/
    void estimateTotalCost();
    /** Calculate the space position*/
    void estimateSpacePosition();
    /** Count the number of inversions in the move*/
    int countInversions();
    /** get the cost*/
    int getCost();
    /** Checks if this move reached its goal*/
    bool checkReach();
    /** @param moveLabels is a 9-element array on which we will print the move.
     * Print the move on the labels*/
    void showMove(QLabel* moveLabels[9]);
    /** Returns the space position of the move-1, i.e 0-1-...-8*/
    short getSpacePosition();
    /** Returns the move as a vector of nodes*/
    std::vector<Node> *getMove();
    /** Gets the begin iterator of the vector of nodes*/
    std::vector<Node >::iterator getBegin();
    /** @param mv the move to be copied
     * This object will be a hard copy of mv*/
    void copy(Move &mv);
    /** Evaluates the string representation*/
    void estimateKey();
    /** get the string representation*/
    QString getKey();
};
#endif // MOVE_H

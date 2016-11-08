#ifndef EIGHTPUZZLESOLVER_H
#define EIGHTPUZZLESOLVER_H

#include <QMainWindow>
#include "path.h"
#include <vector>
#include <QMessageBox>
#include <QTimer>
#include <QLineEdit>
#include <iostream>

namespace Ui {
class EightPuzzleSolver;
}

class EightPuzzleSolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit EightPuzzleSolver(QWidget *parent = 0);
    ~EightPuzzleSolver();
private slots:

    void on_LineStart1_returnPressed();

    void on_LineStart2_returnPressed();

    void on_LineStart3_returnPressed();

    void on_LineStart4_returnPressed();

    void on_LineStart5_returnPressed();

    void on_LineStart6_returnPressed();

    void on_LineStart7_returnPressed();

    void on_LineStart8_returnPressed();

    void on_LineStart9_returnPressed();

    void on_LineTarget1_returnPressed();

    void on_LineTarget2_returnPressed();

    void on_LineTarget3_returnPressed();

    void on_LineTarget4_returnPressed();

    void on_LineTarget5_returnPressed();

    void on_LineTarget6_returnPressed();

    void on_LineTarget7_returnPressed();

    void on_LineTarget8_returnPressed();

    void on_LineTarget9_returnPressed();

    void on_pushButtonSolve_pressed();

    void on_pushButtonExit_pressed();

    void on_pushButtonNext_pressed();

    void on_pushButtonBack_pressed();

private:
    Ui::EightPuzzleSolver *ui;
    /** The 9 values that represent the target*/
    QLineEdit* targetLines[9];
    /** The 9 values that represent the start position*/
    QLineEdit* startLines[9];
    /** The 9 labels on which we would print the moves*/
    QLabel* moveLabels[9];
    short correctPath;
    int currentMove;
    Move upMove;
    Move downMove;
    Move rightMove;
    Move leftMove;
    Move target;
    std::vector<Path> paths;
    std::vector<Node> nodeList;
    std::vector<QString> exploredMoves;
    void analyze();
    void showPath();
    bool checkExplored(QString key);
};

#endif // EIGHTPUZZLESOLVER_H

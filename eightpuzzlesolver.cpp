#include "eightpuzzlesolver.h"
#include "ui_eightpuzzlesolver.h"

EightPuzzleSolver::EightPuzzleSolver(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::EightPuzzleSolver),correctPath(0)
{
    ui->setupUi(this);
    ui->movesFram->setHidden(true);
    this->setFixedSize(191,373);
    ui->pushButtonNext->setHidden(true);
    ui->pushButtonBack->setHidden(true);

    targetLines[0] =ui->LineTarget1;
    targetLines[1] =ui->LineTarget2;
    targetLines[2] =ui->LineTarget3;
    targetLines[3] =ui->LineTarget4;
    targetLines[4] =ui->LineTarget5;
    targetLines[5] =ui->LineTarget6;
    targetLines[6] =ui->LineTarget7;
    targetLines[7] =ui->LineTarget8;
    targetLines[8] =ui->LineTarget9;

    moveLabels[0]=ui->moveLabel1;
    moveLabels[1]=ui->moveLabel2;
    moveLabels[2]=ui->moveLabel3;
    moveLabels[3]=ui->moveLabel4;
    moveLabels[4]=ui->moveLabel5;
    moveLabels[5]=ui->moveLabel6;
    moveLabels[6]=ui->moveLabel7;
    moveLabels[7]=ui->moveLabel8;
    moveLabels[8]=ui->moveLabel9;

    startLines[0]=ui->LineStart1;
    startLines[1]=ui->LineStart2;
    startLines[2]=ui->LineStart3;
    startLines[3]=ui->LineStart4;
    startLines[4]=ui->LineStart5;
    startLines[5]=ui->LineStart6;
    startLines[6]=ui->LineStart7;
    startLines[7]=ui->LineStart8;
    startLines[8]=ui->LineStart9;

    for(int i=0;i<9;i++){
        targetLines[i]->setAlignment(Qt::AlignCenter);
        moveLabels[i]->setAlignment(Qt::AlignCenter);
        startLines[i]->setAlignment(Qt::AlignCenter);
    }
    QTimer::singleShot(0, ui->LineStart1, SLOT(setFocus()));
}

EightPuzzleSolver::~EightPuzzleSolver()
{
    delete ui;
}
void EightPuzzleSolver::on_LineStart1_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart2, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart2_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart3, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart3_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart4, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart4_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart5, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart5_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart6, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart6_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart7, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart7_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart8, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart8_returnPressed()
{
    QTimer::singleShot(0, ui->LineStart9, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineStart9_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget1, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget1_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget2, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget2_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget3, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget3_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget4, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget4_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget5, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget5_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget6, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget6_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget7, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget7_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget8, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget8_returnPressed()
{
    QTimer::singleShot(0, ui->LineTarget9, SLOT(setFocus()));
}

void EightPuzzleSolver::on_LineTarget9_returnPressed()
{
    this->on_pushButtonSolve_pressed();
}

/** Checks if the input is a real puzzle and has a solution
 * then analyze it to find the solution*/
void EightPuzzleSolver::on_pushButtonSolve_pressed()
{
    paths.clear();
    nodeList.clear();
    currentMove = 0;
    ui->movesFram->setHidden(false);
    this->setFixedSize(404,373);

    ui->pushButtonNext->setHidden(true);
    ui->pushButtonBack->setHidden(true);


    for(int i=0;i<9;i++){
        nodeList.push_back(Node(startLines[i]->text(),0));
        moveLabels[i]->setText(startLines[i]->text());
    }

    bool found=false;
    short emptyFound = 0;
    short emptyFound2= 0;

    for(int i=0;i<9&&!found;i++){
        for(int j=i+1;j<9&&!found;j++)
            if(nodeList[i].getName() == nodeList[j].getName())
                found=true;
    }
    for(int i=0;i<9&&!found;i++){
        for(int j=i+1;j<9&&!found;j++)
            if(targetLines[i]->text() == targetLines[j]->text())
                found=true;
    }

    if(found){
        QMessageBox::information(this,tr("Error in the inputs"),
                     tr(" Inputs are duplicated\n please re-enter them again"));
        return;
    }

    for(int i=0;i<9&&!found;i++){
        if(nodeList[i].getName().isEmpty())
            emptyFound++;
        for(int j=0;j<9;j++){
            if(targetLines[j]->text().isEmpty()&&i==0)
                emptyFound2++;
            if(nodeList[i].getName() == targetLines[j]->text()){
                found=true;
                nodeList[i].setNum(j);
                break;
            }
        }
        if(!found||emptyFound>1||emptyFound2>1)
            break;
        else if(i<8)
            found=false;
    }
    if(!found||emptyFound>1||emptyFound2>1){
        QMessageBox::information(this,tr("Error in the inputs"),
               tr(" There is an error with your inputs\n please re-enter them again"));
        return;
    }
    Move m1 (nodeList);
    if(m1.countInversions()%2 == 1){
        QMessageBox::information(this,tr("Not solvable"),
               tr(" Sorry but this puzzle is not solvable,\n please enter a vlid one."));
        return;
    }
    Path p;
    p.addMove(m1);
    this->paths.push_back(p);
    nodeList.clear();
    this->analyze();
}
/** Checks and explores the best path every time untill the goal is reached*/
void EightPuzzleSolver::analyze(){
    int min;
    if(!paths.empty())
        min=0;
    else
        return;
    for(int i=1;i< paths.size();i++){
        if(paths[i].getCost() < paths[min].getCost())
            min=i;
    }
    if(paths[min].checkReach()){
        this->correctPath = min;
        this->showPath();
        return;
    }
    short spacePosition=paths.at(min).getLastSpacePosition();
    short count=4;
    short up=spacePosition-3;
    short down=spacePosition+3;
    short left=spacePosition-1;
    short right=spacePosition+1;
    if(up<0||up>8){
        count--;
        up=-1;
    }
    if(spacePosition%3 == 2){
        count--;
        right=-1;
    }
    if(down>8||down<0){
        count--;
        down=-1;
    }
    if(spacePosition%3 == 0){
        count--;
        left=-1;
    }
    Path p;
    Move m;
    p.copy(paths[min]);
    if(count>=1&&up>=0 && up<9){
        m.copy(p.getPath()->back());
        std::iter_swap(m.getBegin() + spacePosition, m.getBegin() + up);
        m.estimateSpacePosition();
        m.estimateTotalCost();
        m.estimateKey();
        if(this->checkExplored(m.getKey())){
            if(count == 1)
                paths.erase(paths.begin()+min);
        }else if(count !=1){
            exploredMoves.push_back(m.getKey());
            p.addMove(m);
            paths.push_back(p);
        }else{
            exploredMoves.push_back(m.getKey());
            paths[min].addMove(m);
        }
        count--;
    }
    p.copy(paths[min]);
    if(count>=1&&right>=0 && right<9){
        m.copy(p.getPath()->back());
        std::iter_swap(m.getBegin()+ spacePosition, m.getBegin() + right);
        m.estimateSpacePosition();
        m.estimateTotalCost();
        m.estimateKey();
        if(checkExplored(m.getKey())){
            if(count == 1)
                paths.erase(paths.begin()+min);
        }else if(count !=1){
            exploredMoves.push_back(m.getKey());
            p.addMove(m);
            paths.push_back(p);
        }else{
            exploredMoves.push_back(m.getKey());
            paths[min].addMove(m);
        }
        count--;
    }
    p.copy(paths[min]);
    if(count>=1 && down>=0 && down<9){
        m.copy(p.getPath()->back());
        std::iter_swap(m.getBegin()+ spacePosition, m.getBegin() + down);
        m.estimateSpacePosition();
        m.estimateTotalCost();
        m.estimateKey();
        if(checkExplored(m.getKey())){
            if(count == 1)
                paths.erase(paths.begin()+min);
        }else if(count !=1){
            exploredMoves.push_back(m.getKey());
            p.addMove(m);
            paths.push_back(p);
        }else{
            exploredMoves.push_back(m.getKey());
            paths[min].addMove(m);
        }
        count--;
    }
    p.copy(paths[min]);
    if(count>=1 && left>=0 && left<9){
        m.copy(p.getPath()->back());
        std::iter_swap(m.getBegin()+ spacePosition, m.getBegin() + left);
        m.estimateSpacePosition();
        m.estimateTotalCost();
        m.estimateKey();
        if(checkExplored(m.getKey())){
            paths.erase(paths.begin()+min);
        }else if(count !=1){
            exploredMoves.push_back(m.getKey());
            p.addMove(m);
            paths.push_back(p);
        }else{
            exploredMoves.push_back(m.getKey());
            paths[min].addMove(m);
        }
        count--;
    }
    this->analyze();
}

void EightPuzzleSolver::showPath(){

    ui->pushButtonNext->setHidden(false);
    ui->pushButtonBack->setHidden(false);
    currentMove=1;
    QMessageBox::information(this,tr("Sloution found"),
            tr(" Press on the play button ▶ to show the next move \n"
               " and the back button ◀ to show the previous move"));
}
/** Checks if I reached to this move before or not */
bool EightPuzzleSolver::checkExplored(QString key){
    for(int i=0;i<exploredMoves.size();i++)
        if (exploredMoves[i]==key)
            return true;
    return false;
}

void EightPuzzleSolver::on_pushButtonExit_pressed()
{
    QMessageBox::information(this,tr("About program"),
        tr(" Here is some information about this program\n"
           " This program is programmed using C++ & Qt \n"
           " This was programmed by Ammar Sherif\n"
           " for more information read the README file"
           " Have a nice day."));
    this->close();
}

void EightPuzzleSolver::on_pushButtonNext_pressed()
{
    this->paths[this->correctPath].showMove(this->moveLabels,this->currentMove);
    if(paths[this->correctPath].getPath()->at(this->currentMove).checkReach())
        QMessageBox::information(this,tr("Goal Reached"),
            tr(" And here is your goal !."));
    else
        this->currentMove++;
}

void EightPuzzleSolver::on_pushButtonBack_pressed()
{
    this->currentMove--;
    this->paths[this->correctPath].showMove(this->moveLabels,this->currentMove);
    if(this->currentMove<1)
        this->currentMove=1;
}

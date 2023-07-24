#include<iostream>
#include <vector>
#include <queue>
#include "Cell.cpp"
using namespace std;

int RandomNo(int min, int max){
    int range = max - min + 1;
    int num = rand() % range + min;
    return num;
}

enum PlayerMove{
    Open,
    Mark
};

class Board{
    private:
    int size;
    int mines;
    int flags;
    int flagCount;
    int cellOpened;
    bool mineOpened;
    Cell **board;
    bool boardGenerated;
    vector<int> xCords;
    vector<int> yCords;

    
    public:
    Board(int size_, int mines_){
        size = size_;
        mines = mines_;
        flags  = mines;
        flagCount = flags;
        cellOpened = 0;
        mineOpened = false; 
        boardGenerated = false;
        board = new Cell *[size];
        for(int i = 0; i < size; i++){
            board[i] = new Cell [size]();
        }
    }

    void displayBoard(){
        cout<<"    ";
        for(int i = 0; i < size; i++){
            cout<<" "<<i+1<<"  ";
        }

        for(int i = 0; i < size; i++){
            cout<<endl;
            cout<<i+1<<"  ";
            for(int j =0; j<size; j++){
                cout<< "|";
                board[i][j].displayCell();
            }
            cout<< "|";
        }
    }

    void changeNeighnourCells(int row, int col){

        int minX,minY;
        int maxX, maxY;

        if(row-1 >= 0){
            minX = row -1;
        }else{
            minX = row;
        }

        if(col -1 >= 0){
            minY = col -1;
        }else{
            minY = col;
        }

        if(row + 1 <= size -1){
            maxX = row + 1;
        }
        else{
            maxX = row;
        }

        if(col + 1 <= size - 1){
            maxY = col + 1;
        }
        else{
            maxY = col;
        }

        for(int i = minX; i<= maxX; i++){
            for(int j = minY; j <= maxY; j++ ){
                board[i][j].incrementValue();
            }
        }
    }

    void generateBoard(int row, int col){

        int tempX, tempY;
        bool exists;

        for(int i =0; i<size; i++){
            do{
                exists = false;
                tempX = RandomNo(0, size-1);
                tempY = RandomNo(0, size-1);

                if(tempX == row && tempY == col){
                    exists = true;
                }
                else if(!xCords.empty() && !yCords.empty()){
                    for(int i =0; i < xCords.size(); i++){
                        if(tempX == xCords.at(i) && tempY == yCords.at(i)){
                            exists = true;
                            break;
                        }
                    }
                }
            }while(exists);

            board[tempX][tempY].setAsMine();
            xCords.push_back(tempX);
            yCords.push_back(tempY);
        }
        for(int i =0; i< mines; i++){
            changeNeighnourCells(xCords[i],yCords[i]);
        }
    }

    void openAdjacentCells(int row, int col, queue<int> *xQueue, queue<int> *yQueue, vector<int> *xVector, vector<int> *yVector){

        if(board[row][col].isMine() || board[row][col].isCellUnlocked()) return;

        bool alreadyPresent = false;

        if(!xVector->empty() && !yVector->empty()){
            for(int i = 0; i < xVector->size(); i++){
                if(xVector->at(i) == row && yVector->at(i) == col){
                    alreadyPresent = true;
                    break;
                }
            }
        }
        if(alreadyPresent) return;

        xQueue->push(row);
        yQueue->push(col);
        xVector->push_back(row);
        yVector->push_back(col);

        if(!board[row][col].checkForZero()) return;

        int minX,minY;
        int maxX, maxY;

        if(row-1 >= 0){
            minX = row -1;
        }else{
            minX = row;
        }

        if(col -1 >= 0){
            minY = col -1;
        }else{
            minY = col;
        }

        if(row + 1 <= size -1){
            maxX = row + 1;
        }
        else{
            maxX = row;
        }

        if(col + 1 <= size - 1){
            maxY = col + 1;
        }
        else{
            maxY = col;
        }

        for(int i = minX; i<= maxX; i++){
            for(int j = minY; j <= maxY; j++ ){
                if(i != row && j != col){
                    openAdjacentCells(i, j, xQueue, yQueue, xVector, yVector);
                }
            }
        }

    }

    bool clickCell(int row, int col){

        if(board[row][col].isFlagged()){
            cout<<"\n The Cell is Flagged already! Unflag it to open.\n";
            return false;
        }
        if(board[row][col].isCellUnlocked()){
            cout<<"\n The Cell is Open already! Try Again!\n";
            return false;
        }
        if(!board[row][col].isMine()){
            mineOpened = true;
            return false;
        }
        if(!board[row][col].checkForZero()){
            board[row][col].openCell();
            cellOpened++;
            return true;
        }
        else{

            queue<int> xQueue;
            queue<int> yQueue;
            vector<int> xVector;
            vector<int> yVector;
            openAdjacentCells(row, col, &xQueue, &yQueue, &xVector, &yVector);
            while(!xQueue.empty() && !yQueue.empty()){
                if(!board[xQueue.front()][yQueue.front()].isCellUnlocked()){
                    board[xQueue.front()][yQueue.front()].openCell();
                    cellOpened++;
                }
                xQueue.pop();
                yQueue.pop();
            }

        }
        return true;
    }

    bool playerSelect(int row, int col, PlayerMove playerMove){

        if(!boardGenerated && playerMove == Open){
            generateBoard(row, col);
            boardGenerated = true;
        }

        if(playerMove == Mark){
            
            if(board[row][col].isCellUnlocked()){
                cout<<"The cell is already open! Try Again!"<<endl;
                return false;
            }

            if(board[row][col].isFlagged()){
                board[row][col].triggerFlag();
                flagCount++;
            }
            else{
                if(flagCount > 0){
                    board[row][col].triggerFlag();
                    flagCount--;
                }else{
                    cout<<"No More Flags Available! Try Again!"<<endl;
                    return false;
                }
            }
            return true;
        }
        else if(playerMove == Open){
            if(!clickCell(row, col)){
                return false;
            }
        }
        return true;
    }

    int getCellsOpened(){
        return cellOpened;
    }

    bool getMineOpened(){
        return mineOpened;
    }

    void unlockMines(){
        for(int i = 0; i < mines; i++){
            board[xCords[i]][yCords[i]].openCell();
        }
    }

    ~Board(){
        for(int i = 0; i < size; i++){
            delete board[i];
        }
        delete board;
    }

};

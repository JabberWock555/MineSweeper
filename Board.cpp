#include<iostream>
#include <vector>
#include "Cell.cpp"
using namespace std;

int RandomNo(int min, int max){
    int range = max - min + 1;
    int num = rand() % range + min;
    return num;
}

class Board{
    private:
    int size;
    int mines;
    int flags;
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
        cellOpened = 0;
        mineOpened = false; 
        boardGenerated = false;
        board = new Cell *[size];
        for(int i = 0; i < size; i++){
            board[i] = new Cell [size]();
        }
    }

    void displayBoard(){

        for(int i = 0; i < size; i++){
            cout<<" "<<i<<" ";
        }

        for(int i = 0; i < size; i++){
            cout<<endl;
            cout<<i<<"  ";
            for(int j =0; j<size; j++){
                cout<< "|";
                board[i][j].displayCell();
            }
            cout<< "|";
        }
    }

    void generateBoard(int x, int y){

        int tempX, tempY;
        bool exists;

        for(int i =0; i<size; i++){
            do(
                exists = false;
                tempX = RandomNo(0, size);
                tempY = RandomNo(0, size);
                
            )while();
        }
    }
};

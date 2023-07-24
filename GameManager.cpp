#include<iostream>
#include "Board.cpp"
using namespace std;

int main()
{
    Board *board = new Board(10,2);

    board->displayBoard();
    return 0;
}
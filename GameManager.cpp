#include<iostream>
#include "Board.cpp"
using namespace std;

enum GameState{
    Playing,
    Win, 
    Lost
};

enum Difficulty{
    Easy,
    Medium,
    Hard
};

class MineSweeper{
    
    private:
    Board *board;
    int size;
    int mines;
    Difficulty difficulty;
    GameState gameState;

    public:
    MineSweeper(){
        gameState = Playing;
        instructions();
        setDifficulty();
        createBoard();

    }

    void instructions(){

    cout << "Welcome to Text-based Minesweeper!\n";
    cout << "In this classic game, your goal is to reveal all the safe tiles on the board while avoiding hidden mines.\n";
    cout << "You will be presented with a grid of cells, each containing either a number indicating how many mines are adjacent to it or an undiscovered tile.\n";
    cout << "Your task is to carefully analyze the numbers and strategically place flags on tiles you suspect to be mines.\n";
    cout << "Be cautious! If you accidentally reveal a mine, the game will be over.\n";
    cout << "Choose your moves wisely, and test your luck and deduction skills in this challenging adventure.\n";
    cout << "\nInstructions:\n";
    cout << "1. Setting Difficulty:\n";
    cout << "   - At the start of the game, you will be prompted to choose a difficulty level: Easy, Medium, or Hard.\n";
    cout << "   - Each difficulty level determines the size of the grid and the number of mines hidden on the board:\n";
    cout << "     - Easy: 10x10 grid with 15 mines.\n";
    cout << "     - Medium: 12x12 grid with 20 mines.\n";
    cout << "     - Hard: 15x15 grid with 30 mines.\n";
    cout << "2. Gameplay:\n";
    cout << "   - Once you've selected a difficulty level, the game board will be displayed with all cells hidden.\n";
    cout << "   - You will take turns to enter the row and column numbers of the cell you wish to interact with.\n";
    cout << "   - Then, you must select an action for the chosen cell:\n";
    cout << "     - To open a cell, type 1. This action reveals the content of the cell.\n";
    cout << "     - To flag a cell, type 2. This action places a flag on the cell, indicating you suspect it contains a mine.\n";
    cout << "3. Game Rules:\n";
    cout << "   - Cells will be numbered with the count of adjacent mines, ranging from 0 to 8.\n";
    cout << "   - If you open a cell with no adjacent mines (number 0), the adjacent cells will automatically be opened until cells with numbers are reached.\n";
    cout << "   - If you open a cell containing a mine, the game ends immediately, and you lose.\n";
    cout << "   - You win the game when all non-mine cells are opened, and no incorrect flags are placed.\n";
    cout << "4. Display Legend:\n";
    cout << "   - The game board will use the following symbols to represent various states:\n";
    cout << "     - \"Blank\" - An undiscovered cell.\n";
    cout << "     - \"F\" - A flagged cell.\n";
    cout << "     - \"*\" - A cell with a mine (displayed if you lose the game).\n";
    cout << "     - \"0\" to \"8\" - Cells with numbers indicating the count of adjacent mines.\n";
    cout << "5. Playing the Game:\n";
    cout << "   - To make a move, enter the row number, column number, and the action (O or F) when prompted.\n";
    cout << "   - For example, to open row 2, column 3, you would enter \"2 3 O\" (without quotes).\n";
    cout << "   - To flag row 4, column 5, you would enter \"4 5 F\" (without quotes).\n";
    cout << "6. Winning and Losing:\n";
    cout << "   - You win the game if you successfully open all non-mine cells on the board.\n";
    cout << "   - You lose the game if you open a cell containing a mine.\n";
    cout << "7. Enjoy the Game:\n";
    cout << "   - Use your logic, deduction skills, and a bit of luck to navigate the minefield.\n";
    cout << "   - Challenge yourself by improving your score and speed as you become a Minesweeper expert!\n";
    cout << "\nRemember, the game might seem intimidating at first, but with practice, you'll improve your strategies and become a Minesweeper master.\n";
    cout << "Good luck and have fun playing Text-based Minesweeper!\n";
    }

    void setDifficulty(){
        
        int option = 1;
        do{
            if(option < 1 || option > 3){
                cout<<"\nPlease Enter a valid Input!\n";
            }

            cout<<"\n Enter the Difficulty Level: \n";

            cout<<"\n 1 - Beginner\n 2 - Intermediate\n 3 - Expert\n";
            cin >> option;
        }while(option < 1 || option > 3);
        difficulty = (Difficulty)(option-1);
    }

    void createBoard(){

        switch(difficulty){

            case Easy:
            size = EASY_SIZE;
            mines = EASY_MINES;
            break;

            case Medium:
            size = MEDIUM_SIZE;
            mines = MEDIUM_MINES;
            break;
            
            case Hard:
            size = HARD_SIZE;
            mines = HARD_MINES;
            break;

        }
        board = new Board(size, mines);
    }

    void Play(){

        do{
            board->displayBoard();
            getInput();
        }while(gameState == Playing);

        if(gameState == Lost){
            cout<<"\nYou have Opened a Mine\n";
            board->unlockMines();
            board->displayBoard();
            cout<<"\nBetter Luck Next Time!\n";
        }
        else if(gameState == Win){
            cout<<"\nCongratulations! You've Won the Game.\n";
            board->unlockMines();
            board->displayBoard();
            cout<<"\nThank you for Playing!\n";
        }
    }

    void getInput(){
        int row = 1;
        int col = 1;
        PlayerMove playerMove;
        int input = 1;

        do{
            if(board->getMineOpened()){
                gameState = Lost;
                return;
            }

            do{
                if(row < 1 || row >size){
                    cout<<"\nPlease Enter a valid Input!\n";
                }
                cout<<"\nEnter row : ( 1 - "<<size<<" ) "<<endl;
                cin >> row;
            }while(row < 1 || row >size);

            do{
                if(col < 1 || col >size){
                    cout<<"\nPlease Enter a valid Input!\n";
                }
                cout<<"\nEnter column : ( 1 - "<<size<<" ) "<<endl;
                cin >> col;
            }while(col < 1 || col >size);

            do{
                if(input < 1 || input > 2){
                    cout<<"\nPlease Enter a valid Input!\n";
                }
                cout<<"\nSelect Operation : ( 1 - Open | 2 - Flag/Unflag"<<endl;
                cin >> input;
            }while(input < 1 || input > 2);

            if(input == 1 ){
                playerMove = Open;
            }else{
                playerMove = Mark;
            }
        }while(!board->playerSelect(row -1, col -1, playerMove));
        
        if(playerMove == Open){
            checkWin();
        }
    }

    void checkWin(){

        int cellsOpened = board->getCellsOpened();
        if(cellsOpened == (size * size) - mines)
        gameState = Win;
    }

    ~MineSweeper(){
        delete board;
    }

};

int main()
{
    MineSweeper minesweeper;
    minesweeper.Play();
}
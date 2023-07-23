#include<iostream>
using namespace std;
#define EASY_SIZE 10;
#define MEDIUM_SIZE 12;
#define HARD_SIZE 15;
#define EASY_MINES 15;
#define MEDIUM_MINES 20;
#define HARD_MINES 30;

enum cellType{
safe,
mine
};

enum cellStatus{
locked,
flagged,
unlocked
};

int charToInt(char ch){
    int x = (int(ch) - 48);
    return x;
}

char intToChar(int x) {
    char ch = '0' + static_cast<char>(x);
    return ch;
}

class Cell{
    private: 
    char value;
    cellType type;
    cellStatus status;

    public:
    Cell(){
        value = '0';
        type = safe;
        status = locked;
    }

    void setAsMine(){
        type = mine;
        value = '*';
    }

    void displayCell(){
        switch(status){
            case locked:
            cout<<"   ";
            break;

            case flagged:
            cout<<" F ";
            break;

            case unlocked:
            cout<<" "<< value<<" ";
            break;
        }
    }

    bool isCellUnlocked(){
        return status == unlocked;
    }

    bool checkForZero(){
        return value == '0';
    }

    bool isFlagged(){
        return status == flagged;
    }

    bool isMine(){
        return type == mine;
    }

    void triggerFlag(){
        if(status == locked)
        status = flagged;
        else if(status == flagged)
        status = locked;
    }

    void openCell(){
        status = unlocked;
    }

    void incrementValue(){
        int x = charToInt(value);
        x++;
        value = intToChar(x);
    }

};

#include<iostream>
using namespace std;

enum cellType{
safe,
mine
};

enum cellStatus{
locked,
flagged,
unlocked
};

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
    }

    void displayCell(){
        switch(type){
            case 0:
            cout<<value;
            break;

            case 1:
            cout<<'*';
            break;
        }
    }

    bool isCellLocked(){
        return status == locked;
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

};

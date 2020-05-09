#include <iostream>
#include <string>
#include"functions.h"
using namespace std;
/*This function is used to let the player replay the game. The input is 1(yes) or 2 (No).the program will let user input again if he input 
another number.The output is the user replay the game or stop it.*/
int main(){
    string again;
    start();
    cout<<"Play again (1. Yes 2. No)? ";//can play game again
    cin>>again;
    while(again!="1"&&again!="2"){
        cout<<"Please enter 1 or 2 (1. Yes 2. No): ";//re-input for invalid input
        cin>>again;
    }
    while(again=="1"){
        cout<<"\n\n";
        start();
        cout<<"Play again (1. Yes 2. No)? ";
        cin>>again;
        while(again!="1"&&again!="2"){
            cout<<"Please enter 1 or 2 (1. Yes 2. No): ";
            cin>>again;
        }
    }
    return 0;
}

#include <iostream>
#include <string>
#include"functions.cpp"
using namespace std;
/*This function is used to let player replay the game after the one trial is end.Input is 1. Yes or 2. No,and the program will require you to 
input again if you input another number.The output is you replay the game or stop it.*/
int main(){
    string again;
    start();
    cout<<"Play again (1. Yes 2. No)? ";
    cin>>again;
    while(again!="1"&&again!="2"){
        cout<<"Please enter 1 or 2 (1. Yes 2. No): ";
        cin>>again;
    }
    while(again=="1"){
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

#include <iostream>
#include <string>
#include"functions.cpp"
using namespace std;
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

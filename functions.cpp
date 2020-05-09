#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*this function is to let the player input his name and define whether the adventure is a success or a faliure. Input is the player name,
output is the outcome of the adventure*/
void start(){
    string name;
    int n;
    cout<<"Welcome! Please enter your name (shorter than 20 characters): ";
    cin>>name;
    ofstream fout;
    fout.open("player.txt");
    fout << name <<" "<<500<<" "<<0<<endl;
    fout.close();
    ifstream fin;
    fin.open("monsters.txt");
    fin>>n;
    fin.close();
    for(int i=0;i<n;i++){
        if(stage(i+1)==0){
            cout<<"You lose!"<<endl;
        }
    }
    cout<<"You beat all monsters, congratulations!"<<endl;
}
/*This function is to read the state of the player and the monster in the n+1 turn.It's input is the turn number-1,the output is the 
introduction of the both side of the battle*/
int stage(int n){
    int end;
    int win;
    string pname,mname;
    int php,pmp,mhp,mmp=0;
    ifstream fin;
    int num;
    string s;
    fin.open("player.txt");
    fin>>pname>>php>>pmp;
    fin.close();
    fin.open("monsters.txt");
    fin>>num;
    string *mnames = new string[num];
    int *mhps = new int[num];
    for(int i=0;i<num;i++){
        fin>>mnames[i]>>mhps[i];
    }
    mhp=mhps[n];
    mname=mnames[n];
    delete[] mnames;
    delete[] mhps;
    cout<<"Stage "<<n+1<<": "<<pname<<" vs "<<mname<<endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
using namespace std;
int stage(int);
void story(int);
/*This function is uesd let the player make his name, in the while loop it will post the crossing discription for every part.It will define
whether the player win the game or lose it,the input is the name of the player, the output */
int start(){
    string name, s;
    int n;
    ifstream fin;
    fin.open("Crossing-discription.txt");
    while(fin>>s){
        if(s=="End"){
            break;
        }
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<endl;
    fin.close();
    cout<<"Welcome new adventurer! Please enter your name (shorter than 20 characters): ";
    cin>>name;
    ofstream fout;
    fout.open("player.txt");
    fout<<name<<" "<<500<<" "<<0<<endl;
    fout.close();
    fin.open("monsters.txt");
    fin>>n;
    fin.close();
    for(int i=0;i<n;i++){
        if(stage(i)==0){
            cout<<"You lose!"<<endl;
            return 0;
        }
    }
    cout<<"You beat all monsters, congratulations!"<<endl;
    return 0;
}
/*The funtion is used to control the player action.Four number stands for different action and if player input other number, the program will
require pplayer to input again.Input:player's inputed number,output:the change in MP,HP and the monster's HP*/
void move(string s, int *a, int *b, int *c, int *d){
    if(s=="1"){
        *c-=20;
        if(*c<0){
            *c=0;
        }
    }
    else if(s=="3"){
        *a+=50;
        *b-=50;
        if(*a<0){
            *a=0;
        }
    }
    else if(s=="2"){
        *b+=20;
        if(*b>500){
            *b=500;
        }
    }
    else if(s=="4"){
        *c-=100;
        *b-=100;
        if(*c<0){
            *c=0;
        }
    }
        }
    else {
        cout<<"Please input again."<<endl;
        move(string s, int *a, int *b, int *c, int *d)
    }
}
/*This function is used to post the crossing-discription of the game,the loop will output the crossing-discription of the current part*/
void story(int n){
    string s;
    ifstream fin;
    cout<<endl;
    fin.open("Crossing-discription.txt");
    for(int i =0;i<n+1;i++){
        while(fin>>s){
            if(s=="End"){
                break;
            }
        }
    }
    while(fin>>s){
        if(s=="End"){
            break;
        }
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<endl;
    fin.close();
}

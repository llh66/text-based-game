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
require player to input again.Input:player's inputed number,output:the change in MP,HP and the monster's HP*/
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
        if(*a>500){
            a=500;
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
/*This function is used to read the state of the player and the monster.It will define that whether the MP is enough to use some skills and 
ensure that the proper use of the skill.It will then deteermine the winner of the battle and recover the player, then it will start next
part of the game.Input:the turn "n",output:the outcome of the battle,the state of player.*/
int stage(int n){
    int exp;
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
    exp=mhp/2;
    delete[] mnames;
    delete[] mhps;
    story(n);
    cout<<pname<<": "<<php<<"/500 HP "<<pmp<<"/500 MP"<<endl;
    cout<<mname<<": "<<mhp<<"/500 HP "<<mmp<<"/500 MP"<<endl;
    cout<<endl;
    cout<<"Adventurer "<<pname<<", please choose a move (1. Attack (20 damage) 2. Rest (+20 MP)";
    if(pmp<50){
        cout<<"): ";
        cin>>s;
        while(s!="1"&&s!="2"){
            cout<<"Please enter 1 or 2: ";
            cin>>s;
        }
    }
    else if(pmp<100){
        cout<<" 3. Recover (+50 HP, -50 MP)): ";
        cin>>s;
        while(s!="1"&&s!="2"&&s!="3"){
            cout<<"Please enter 1, 2, or 3: ";
            cin>>s;
        }
    }
    else{
        cout<<" 3. Recover (+50 HP, -50 MP) 4. Skill attack (100 damage, -100 MP)): ";
        cin>>s;
        while(s!="1"&&s!="2"&&s!="3"&&s!="4"){
            cout<<"Please enter 1, 2, 3 or 4: ";
            cin>>s;
        }
    }
    move(s, &php, &pmp, &mhp, &mmp);
    cout<<pname<<": "<<php<<"/500 HP "<<pmp<<"/500 MP"<<endl;
    cout<<mname<<": "<<mhp<<"/500 HP "<<mmp<<"/500 MP"<<endl;
    cout<<endl;
    while(mhp>0&&php>0){
        srand((unsigned int)time(0));
        if(mmp<50){
            s=49+rand()%2;
        }
        else if(mmp<100){
            s=49+rand()%3;
        }
        else{
            s=49+rand()%4;
        }
        move(s, &mhp, &mmp, &php, &pmp);
        if(s=="1"){
            cout<<mname<<" attacks you."<<endl;
        }
        else if(s=="2"){
            cout<<mname<<" takes a rest."<<endl;
        }
        else if(s=="3"){
            cout<<mname<<" recovers"<<endl;
        }
        else if(s=="4"){
            cout<<mname<<" uses skill attack"<<endl;
        }
        cout<<pname<<": "<<php<<"/500 HP "<<pmp<<"/500 MP"<<endl;
        cout<<mname<<": "<<mhp<<"/500 HP "<<mmp<<"/500 MP"<<endl;
        cout<<endl;
        if(php==0){
            cout<<mname<<" beats you."<<endl;
            return 0;
        }
        cout<<"End of the round, MP rises 20"<<endl;
        pmp+=20;
        mmp+=20;
        if(pmp>500){
            pmp=500;
        }
        if(mmp>500){
            mmp=500;
        }
        cout<<pname<<": "<<php<<"/500 HP "<<pmp<<"/500 MP"<<endl;
        cout<<mname<<": "<<mhp<<"/500 HP "<<mmp<<"/500 MP"<<endl;
        cout<<endl;
        cout<<"Adventurer "<<pname<<", please choose a move (1. Attack (20 damage) 2. Rest (+20 MP)";
        if(pmp<50){
            cout<<"): ";
            cin>>s;
            while(s!="1"&&s!="2"){
                cout<<"Please enter 1 or 2: ";
                cin>>s;
            }
        }
        else if(pmp<100){
            cout<<" 3. Recover (+50 HP, -50 MP)): ";
            cin>>s;
            while(s!="1"&&s!="2"&&s!="3"){
                cout<<"Please enter 1, 2, or 3: ";
                cin>>s;
            }
        }
        else{
            cout<<" 3. Recover (+50 HP, -50 MP) 4. Skill attack (100 damage, -100 MP)): ";
            cin>>s;
            while(s!="1"&&s!="2"&&s!="3"&&s!="4"){
                cout<<"Please enter 1, 2, 3 or 4: ";
                cin>>s;
            }
        }
        move(s, &php, &pmp, &mhp, &mmp);
        cout<<pname<<": "<<php<<"/500 HP "<<pmp<<"/500 MP"<<endl;
        cout<<mname<<": "<<mhp<<"/500 HP "<<mmp<<"/500 MP"<<endl;
        cout<<endl;
    }
    if(num-1!=n){
        cout<<"You win, MP rises 20"<<endl;
        pmp+=20;
        if(pmp>500){
            pmp=500;
        }
        cout<<pname<<": "<<php<<"/500 HP "<<pmp<<"/500 MP"<<endl;
        cout<<"You gained "<<exp<<" exp. , please choose to convert into 1. "<<exp<<" HP 2. "<<exp<<" MP: ";
        cin>>s;
        while(s!="1"&&s!="2"){
            cout<<"Please enter 1 or 2: ";
            cin>>s;
        }
        if(s=="1"){
            php+=exp;
        }
        else if(s=="2"){
            pmp+=exp;
        }
        if(php>500){
            php=500;
        }
        if(pmp>500){
            pmp=500;
        }
        ofstream fout;
        fout.open("player.txt");
        fout<<pname<<" "<<php<<" "<<pmp<<endl;
        fout.close();
    }
    else{
        story(n+1);
    }
    return 1;
}
#endif

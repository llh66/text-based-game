#include <iostream>
#include <fstream>
using namespace std;
int main(){
    char name[20];
    cout<<"Welcome! Please enter your name (shorter than 20 characters):";
    cin>>name;
    ofstream fout;
    fout.open("player.txt");
    fout << name <<" "<<500<<" "<<0<<endl;
    fout.close();
    return 0;
}

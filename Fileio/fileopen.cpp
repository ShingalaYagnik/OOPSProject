#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
int main(){
    cout<<int('0')-48;
ofstream op;
op.open("sample.txt");
op<<"cout ooo\noooop\n";
op<<"enter\n";
 op.close();
ifstream ip;
ip.open("sample.txt");
char ch;

ch=ip.get();
while(!ip.eof()){
    cout<<ch;
    ch=ip.get();
}
//system("CLS");

cout<<"asas";

}

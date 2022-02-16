#include<iostream>
#include<fstream>
using namespace std;

int main(){

ofstream fout;
fout.open("example.txt");
int data=12;
fout<<data<<endl;
cout<<data<<endl;
string str="Yagjkkkkkkkkkkkkkkkkkknik";
fout<<str<<endl;
cout<<str<<endl;

bool tr=true;
fout<<tr<<endl;
cout<<tr<<endl;

fout.close();

ifstream fin;
fin.open("example.txt");
int datar;
fin>>datar;
datar*=2;
cout<<datar<<endl;


string strr;
fin>>strr;
cout<<strr<<endl;

bool trr;
fin>>trr;
cout<<trr<<endl;
fin.close();
}

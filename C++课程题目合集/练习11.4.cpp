#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream outfile,infile;
    outfile.open("herb.txt",ios::out);
    outfile << "Rosemary\n" << "Lavender\n";
    outfile << "Sage mint\n";
    outfile.close();
    infile.open("herb.txt",ios::in);
    char textline[80];
    while(! infile.eof()){
        infile.getline(textline,sizeof(textline));
        cout<<textline<<endl;
    }
}   

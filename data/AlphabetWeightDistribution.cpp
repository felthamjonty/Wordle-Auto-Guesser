#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

int main(){
    unordered_map<char, int> commonLetters = {
        {'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0}, {'w',0}, {'x',0},{'y',0},{'z',0}
    };

    ifstream myfile;
    myfile.open ("valid-wordsAdjusted.txt");
    if(myfile.is_open()){
        string curLine;
        int numLine=1;
        
        while (getline(myfile,curLine)){
            cout<<"Checking Line: "<<numLine<<"\n";
            numLine++;
            for (int i = 0; i<curLine.length(); i++){
                commonLetters[curLine[i]]++;
            }
        }
    }
    myfile.close();

    string alph = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i<alph.length(); i++){
        cout<<"{'"<<alph[i]<<"',"<<commonLetters[alph[i]]<<"},";
    }

    return 0;
}

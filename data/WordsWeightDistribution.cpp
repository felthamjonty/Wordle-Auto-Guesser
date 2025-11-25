#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

int main(){
    unordered_map<char, int> commonLetters = {
        {'a',6415},{'b',1659},{'c',1920},{'d',2458},{'e',6572},{'f',1079},{'g',1643},{'h',1700},{'i',3922},{'j',323},{'k',1610},{'l',3278},{'m',2195},{'n',3068},{'o',4662},{'p',2188},{'q',123},{'r',4078},{'s',6881},{'t',3165},{'u',2613},{'v',693},{'w',996},{'x',295},{'y',2140},{'z',474}
    };

    ifstream myfile;
    myfile.open ("valid-wordsAdjusted.txt",ios::in);
    ofstream writeTo;
    writeTo.open ("weighted-wordle-words.txt",ios::out);
    if(myfile.is_open()&&writeTo.is_open()){
        string curLine;
        int lineValBest=0;
        string bestWord = "";
        while (getline(myfile,curLine)){
            unordered_map<char, bool> doubleCheck={};
            int lineVal = 0;
            for (int i = 0; i<curLine.length(); i++){
                if(doubleCheck.find(curLine[i])==doubleCheck.end()){
                    lineVal+=commonLetters[curLine[i]];
                    doubleCheck[curLine[i]]=true;
                }
            }
            writeTo<<curLine<<" : "<<lineVal<<"\n";
            if(lineVal>lineValBest){
                lineValBest=lineVal;
                bestWord=curLine;
            }
            cout<<"Most Valuable Word: "<< bestWord <<" : "<<lineValBest<<"\n";
        }
    }
    myfile.close();
    writeTo.close();

    return 0;
}

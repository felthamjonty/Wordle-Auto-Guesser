#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

int main(){
    unordered_map<char, int> commonLetters = {
        {'a',7128},{'b',1849},{'c',2246},{'d',2735},{'e',7455},{'f',1240},{'g',1864},{'h',1993},{'i',4381},{'j',342},{'k',1753},{'l',3780},{'m',2414},{'n',3478},{'o',5212},{'p',2436},{'q',145},{'r',4714},{'s',7319},{'t',3707},{'u',2927},{'v',801},{'w',1127},{'x',326},{'y',2400},{'z',503}
    };

    ifstream myfile;
    myfile.open ("valid-wordle-words.txt",ios::in);
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

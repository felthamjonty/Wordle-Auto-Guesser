#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    unordered_map<string, int> foundWords;

    ifstream myfile;
    myfile.open ("past-wordles.txt",ios::in);
    if(myfile.is_open()){
        string curLine;
        while (getline(myfile,curLine)){
            transform(curLine.begin(),curLine.end(),curLine.begin(),::tolower);
            curLine = curLine.substr (0,5);
            foundWords[curLine]++;
        }
    }
    myfile.close();

    myfile.open ("valid-wordle-words.txt",ios::in);
    ofstream writeTo;
    writeTo.open ("valid-wordsAdjusted.txt",ios::out);
    if(myfile.is_open()&&writeTo.is_open()){
        string curLine;
        int lineValBest=0;
        string bestWord = "";
        while (getline(myfile,curLine)){
            
            if(foundWords.find(curLine)==foundWords.end()){
                cout<<curLine<<":";
                writeTo<<curLine<<"\n";
            }
            
            
        }
    }
    myfile.close();
    writeTo.close();

    return 0;
}

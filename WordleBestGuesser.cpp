#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

int main(){
    unordered_map<char, int> commonLetters = {
        {'a',7128},{'b',1849},{'c',2246},{'d',2735},{'e',7455},{'f',1240},{'g',1864},{'h',1993},{'i',4381},{'j',342},{'k',1753},{'l',3780},{'m',2414},{'n',3478},{'o',5212},{'p',2436},{'q',145},{'r',4714},{'s',7319},{'t',3707},{'u',2927},{'v',801},{'w',1127},{'x',326},{'y',2400},{'z',503}
    };
    
    string knownLetters="-----";
    unordered_map<char, bool> voidLetters={};
    
    string myWord="banne";
    string myGuess="00002";

    for(int i=0; i<myWord.length(); i++){
        if(knownLetters[i]=='-'){
            if(myGuess[i]=='2'){
                knownLetters[i]=myWord[i];
            }
        }
        if(myGuess[i]=='0'){
            voidLetters[myWord[i]]=true;
        }
    }

    int givenWords = 5;
    vector<int> lineValBest = {};
    vector<string> bestWord = {};

    ifstream myfile;
    myfile.open ("valid-wordle-words.txt",ios::in);
    if(myfile.is_open()){
        string curLine;
        while (getline(myfile,curLine)){
            unordered_map<char, bool> doubleCheck={};
            int lineVal = 0;
            for (int i = 0; i<curLine.length(); i++){
                if(doubleCheck.find(curLine[i])==doubleCheck.end()){
                    lineVal+=commonLetters[curLine[i]];
                    doubleCheck[curLine[i]]=true;
                }
            }
            int lineValSmallest = -1;
            for (int i = 0; i<lineValBest.size(); i++){
                if(lineValSmallest==-1||lineValSmallest<lineValBest[i]){
                    lineValSmallest=lineValBest[i];
                }
            }
            if(lineVal>lineValSmallest || bestWord.size()<=givenWords){
                bool acceptable = true;
                for(int i=0; i<curLine.length(); i++){
                    if(knownLetters[i]!='-'&&knownLetters[i]!=curLine[i]){
                        acceptable=false;
                        break;
                    }
                    if(voidLetters.find(curLine[i])!=voidLetters.end()){
                        acceptable=false;
                        break;
                    }
                }
                if (acceptable){
                    for (int i = 0; i<lineValBest.size(); i++){
                        if(lineVal>lineValBest[i]){
                            lineValBest.insert(lineValBest.begin()+i,lineVal);
                            bestWord.insert(bestWord.begin()+i,curLine);
                            break;
                        }
                    }
                    if(lineValBest.size()<5){
                        lineValBest.push_back(lineVal);
                        bestWord.push_back(curLine);
                    }
                    if(lineValBest.size()>5){
                        cout<<"a"<<"\n";
                        lineValBest.pop_back();
                        bestWord.pop_back();
                        cout<<"b"<<"\n";
                    }
                }
            }
            if(lineValBest.size()>0){
                cout<<"Most Valuable Word: "<< bestWord[0] <<" : "<<lineValBest[0]<<"\n";
            }
        }
    }
    myfile.close();

    cout<<"Most Valuable Word: \n";
    for (int i = 0; i<bestWord.size(); i++){
        cout<< bestWord[i] <<" : "<<lineValBest[i]<<"\n";
    }
    
    return 0;
}

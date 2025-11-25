#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    unordered_map<char, int> commonLetters = {
        {'a',7128},{'b',1849},{'c',2246},{'d',2735},{'e',7455},{'f',1240},{'g',1864},{'h',1993},{'i',4381},{'j',342},{'k',1753},{'l',3780},{'m',2414},{'n',3478},{'o',5212},{'p',2436},{'q',145},{'r',4714},{'s',7319},{'t',3707},{'u',2927},{'v',801},{'w',1127},{'x',326},{'y',2400},{'z',503}
    };
    
    srand(time(0));

    string knownLetters="-----";
    unordered_map<char, bool> voidLetters={};
    unordered_map<char, vector<int>> shuffledLetters={};
    
    string myWord="";
    string myGuess="";
    bool exitCond=false;
    bool option = true;
    string input;
    cout<<"Welcome To The Wordle Auto Word Generator!!\n";
    cout<<"-------------------------------------\n";
    while(!exitCond){
        exitCond=true;
        cout<<"Please Choose A Starter Word:\n";
        cout<<"1. Best Word:\n";
        cout<<"2. Random Word:\n";
        cout<<"3. Input My Own:\n";
        cin>>input;

        if(input=="1"){
            myWord="";
            myGuess="";
            option=true;
        }else if(input=="2"){
            option=false;
        }else if(input=="3"){
            option=false;
        }else{
            exitCond=false;
        }
    }

    while (myGuess!="22222"){
        if(option)
        {
            if(myWord!=""){
                for(int i=0; i<myWord.length(); i++){
                    if(knownLetters[i]=='-'){
                        if(myGuess[i]=='2'){
                            knownLetters[i]=myWord[i];
                            bool corrector = true;
                            for(int ii=0; ii<shuffledLetters[myWord[ii]].size(); ii++){
                                if(shuffledLetters[myWord[ii]][i]==i){
                                    corrector = false;
                                    break;
                                }
                            }
                            if (corrector){
                                shuffledLetters.erase(myWord[i]);
                            }
                        }
                    }
                    if(myGuess[i]=='1'){
                        shuffledLetters[myWord[i]].push_back(i);
                    }
                    if(myGuess[i]=='0'){
                        if(shuffledLetters.find(myWord[i])==shuffledLetters.end()){
                            voidLetters[myWord[i]]=true;
                        }
                    }
                }
            }

            int givenWords = 5;
            vector<int> lineValBest = {};
            vector<string> bestWord = {};

            ifstream myfile;
            myfile.open ("valid-wordsAdjusted.txt",ios::in);
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
                            if(shuffledLetters.find(curLine[i])!=shuffledLetters.end()){
                                bool breakage=false;
                                for(int ii=0; ii<shuffledLetters[curLine[i]].size(); ii++){
                                    if(i==shuffledLetters[curLine[i]][ii]){
                                        acceptable=false;
                                        breakage=true;
                                        break;
                                    }
                                }
                                if (breakage){
                                    break;
                                }
                            }
                            if(voidLetters.find(curLine[i])!=voidLetters.end()){
                                acceptable=false;
                                break;
                            }
                        }
                        if (acceptable){
                            string alph = "abcdefghijklmnopqrstuvwxyz";
                            for (int i = 0; i<alph.length(); i++){
                                if(shuffledLetters.find(alph[i])!=shuffledLetters.end()&&shuffledLetters[alph[i]].size()>0){
                                    bool letterFound=false;
                                    for(int ii=0; ii<curLine.length(); ii++){
                                        if(curLine[ii]==alph[i]){
                                            letterFound=true;
                                            break;
                                        }
                                    }
                                    if(!letterFound){
                                        acceptable=false;
                                        break;
                                    }
                                }
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
                                lineValBest.pop_back();
                                bestWord.pop_back();
                            }
                        }
                    }
                    // if(lineValBest.size()>0){
                    //     cout<<"Most Valuable Word: "<< bestWord[0] <<" : "<<lineValBest[0]<<"\n";
                    // }
                }
            }
            myfile.close();

            cout<<"\n";
            cout<<"Most Valuable Word: \n";
            for (int i = 0; i<bestWord.size(); i++){
                cout<< bestWord[i] <<" : "<<lineValBest[i]<<"\n";
            }
            if(bestWord.size()==0){
                cout<<"There are no more available words \n";
            }
        }else{
            if(input=="2"){
                int randNum=rand() % 7427;
                randNum+=rand() % 7427;

                ifstream myfile;
                myfile.open ("valid-wordle-words.txt",ios::in);
                if(myfile.is_open()){
                    int lineNum=0;
                    string curLine;
                    while (getline(myfile,curLine)){
                        if(lineNum==randNum){
                            cout<<curLine;
                            break;
                        }
                        lineNum++;
                    }
                }
                myfile.close();
            }
        }
        option=true;
        exitCond=false;
        while(!exitCond){
            exitCond=true;
            cout<<"\n";
            cout<<"Input The Word You've Used:\n";
            cin>>myWord;
            if(myWord.length()!=5){
                exitCond=false;
            }
            std::transform(myWord.begin(), myWord.end(), myWord.begin(),
                    [](unsigned char c){ return std::tolower(c); });
        }
        exitCond=false;
        while(!exitCond){
            exitCond=true;
            cout<<"\n";
            cout<<"Input The Accuracy You Got:\n";
            cout<<"(0=black/gray, 1=yellow, 2=green)\n";
            cout<<"(eg. 00021)\n";
            cin>>myGuess;
            if(myGuess.length()!=5){
                exitCond=false;
            }else{
                for(int i=0; i<5; i++){
                    if(myGuess[i]!='0'&&myGuess[i]!='1'&&myGuess[i]!='2'){
                        exitCond=false;
                    }
                }
            }
        }
    }
    
    cout<<"Well Done!";
    return 0;
}

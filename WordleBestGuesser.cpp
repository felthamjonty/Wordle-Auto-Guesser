#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

int main(){
    unordered_map<char, int> commonLetters = {
        //{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0}, {'w',0}, {'x',0},{'y',0},{'z',0}
        {'a',7128},{'b',1849},{'c',2246},{'d',2735},{'e',7455},{'f',1240},{'g',1864},{'h',1993},{'i',4381},{'j',342},{'k',1753},{'l',3780},{'m',2414},{'n',3478},{'o',5212},{'p',2436},{'q',145},{'r',4714},{'s',7319},{'t',3707},{'u',2927},{'v',801},{'w',1127},{'x',326},{'y',2400},{'z',503},
    };

    // ifstream myfile;
    // myfile.open ("valid-wordle-words.txt");
    // if(myfile.is_open()){
    //     string curLine;
    //     int numLine=1;
        
    //     while (getline(myfile,curLine)){
    //         cout<<"Checking Line: "<<numLine<<"\n";
    //         numLine++;
    //         for (int i = 0; i<curLine.length(); i++){
    //             commonLetters[curLine[i]]++;
    //         }
    //     }
    // }
    // myfile.close();

    // string alph = "abcdefghijklmnopqrstuvwxyz";

    // for (int i = 0; i<alph.length(); i++){
    //     cout<<"{'"<<alph[i]<<"',"<<commonLetters[alph[i]]<<"},";
    // }

    //-----------------------------------------------------------------
    
    // ifstream myfile;
    // myfile.open ("valid-wordle-words.txt",ios::in);
    // ofstream writeTo;
    // writeTo.open ("weighted-wordle-words.txt",ios::out);
    // if(myfile.is_open()&&writeTo.is_open()){
    //     string curLine;
    //     int lineValBest=0;
    //     string bestWord = "";
    //     while (getline(myfile,curLine)){
    //         unordered_map<char, bool> doubleCheck={};
    //         int lineVal = 0;
    //         for (int i = 0; i<curLine.length(); i++){
    //             if(doubleCheck.find(curLine[i])==doubleCheck.end()){
    //                 lineVal+=commonLetters[curLine[i]];
    //                 doubleCheck[curLine[i]]=true;
    //             }
    //         }
    //         writeTo<<curLine<<" : "<<lineVal<<"\n";
    //         if(lineVal>lineValBest){
    //             lineValBest=lineVal;
    //             bestWord=curLine;
    //         }
    //         cout<<"Most Valuable Word: "<< bestWord <<" : "<<lineValBest<<"\n";
    //     }
    // }
    // myfile.close();
    // writeTo.close();

    //-----------------------------------------------------------------
    
    string myWord="banne";
    string myGuess="00002";

    string wordLine = "apple";
    bool Acceptable = false;
    for(int i=0; i<wordLine.length(); i++){
        /* code */
    }
    

    return 0;
}

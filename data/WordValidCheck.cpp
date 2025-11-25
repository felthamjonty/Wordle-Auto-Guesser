#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

int main(){

    while(true){
        string wordGuess;
        cout<<"chosen word (lower case): ";
        cin>>wordGuess;

        bool foundWord = false;

        ifstream myfile;
        myfile.open ("valid-wordsAdjusted.txt");
        if(myfile.is_open()){
            string curLine;
            
            while (getline(myfile,curLine)){
                if(curLine==wordGuess){
                    foundWord=true;
                    break;
                }
            }
        }
        myfile.close();

        if(foundWord){
            cout<<"True"<<"\n";
        }else{
            cout<<"False"<<"\n";
        }
        
    }

    return 0;
}

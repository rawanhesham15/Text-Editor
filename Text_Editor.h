#ifndef CLION_TEXT_EDITOR_H
#define CLION_TEXT_EDITOR_H

#endif //CLION_TEXT_EDITOR_H
#include <iostream>
#include <fstream>
#include<istream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
//__________________________________________________________
using namespace std;
//__________________________________________________________
void mergeFiles();
void countWords();
void countCharacters();
void countLines();
void searchForWord();
void countNumTimesWord();
void turnUpper();
void turnLower();
void firstCaps();
void save();
//__________________________________________________________
string toLower(string word){

    string temp;
    ifstream myFile("dataFile.txt");
    for (int i = 0; i < word.length(); ++i) {
        if(isalpha(word[i])){
            word[i] = tolower(word[i]);
        }
    }
    return word;
}
//__________________________________________________________
fstream myFile;
fstream myFile2;
char filename[81];
//__________________________________________________________
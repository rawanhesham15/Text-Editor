#include <iostream>
#include<fstream>
#include<istream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

//__________________________________________________________

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

int main(){
    int choice;
    string fileName;
    cout << "... WELCOME IN OUR TEXT EDITOR...\n";
    cout << "(if you want to merge two files enter the NOT ORIGINAL FILE NAME)\nPlease enter File name here: ";
    cin >> fileName;

    myFile.open(fileName, ios::out|ios::in);

    if(myFile){
        cout << "...This File is Already Exists...\n";
        system("PAUSE");
        system("cls");
    }
    else{
        ofstream myFile(fileName);
        cout << "...This is a new file. I created it for you :)\n";
        system("PAUSE");
        system("cls");
    }

    cout << "1. Add new text to the end of the file.\n2. Display the content of the file.\n3. Empty the file.\n4. Encrypt the file content.\n5. Decrypt the file content.\n6. Merge another file.\n7. Count the number of words in the file.\n8. Count the number of characters in the file.\n9. Count the number of lines in the file.\n10. Search for a word in the file.\n11. Count the number of times a word exists in the file.\n12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital).\n15. Save.\n16. Exit.\n";
    cout << "Please choose number: ";
    cin >> choice;
//        switch(choice)
//        {
//        }
}

//__________________________________________________________
void countNumTimesWord() {

    string fileName;
    cout << "Enter input file name: " << "\n";
    cin >> fileName;
//open the file
    ifstream myFile(fileName);
    int count = 0;
    string temp;
    string search;
    cout << "Please enter the word you want to know how many times it exists in the file: ";
    cin >> search;
    while (myFile >> temp) {
        if (toLower(temp) == toLower(search)) {
            ++count;
        }
    }
    cout <<"The word "<< search <<" was found "<< count << " times in the file. "<< endl;
}

//__________________________________________________________
void turnUpper(){

    fstream myFile;
    char name[100] , ch;
    vector<char> letters;
    cout << "Enter the file name : ";
    cin >> name;
    myFile.open(name,ios::in);
    while(!myFile.eof() && !myFile.fail()){
        myFile.get(ch);
        letters.push_back(toupper(ch));
    }
    myFile.close();
    myFile.open(name,ios::out);
    for(int i=0 ; i<letters.size()-1 ; ++i){
        myFile.put(letters[i]);
    }
    myFile.close();
    cout << "Changed to uppercase successfully :)";

}

//__________________________________________________________

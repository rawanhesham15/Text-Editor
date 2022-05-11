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
       switch(choice)
       {
           case 11:
            countNumTimesWord();
            break;
        case 12:
            turnUpper();
            save();
            break;
        case 13:
            turnLower();
            save();
            break;
        case 14:
            firstCaps();
            break;
        case 15:
            save();
            break;
        case 16:
            break;
        default:
            cout << "Invalid option :(";
            break;
    }
       
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
void turnLower(){
    fstream myFile;
    char name[100] , ch;
    vector<char> letters;
    cout << "Enter the file name : ";
    cin >> name;
    myFile.open(name,ios::in);
    while(!myFile.eof() && !myFile.fail()){
        myFile.get(ch);
        letters.push_back(tolower(ch));
    }
    myFile.close();
    myFile.open(name,ios::out);
    for(int i=0 ; i<letters.size()-1 ; ++i){
        myFile.put(letters[i]);
    }
    myFile.close();
    cout << "\nChanged to lowercase successfully :)";

}

//__________________________________________________________
void firstCaps(){

    // Take the input and output filename
    string fileName;
// indicate that a new sentence will come
    bool newSentence = true;
    cout << "Enter input file name: " << "\n";
    cin >> fileName;
//open the file
    ifstream myFile(fileName);
    cout << "Enter output file name: " << "\n";
    cin >> fileName;
// And try to open the file
    ofstream outFile(fileName);
// convert if the input and output file could be opened
    if (myFile && outFile) {
        char ch;
        while (myFile.get(ch)) {
            if (ch == '.' || ch == ' ') {
                newSentence = true;
            }
            if (isalpha(ch)) {
                if (newSentence) {
                    ch = toupper(ch);
                    newSentence = false;
                }
                else {
                    ch = tolower(ch);
                }
            }
            outFile.put(ch);
        }
    }
    else {
        cout << "Cannot open file\n";
    }
    cout << "\nFile changed to first caps";
}

//__________________________________________________________

void save(){

    char fileOne[30], fileTarget[30], ch;
    fstream fpsOne, fpTarget;
    int x ;
    cout << "\n1-Save in the same file.\n2-save in a new file.\n";
    cin >> x;
    switch (x) {
        case 1:
            cout << "File saved Successfully\n";
            break;
        case 2:
            cout << "\nEnter the Name of Original File: ";
            cin >> fileOne;//gets(fileOne);
            fpsOne.open(fileOne, fstream::in);
            if ((!fpsOne)) {
                cout << "\nError Occurred (First Source File)!";
            } else {
                cout << "\nEnter the Name of New File: ";
                cin >> fileTarget;//gets(fileTarget);
                fpTarget.open(fileTarget, fstream::out);
                if (!fpTarget)
                    cout << "\nError Occurred (Target File)!";
                else {
                    while (fpsOne >> noskipws >> ch)
                        fpTarget << ch;
                    fpTarget << "\n";
                    cout << "\nFile has been saved Successfully ";
                }
            }
            fpsOne.close();
            fpTarget.close();
            cout << endl;;
            break;
    }
}
//__________________________________________________________

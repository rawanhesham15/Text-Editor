#include "Text_Editor.h"

//__________________________________________________________
void mergeFiles(){
    string fileName, fileName2, line;

    cout << "Please enter the first file name (NOT ORIGINAL FILE NAME): ";
    cin >> fileName;

    myFile.open(fileName, ios::out|ios::in);

    if(myFile){
        cout << "...This File is Already Exists...\n";
    }
    else{
        ofstream myFile(fileName);
        cout << "...This is a new file. I created it for you :)\n";
    }

    cout << "Please enter the second file to merge(the file to merge in, THE ORIGINAL FILE): ";
    cin >> fileName2;
    myFile2.open(fileName2, ios::out|ios::app);
    myFile2.seekg(0, ios::end);

    if(myFile && myFile2){
        myFile2 << myFile.rdbuf();
        cout << "...DONE...";
    }
    else
        cout << "Failed To Open Files :(\n";

    myFile.close();
    myFile2.close();
}

//__________________________________________________________
void countWords(){
    string word = "";
    int words = 0;
    char ch;
    string fileName;

    cout << "Please enter the file name: ";
    cin >> fileName;

    myFile.open(fileName, ios::out|ios::in);

    if(myFile){
        cout << "...This File is Already Exists...\n";
    }
    else{
        ofstream myFile(fileName);
        cout << "...This is a new file. I created it for you :)\n";
    }
    myFile.seekg(0, ios::beg); //bring position of file pointer to begining of file.

    while(myFile.peek() != EOF){
        myFile.get(ch);
        if(ch != ' ' || ch == '\n')
            word += ch;
        if(ch == ' ' || ch == '\n'){
            if(word.length() > 1)
                words++;
            word = "";
        }
    }

    cout << "The number of words in the file is " << words << " words.\n";
    myFile.close();
}

//__________________________________________________________
void countCharacters(){
    int characters = 0;
    char ch;
    string fileName;

    cout << "Please enter the file name: ";
    cin >> fileName;

    myFile.open(fileName, ios::out|ios::in);

    if(myFile){
        cout << "...This File is Already Exists...\n";
    }
    else{
        ofstream myFile(fileName);
        cout << "...This is a new file. I created it for you :)\n";
    }
    myFile.seekg(0, ios::beg); //bring position of file pointer to begining of file.

    while(myFile.peek() != EOF){
        myFile.get(ch);
        characters += 1;
    }
    cout << "The number of characters in the file is " << characters << " characters.\n";
    myFile.close();
}

//__________________________________________________________
void countLines(){
    string fileName, line;
    int lines = 0;

    cout << "Please enter the file name: ";
    cin >> fileName;

    myFile.open(fileName, ios::out|ios::in);

    if(myFile){
        cout << "...This File is Already Exists...\n";
    }
    else{
        ofstream myFile(fileName);
        cout << "...This is a new file. I created it for you :)\n";
    }
    myFile.seekg(0,ios::beg);

    while(myFile.peek() != EOF){
        getline(myFile, line);
        lines++;
    }

    cout << "The number of lines in the file is " << lines << " line.\n";
}

//__________________________________________________________
void searchForWord(){
    bool find = false;
    string fileName, word, word1, word2, word3 = "";
    char ch;

    cout << "Please enter the file name: ";
    cin >> fileName;

    myFile.open(fileName, ios::out|ios::in);

    if(myFile){
        cout << "...This File is Already Exists...\n";
    }
    else{
        ofstream myFile(fileName);
        cout << "...This is a new file. I created it for you :)\n";
    }
    myFile.seekg(0, ios::beg); //bring position of file pointer to begining of file.

    cout << "Please enter the word you want to search for: ";
    cin >> word;
    for(int i = 0; i < word.length(); ++i){
        word1 += toupper(word[i]);
    }

    while(myFile.peek() != EOF){
        while(getline(myFile, word2)){
            for(int i = 0; i < word2.length(); ++i){
                if(word2[i] != ' '){
                    word3 += toupper(word2[i]);
                }
                else{
                    if (word1 == word3)
                        find = true;
                    word3 = "";
                }
            }
        }
    }
    if(find)
        cout << "\"" << word << "\"" << " Was Found In The File:)\n";
    else
        cout << "\"" << word << "\"" << " Was Not Found In The File:(\n";
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
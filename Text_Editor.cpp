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
//__________________________________________________________
void add_text()
{

    string text;
    cout << "please enter filename";
    cin.getline(filename, 81);
    ofstream out_file;
    out_file.open(filename, ios::app);
    cout << "enter the text you want to add";
    while (getline(cin, text))
    {
        out_file << text << endl;
        if (text == "ctrl+Z")
        {
            break;
        }
    }
    cin.clear();


}
//__________________________________________________________

void encrypt()
{
    fstream file;
    fstream ofile;
    char file_encrypt[81];
    char encryptarr[50];
    char c;
    int encrypt_char;
    ofstream encfile;
    cout << "please enter filename";
    cin.getline(filename, 81);

    file.open(filename, ios::in);


    int i = 0;
    while (file.peek() != EOF) {
        file.get(c);
        encrypt_char = int(c) + 1;
        cout << char(encrypt_char);
        encryptarr[i] = char(encrypt_char);

        i++;
    }
    encfile.open(filename);
    for (int j = 0; j < i; j++)
    {
        encfile << encryptarr[j];
    }
    encfile.close();

}
void empty_file()
{
    fstream file;
    file.open(filename, ios::in);
    ofstream out_file;
    out_file.open(filename, ios::app);
    while (file.peek() != EOF) {
        out_file << ' ';

    }
}
//__________________________________________________________
void decrypt_file()
{
    fstream file;
    fstream ofile;
    char file_decrypt[81];
    char decryptarr[50];
    char c;
    int dencrypt_char;
    ofstream decfile;
    cout << "please enter filename";
    cin.getline(filename, 81);

    file.open(filename, ios::in);


    int i = 0;

    while (file.peek() != EOF) {
        file.get(c);
        dencrypt_char = int(c) - 1;
        decryptarr[i] = char(dencrypt_char);

        i++;
    }

    decfile.open(filename);
    for (int j = 0; j < i; j++)
    {
        decfile << decryptarr[j];
    }
    decfile.close();
}
//__________________________________________________________

void display_file()
{
    char filename[81];
    cout << "please enter filename";
    cin.getline(filename, 81);

    fstream file;
    string input;
    file.open(filename, ios::in);

    while (file.peek() != EOF) {
        getline(file, input);
        cout << input;
    }
}
//__________________________________________________________


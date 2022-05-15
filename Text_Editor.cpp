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

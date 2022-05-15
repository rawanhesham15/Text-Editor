// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: TextEditor.cpp
// Last Modification Date: 15/5/2022
// Author1 and ID and Group: Rawan Hesham / 20211040 / S2
// Author2 and ID and Group: Nourhan Mahmoud / 20211107 / S2
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: Eg.Nesma and Eg.Yousra
// Purpose: program for displaying and manipulating text files.

#include "Text_Editor.h"

int main() {
    int choice;
    cout<< "1. Add new text to the end of the file.\n2. Display the content of the file.\n3. Empty the file.\n4. Encrypt the file content.\n5. Decrypt the file content.\n6. Merge another file.\n7. Count the number of words in the file.\n8. Count the number of characters in the file.\n9. Count the number of lines in the file.\n10. Search for a word in the file.\n11. Count the number of times a word exists in the file.\n12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital).\n15. Save.\n16. Exit.\n";
    cout << "Please choose number: ";
    cin >> choice;
    switch (choice) {
        case 6:
            mergeFiles();
            save();
            break;
        case 7:
            countWords();
            break;
        case 8:
            countCharacters();
            break;
        case 9:
            countLines();
            break;
        case 10:
            searchForWord();
            break;
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
    
    }
}
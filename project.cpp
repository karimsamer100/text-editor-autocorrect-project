#include "TextEditor.h"
#include <iostream>

using namespace std;

int main() {
    TextEditor editor;

    int choice;
    string text, findWord, replaceWord;

    while (true) {
        cout << "\nText Editor Menu:\n";
        cout << "1. Check Spelling\n";
        cout << "2. Find and Replace\n";
        cout << "3. Display Current Text\n";
        cout << "4. Undo\n";
        cout << "5. Redo\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter text to check spelling: ";
            cin.ignore();
            getline(cin, text);
            editor.checkSpelling(text);
            break;
        case 2:
            cout << "Enter word to find: ";
            cin >> findWord;
            cout << "Enter word to replace with: ";
            cin >> replaceWord;
            editor.findAndReplace(findWord, replaceWord);
            break;
        case 3:
            editor.displayCurrentText();
            break;
        case 4:
            editor.undo();
            break;
        case 5:
            editor.redo();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

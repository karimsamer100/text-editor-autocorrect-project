#include "TextEditor.h"
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

TextEditor::TextEditor() {
    ifstream inFile("english2.txt");
    if (inFile) {
        string word;
        while (getline(inFile, word)) {
            dictionary.insert(toLowerCase(word));
        }
        inFile.close();
    }
    else {
        cout << "Dictionary file not found. Starting with an empty dictionary.\n";
    }
}

string TextEditor::toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void TextEditor::suggestWord(const string& word) {
    string lowerWord = toLowerCase(word);
    vector<string> suggestions;

    cout << "Enter the number of suggestions you want to see: ";
    int limit;
    cin >> limit;

    for (size_t prefixLength = 2; prefixLength <= lowerWord.size(); ++prefixLength) {
        for (const auto& dictWord : dictionary) {
            if (lowerWord.substr(0, prefixLength) == dictWord.substr(0, prefixLength)) {
                suggestions.push_back(dictWord);
            }
        }

        if (!suggestions.empty()) {
            break;
        }
    }

    cout << "Number of suggestions found: " << suggestions.size() << "\n";

    if (suggestions.size() > limit) {
        suggestions.resize(limit);
    }

    if (!suggestions.empty()) {
        cout << "Suggestions for '" << word << "':\n";
        for (const auto& suggestion : suggestions) {
            cout << "- " << suggestion << "\n";
        }
    }
    else {
        cout << "No suggestions available for '" << word << "'.\n";
    }

    cout << "Would you like to add this word to the dictionary? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        addWordToDictionary(word);
    }
}

void TextEditor::addWordToDictionary(const string& word) {
    dictionary.insert(word);
    ofstream outFile("english2.txt", ios::app);
    if (outFile) {
        outFile << word << "\n";
        outFile.close();
    }
    else {
        cout << "Error saving dictionary to file.\n";
    }
    cout << "'" << word << "' has been added to the dictionary.\n";
}

void TextEditor::checkSpelling(const string& text) {
    stringstream ss(text);
    string word;
    bool misspelled = false;

    history.push(currentText);

    while (ss >> word) {
        string lowerWord = toLowerCase(word);

        if (dictionary.find(lowerWord) == dictionary.end()) {
            cout << "Misspelled word: " << word << "\n";
            suggestWord(word);
            misspelled = true;
        }
    }

    if (!misspelled) {
        cout << "No spelling mistakes found.\n";
    }

    currentText = text;
}

void TextEditor::displayCurrentText() {
    cout << "Current text: " << currentText << "\n";
}

void TextEditor::findAndReplace(const string& oldWord, const string& newWord) {
    history.push(currentText);

    size_t pos = 0;
    while ((pos = currentText.find(oldWord, pos)) != string::npos) {
        currentText.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }

    while (!redoHistory.isEmpty()) {
        redoHistory.pop();
    }

    displayCurrentText();
}

void TextEditor::undo() {
    if (!history.isEmpty()) {
        redoHistory.push(currentText);
        currentText = history.top();
        history.pop();

        cout << "Undo successful! Current text: " << currentText << "\n";
    }
    else {
        cout << "No changes to undo.\n";
    }
}

void TextEditor::redo() {
    if (!redoHistory.isEmpty()) {
        history.push(currentText);
        currentText = redoHistory.top();
        redoHistory.pop();

        cout << "Redo successful! Current text: " << currentText << "\n";
    }
    else {
        cout << "No changes to redo.\n";
    }
}

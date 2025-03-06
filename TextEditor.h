#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <string>
#include <set>
#include <vector>
#include "Stack.h"

using namespace std;

class TextEditor {
public:
    TextEditor();

    string toLowerCase(const string& str);

    void suggestWord(const string& word);

    void addWordToDictionary(const string& word);

    void checkSpelling(const string& text);

    void displayCurrentText();

    void findAndReplace(const string& oldWord, const string& newWord);

    void undo();

    void redo();

private:
    string currentText;
    set<string> dictionary;
    Stack<string> history;
    Stack<string> redoHistory;
};

#endif

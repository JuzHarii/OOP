#include "wordCounter.h"

using namespace std;

WordCounter::WordCounter(const char* path) {
    filePath = new char[strlen(path) + 1];
    strcpy(filePath, path);
}

WordCounter::~WordCounter() {
    delete[] filePath;
}

int WordCounter::countWords() {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return -1;
    }

    char buffer[1024];
    int totalWords = 0;
    int wordIndex = 0;
    while (file.getline(buffer, 1024)) {
        totalWords += processText(buffer, wordIndex);
    }

    file.close();
    return totalWords;
}

bool WordCounter::isAlphabet(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool WordCounter::isBlank(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void WordCounter::printWord(int wordIndex, string& word) {
    cout << wordIndex << "-th Word: " << word << endl;
}

int WordCounter::processText(const char* text, int& wordIndex) {
    int wordCount = 0;
    bool inWord = false; // Check if we are in a word
    string word = "";

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isAlphabet(text[i]) || (text[i] == '\'' && isAlphabet(text[i + 1]))) {
            if (!inWord) {
                inWord = true;
                word = "";  // Reset word
                wordIndex++;
            }
            word += text[i];
        } else {
            if (inWord) {
                // Only print and count if the word contains letters
                printWord(wordIndex, word);
                wordCount++;
                inWord = false; // Reset inWord state
            }
        }
    }

    if (inWord) {
        printWord(wordIndex, word);
        wordCount++;
    }
    return wordCount;
}

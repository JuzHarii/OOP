#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class WordCounter {
public:
    WordCounter(const char* path);
    ~WordCounter();
    int countWords();

private:
    char* filePath;
    bool isAlphabet(char c);
    bool isBlank(char c);
    void printWord(int wordIndex, string& word);
    int processText(const char* text, int& wordIndex);
};
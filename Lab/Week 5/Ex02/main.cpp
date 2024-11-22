#include "wordCounter.h"

using namespace std;

int main() {
    char filePath[256];
    cout << "Enter the file path: ";
    cin.getline(filePath, 256);

    WordCounter counter(filePath);
    int wordCount = counter.countWords();

    if (wordCount != -1) {
        cout << "The total number of words in the file is: " << wordCount << endl;
    }

    return 0;
}

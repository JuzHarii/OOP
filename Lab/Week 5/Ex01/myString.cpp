#include "myString.h"
#include <cstring>

MyString::MyString(const char* input) {
    len = strlen(input);
    str = new char[len + 1];
    strcpy(str, input);
}

MyString::MyString(const MyString& other) {
    len = other.len;
    str = new char[len + 1];
    strcpy(str, other.str);
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    int newLen = len + other.len;
    char* newStr = new char[newLen + 1];
    strcpy(newStr, str);
    strcat(newStr, other.str);
    MyString result(newStr);
    delete[] newStr;
    return result;
}

MyString operator+(const char* lhs, const MyString& rhs) {
    MyString left(lhs);
    return left + rhs;
}

int MyString::size() const {
    return len;
}

vector<MyString> MyString::Split(const vector<char>& delimiters, bool removeEmpty) const {
    vector<MyString> result;
    char* temp = new char[len + 1];
    int tempIndex = 0;

    for (int i = 0; i < len; ++i) {
        bool isDelimiter = false;
        for (int j = 0; j < delimiters.size(); ++j) {
            if (str[i] == delimiters[j]) {
                isDelimiter = true;
                break;
            }
        }

        if (isDelimiter) {
            if (tempIndex > 0 || !removeEmpty) {
                temp[tempIndex] = '\0';
                result.push_back(MyString(temp));
                tempIndex = 0;
            }
        } else {
            temp[tempIndex++] = str[i];
        }
    }

    if (tempIndex > 0 || !removeEmpty) {
        temp[tempIndex] = '\0';
        result.push_back(MyString(temp));
    }

    delete[] temp;
    return result;
}

ostream& operator<<(ostream& os, const MyString& ms) {
    os << ms.str;
    return os;
}
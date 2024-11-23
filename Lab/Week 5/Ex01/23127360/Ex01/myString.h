#include <iostream>
#include <vector>

using namespace std;

class MyString {
private:
    char* str;
    int len;

public:
    MyString(const char* input = "");
    MyString(const MyString& other);
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const;
    friend MyString operator+(const char* lhs, const MyString& rhs);

    int size() const;
    vector<MyString> Split(const vector<char>& delimiters, bool removeEmpty = true) const;
    friend ostream& operator<<(ostream& os, const MyString& ms);
};
#pragma once
#include <string>

using namespace std;

class SymString {
protected:
    string id;
    string value;

public:
    SymString(string id = "", string value = "");
    virtual ~SymString(); 

    void show() const;
    string getId() const;
    string getValue() const;

    friend SymString operator-(const SymString& s1, const SymString& s2);
};
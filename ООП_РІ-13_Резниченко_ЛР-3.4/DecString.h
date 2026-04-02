#pragma once
#include "SymString.h"

using namespace std;

class DecString : public SymString {
public:
    DecString(string id = "", string value = "0");
    ~DecString() override; 

    void show() const;
    void ShowDec() const;

    friend DecString operator-(const DecString& d1, const DecString& d2);
};
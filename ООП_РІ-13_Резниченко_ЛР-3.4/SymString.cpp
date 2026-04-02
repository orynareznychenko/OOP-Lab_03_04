#include "SymString.h"
#include <iostream>

using namespace std;

SymString::SymString(string id, string value) : id(id), value(value) {}

SymString::~SymString() {}

void SymString::show() const {
    cout << "[SymString] ID: " << id << " | Value: " << value << endl;
}

string SymString::getId() const {
    return id;
}

string SymString::getValue() const {
    return value;
}

SymString operator-(const SymString& s1, const SymString& s2) {
    string result_val = s1.value;

    if (!s2.value.empty()) {
        size_t pos = result_val.find(s2.value);
        while (pos != string::npos) {
            result_val.erase(pos, s2.value.length());
            pos = result_val.find(s2.value, pos); 
        }
    }
    return SymString(s1.id + "_res", result_val);
}
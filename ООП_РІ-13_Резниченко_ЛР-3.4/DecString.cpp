#include "DecString.h"
#include <iostream>
#include <string>

using namespace std;

DecString::DecString(string id, string value) : SymString(id, value) {}

DecString::~DecString() {}

void DecString::show() const {
    cout << "[DecString] ID: " << id << " | Value: " << value << endl;
}

void DecString::ShowDec() const {
    try {
        long long decValue = stoll(value);
        cout << "Decimal value of object " << id << " is: " << decValue << endl;
    }
    catch (...) {
        cout << "Error: string '" << value << "' cannot be converted to a decimal number!" << endl;
    }
}

DecString operator-(const DecString& d1, const DecString& d2) {
    try {
        long long val1 = stoll(d1.value);
        long long val2 = stoll(d2.value);
        long long result = val1 - val2;
        return DecString(d1.id + "_res", to_string(result));
    }
    catch (...) {
        cout << "Error during mathematical operation." << endl;
        return DecString(d1.id + "_err", "0");
    }
}
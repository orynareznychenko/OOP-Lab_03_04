#pragma once
#include "SymString.h"
#include "DecString.h"

using namespace std;

class Factory {
public:
    static SymString* createSymString(string id, string value);
    static DecString* createDecString(string id, string value);

    static void deleteObject(SymString* obj);
    static void deleteObject(DecString* obj);
};
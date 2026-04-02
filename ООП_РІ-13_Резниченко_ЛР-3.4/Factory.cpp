#include "Factory.h"

using namespace std;

SymString* Factory::createSymString(string id, string value) {
    return new SymString(id, value);
}

DecString* Factory::createDecString(string id, string value) {
    return new DecString(id, value);
}

void Factory::deleteObject(SymString* obj) {
    if (obj != nullptr) {
        delete obj;
    }
}

void Factory::deleteObject(DecString* obj) {
    if (obj != nullptr) {
        delete obj;
    }
}
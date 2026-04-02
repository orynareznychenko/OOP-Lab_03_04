#include <iostream>
#include "Factory.h"

using namespace std;

int main() {
    SymString* s1 = nullptr;
    SymString* s2 = nullptr;
    DecString* d1 = nullptr;
    DecString* d2 = nullptr;

    int choice;
    do {
        cout << "\n=========== MENU ===========" << endl;
        cout << "1. Create SymString objects (s1, s2)" << endl;
        cout << "2. Create DecString objects (d1, d2)" << endl;
        cout << "3. Show values of all objects" << endl;
        cout << "4. Subtract SymString (s1 - s2)" << endl;
        cout << "5. Subtract DecString (d1 - d2)" << endl;
        cout << "6. Call ShowDec() for d1 and d2" << endl;
        cout << "7. Delete all objects" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Factory::deleteObject(s1);
            Factory::deleteObject(s2);
            s1 = Factory::createSymString("Sym1", "HelloWorldStringWorld");
            s2 = Factory::createSymString("Sym2", "World");
            cout << "SymString objects successfully created!" << endl;
            break;
        case 2:
            Factory::deleteObject(d1);
            Factory::deleteObject(d2);
            d1 = Factory::createDecString("Dec1", "2000");
            d2 = Factory::createDecString("Dec2", "450");
            cout << "DecString objects successfully created!" << endl;
            break;
        case 3:
            if (s1) s1->show();
            if (s2) s2->show();
            if (d1) d1->show();
            if (d2) d2->show();
            if (!s1 && !d1) cout << "Objects are not created yet." << endl;
            break;
        case 4:
            if (s1 && s2) {
                SymString s3 = (*s1) - (*s2);
                cout << "Result of s1 - s2:" << endl;
                s3.show();
            }
            else {
                cout << "Create SymString objects first (Option 1)." << endl;
            }
            break;
        case 5:
            if (d1 && d2) {
                DecString d3 = (*d1) - (*d2);
                cout << "Result of d1 - d2:" << endl;
                d3.show();
            }
            else {
                cout << "Create DecString objects first (Option 2)." << endl;
            }
            break;
        case 6:
            if (d1 && d2) {
                d1->ShowDec();
                d2->ShowDec();
            }
            else {
                cout << "Create DecString objects first (Option 2)." << endl;
            }
            break;
        case 7:
            Factory::deleteObject(s1); s1 = nullptr;
            Factory::deleteObject(s2); s2 = nullptr;
            Factory::deleteObject(d1); d1 = nullptr;
            Factory::deleteObject(d2); d2 = nullptr;
            cout << "Objects successfully deleted." << endl;
            break;
        case 0:
            Factory::deleteObject(s1);
            Factory::deleteObject(s2);
            Factory::deleteObject(d1);
            Factory::deleteObject(d2);
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std; // Використання простору імен std

// Базовий клас T1: Символьний рядок
class SymString {
protected:
    string id;
    string value;

public:
    // Конструктор
    SymString(string i, string v) : id(i), value(v) {}

    // Конструктор копіювання
    SymString(const SymString& other) : id(other.id), value(other.value) {}

    // Віртуальний деструктор для правильного видалення об'єктів похідних класів
    virtual ~SymString() {}

    virtual void Show() const {
        cout << "[SymString] ID: " << id << " | Value: " << value << endl;
    }

    string GetId() const { return id; }
    string GetValue() const { return value; }

    // Перевантаження оператора '-' для SymString
    // Якщо s2 є підрядком s1, видаляємо його. Інакше повертаємо s1.
    friend SymString operator-(const SymString& s1, const SymString& s2) {
        string newVal = s1.value;
        size_t pos = newVal.find(s2.value);
        if (pos != string::npos) {
            newVal.erase(pos, s2.value.length());
        }
        return SymString(s1.id + "_minus_" + s2.id, newVal);
    }
};

// Похідний клас T2: Десятковий рядок
class DecString : public SymString {
public:
    // Конструктор з перевіркою на десяткові цифри
    DecString(string i, string v) : SymString(i, v) {
        if (!IsValidDec(v)) {
            cout << "Warning: Invalid characters in string. Value set to 0." << endl;
            value = "0";
        }
    }

    // Метод перевірки: чи рядок складається лише з цифр
    bool IsValidDec(const string& str) const {
        if (str.empty()) return false;
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    void Show() const override {
        cout << "[DecString] ID: " << id << " | Value: " << value << endl;
    }

    // Додатковий метод (Варіант 18): Показати у шістнадцятковому форматі
    void ShowHex() const {
        try {
            unsigned long long val = stoull(value);
            // Вивід у 16-ковому форматі з префіксом 0x
            cout << "[DecString] ID: " << id << " | Hex value: 0x"
                << hex << uppercase << val << dec << endl;
        }
        catch (...) {
            cout << "Error: Conversion failed." << endl;
        }
    }

    // Перевантаження оператора '-' для DecString
    // Віднімання чисельних значень з перетворенням до типу T (DecString)
    friend DecString operator-(const DecString& d1, const DecString& d2) {
        long long v1 = 0, v2 = 0;
        try { v1 = stoll(d1.value); }
        catch (...) {}
        try { v2 = stoll(d2.value); }
        catch (...) {}

        long long res = v1 - v2;
        // За умовою розглядаються тільки додатні числа, тому якщо менше нуля - ставимо 0
        if (res < 0) res = 0;

        return DecString(d1.id + "_minus_" + d2.id, to_string(res));
    }
};

// Клас Factory для інкапсуляції створення та видалення об'єктів
class Factory {
public:
    static SymString* CreateSymString(string id, string val) {
        return new SymString(id, val);
    }

    static DecString* CreateDecString(string id, string val) {
        return new DecString(id, val);
    }

    static void DeleteObject(SymString* obj) {
        if (obj) {
            delete obj;
        }
    }
};

// Головна функція з меню
int main() {
    vector<SymString*> objects;
    int choice;

    do {
        cout << "\n=========== MENU ===========" << endl;
        cout << "1. Create SymString" << endl;
        cout << "2. Create DecString" << endl;
        cout << "3. Show all objects" << endl;
        cout << "4. Delete object" << endl;
        cout << "5. Test operator '-' for SymString" << endl;
        cout << "6. Test operator '-' for DecString" << endl;
        cout << "7. Test ShowHex() for DecString" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string id, val;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter random string: "; cin >> ws; getline(cin, val);
            objects.push_back(Factory::CreateSymString(id, val));
            cout << "SymString object created." << endl;
            break;
        }
        case 2: {
            string id, val;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter decimal string: "; cin >> ws; getline(cin, val);
            objects.push_back(Factory::CreateDecString(id, val));
            cout << "DecString object created." << endl;
            break;
        }
        case 3: {
            if (objects.empty()) {
                cout << "Object list is empty." << endl;
            }
            else {
                for (size_t i = 0; i < objects.size(); ++i) {
                    cout << i << ". ";
                    objects[i]->Show();
                }
            }
            break;
        }
        case 4: {
            int index;
            cout << "Enter object index to delete: "; cin >> index;
            if (index >= 0 && index < objects.size()) {
                Factory::DeleteObject(objects[index]);
                objects.erase(objects.begin() + index);
                cout << "Object deleted." << endl;
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 5: {
            string v1, v2;
            cout << "Enter first string: "; cin >> ws; getline(cin, v1);
            cout << "Enter substring to subtract: "; cin >> ws; getline(cin, v2);
            SymString s1("temp1", v1);
            SymString s2("temp2", v2);
            SymString res = s1 - s2;
            cout << "Subtraction result: ";
            res.Show();
            break;
        }
        case 6: {
            string v1, v2;
            cout << "Enter first number: "; cin >> ws; getline(cin, v1);
            cout << "Enter second number: "; cin >> ws; getline(cin, v2);
            DecString d1("temp1", v1);
            DecString d2("temp2", v2);
            DecString res = d1 - d2;
            cout << "Subtraction result: ";
            res.Show();
            break;
        }
        case 7: {
            int index;
            cout << "Enter DecString object index: "; cin >> index;
            if (index >= 0 && index < objects.size()) {
                // Перевіряємо чи є об'єкт екземпляром DecString за допомогою dynamic_cast
                DecString* ds = dynamic_cast<DecString*>(objects[index]);
                if (ds) {
                    ds->ShowHex();
                }
                else {
                    cout << "Error: Selected object is not a DecString!" << endl;
                }
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            // Очищення виділеної пам'яті перед виходом з програми
            for (auto obj : objects) {
                Factory::DeleteObject(obj);
            }
            objects.clear();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
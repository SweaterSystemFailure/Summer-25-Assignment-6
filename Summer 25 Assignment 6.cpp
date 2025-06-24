#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item(const string& name = "", int quantity = 0) : name(name), quantity(quantity) {}

    void saveToFile() {
        ofstream out("items.txt", ios::app);
        if (out.is_open()) {
            out << name << ", " << quantity << endl;
            out.close();
            cout << "Item saved to file!" << endl;
        }
        else {
            cout << "Unable to access file." << endl;
        }
    }

    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << "File content: " << line << endl;
            }
            in.close();
        }
    }
};

int main()
{
    Item test("Cabbage", 6);

    test.saveToFile();
    test.loadFromFile();

    return 0;
}
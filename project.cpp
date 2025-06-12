#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

class Product {
    int id;
    string name;
    float price;
    int quantity;

public:
    void input();
    void display();
    int getID() const { return id; }
    void update();

    bool isValidName(const string &);
};

#pragma once

#include <string>
using namespace std;

class Customer {
private:
    string name, phone;
public:
    Customer(string name, string phone) {
        this->name = name; this->phone = phone;
    }
    string getName() const { return name; }
    string getPhone() const { return phone; }
};

#pragma once

#include "Payment.cpp"
#include <iostream>
using namespace std;

class UpiPayment : public Payment { // OOP: Inheritance
public:
    bool pay(double amount) override {
        int success;
        cout << "UPI Payment of Rs." << amount << "\n";
        cout << "Enter 1 for success or 0 for failed payment: ";
        cin >> success;
        return success == 1;
    }
};

#pragma once

#include "Payment.cpp"
#include <iostream>
using namespace std;

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        int success;
        cout << "Card Payment of Rs." << amount << "\n";
        cout << "Enter 1 for success or 0 for failed payment: ";
        cin >> success;
        return success == 1;
    }
};

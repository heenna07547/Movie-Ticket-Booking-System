#pragma once

#include "Payment.cpp"
#include <iostream>
using namespace std;

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash Payment of Rs." << amount << " received successfully.\n";
        return true;
    }
};

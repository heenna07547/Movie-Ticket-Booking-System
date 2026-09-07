#pragma once

#include "ShowSeat.cpp"
#include <vector>
using namespace std;

class PriceCalculator {
private:
    const double SILVER_PRICE = 150;
    const double GOLD_PRICE = 250;
    const double PLATINUM_PRICE = 400;
public:
    double calculate(const vector<ShowSeat*>& seats) {
        double total = 0;
        for (const auto seat : seats) {
            if (seat->getType() == SeatType::SILVER) total += SILVER_PRICE;
            else if (seat->getType() == SeatType::GOLD) total += GOLD_PRICE;
            else total += PLATINUM_PRICE;
        }
        return total;
    }
};

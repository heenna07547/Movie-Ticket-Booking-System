#pragma once

#include "Seat.cpp"
#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;
public:
    Screen(int number) {
        screenNumber = number;
        for (int i = 1; i <= 5; i++) seats.push_back(Seat("S" + to_string(i), SeatType::SILVER));
        for (int i = 1; i <= 5; i++) seats.push_back(Seat("G" + to_string(i), SeatType::GOLD));
        for (int i = 1; i <= 5; i++) seats.push_back(Seat("P" + to_string(i), SeatType::PLATINUM));
    }
    int getScreenNumber() const { return screenNumber; }
    vector<Seat> getSeats() const { return seats; }
};

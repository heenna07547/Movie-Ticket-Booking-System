#pragma once

#include "Seat.cpp"

enum class SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat seat;
    SeatStatus seatStatus; // OOP: Encapsulation - status changes only through methods
public:
    ShowSeat(Seat seat) : seat(seat), seatStatus(SeatStatus::AVAILABLE) {}
    string getNumber() const { return seat.getNumber(); }
    SeatType getType() const { return seat.getType(); }
    string getTypeName() const { return seat.getTypeName(); }
    bool isAvailable() const { return seatStatus == SeatStatus::AVAILABLE; }
    bool bookSeat() {
        if (!isAvailable()) return false;
        seatStatus = SeatStatus::BOOKED;
        return true;
    }
    void cancelSeat() { seatStatus = SeatStatus::AVAILABLE; }
};

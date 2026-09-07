#pragma once

#include "Customer.cpp"
#include "Show.cpp"
#include <vector>
#include <string>
using namespace std;

enum class BookingStatus { PENDING, CONFIRMED, CANCELLED };

class Booking {
private:
    static int nextBookingId; // OOP: Static member
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> bookedSeats;
    double bookingAmount; // Encapsulation
    BookingStatus status;
public:
    Booking(Customer* customer, Show* show, vector<ShowSeat*> seats, double amount) {
        bookingId = nextBookingId++;
        this->customer = customer; this->show = show;
        bookedSeats = seats; bookingAmount = amount;
        status = BookingStatus::PENDING;
    }
    Booking(int id, Customer* customer, Show* show) { // Compile-time polymorphism
        bookingId = id; this->customer = customer; this->show = show;
        bookingAmount = 0; status = BookingStatus::PENDING;
    }
    int getId() const { return bookingId; }
    Customer* getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    vector<ShowSeat*>& getSeats() { return bookedSeats; }
    double getAmount() const { return bookingAmount; }
    BookingStatus getStatus() const { return status; }
    void confirm() { status = BookingStatus::CONFIRMED; }
    void cancel() { status = BookingStatus::CANCELLED; }
};

int Booking::nextBookingId = 1001;

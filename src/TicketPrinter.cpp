#pragma once

#include "Booking.cpp"
#include <iostream>
using namespace std;

class TicketPrinter {
public:
    void printTicket(Booking& booking) {
        cout << "\n================ TICKET ================\n";
        cout << "Booking ID: " << booking.getId() << "\n";
        cout << "Customer: " << booking.getCustomer()->getName() << "\n";
        cout << "Movie: " << booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "Screen: " << booking.getShow()->getScreen()->getScreenNumber() << "\n";
        cout << "Time: " << booking.getShow()->getStartTime() << "\n";
        cout << "Seats: ";
        for (auto seat : booking.getSeats()) cout << seat->getNumber() << " ";
        cout << "\nTotal Amount: Rs." << booking.getAmount() << "\n";
        cout << "Status: CONFIRMED\n";
        cout << "========================================\n";
    }
};

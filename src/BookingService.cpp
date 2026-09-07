#pragma once

#include "Booking.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "Payment.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BookingService {
private:
    vector<Booking*> bookings;
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;

    void releaseSeats(vector<ShowSeat*>& seats) {
        for (auto seat : seats) seat->cancelSeat();
    }

public:
    ~BookingService() {
        for (auto booking : bookings) delete booking;
    }

    void bookTicket(Customer* customer, Show* show, Payment& payment) {
        int count;
        cout << "How many seats do you want to book? ";
        cin >> count;
        if (count <= 0) { cout << "Invalid seat count.\n"; return; }

        vector<ShowSeat*> selected;
        for (int i = 0; i < count; i++) {
            string number;
            cout << "Enter seat number: ";
            cin >> number;
            ShowSeat* seat = show->findSeat(number);
            if (seat == nullptr) {
                cout << "Invalid seat number. Booking cancelled.\n";
                releaseSeats(selected); return;
            }
            if (!seat->bookSeat()) {
                cout << "Seat " << number << " is already BOOKED. Booking cancelled.\n";
                releaseSeats(selected); return;
            }
            selected.push_back(seat);
        }

        double total = priceCalculator.calculate(selected);
        cout << "Total amount: Rs." << total << "\n";

        // Runtime polymorphism: Payment& may refer to any derived payment object.
        bool isPaid = payment.pay(total);
        if (!isPaid) {
            cout << "Payment failed. Booking NOT confirmed. Seats released.\n";
            releaseSeats(selected);
            return;
        }

        Booking* booking = new Booking(customer, show, selected, total);
        booking->confirm();
        bookings.push_back(booking);
        cout << "Booking confirmed successfully!\n";
        ticketPrinter.printTicket(*booking);
    }

    void cancelBooking(int id) {
        for (auto booking : bookings) {
            if (booking->getId() == id && booking->getStatus() == BookingStatus::CONFIRMED) {
                releaseSeats(booking->getSeats());
                booking->cancel();
                cout << "Booking cancelled. Seats are AVAILABLE again.\n";
                return;
            }
        }
        cout << "Booking ID not found or already cancelled.\n";
    }
};

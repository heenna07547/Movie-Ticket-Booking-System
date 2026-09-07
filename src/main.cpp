#include <iostream>
#include <vector>
#include <limits>
#include "Cinema.cpp"
#include "Movie.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "BookingService.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Cinema cinema("CineMax");
    Movie movie1("Sky Force", "Hindi", 150);
    Movie movie2("Interstellar", "English", 169);

    vector<Movie*> movies = {&movie1, &movie2};
    vector<Show> shows;
    shows.push_back(Show(1, &movie1, &cinema.getScreens()[0], "10:00 AM"));
    shows.push_back(Show(2, &movie1, &cinema.getScreens()[1], "2:00 PM"));
    shows.push_back(Show(3, &movie2, &cinema.getScreens()[0], "6:00 PM"));

    BookingService bookingService;
    int choice;

    do {
        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. List Movies\n2. List Shows\n3. View Seats\n4. Book Ticket\n5. Cancel Booking\n0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) { clearInput(); cout << "Invalid menu choice.\n"; continue; }

        if (choice == 1) {
            for (size_t i = 0; i < movies.size(); i++)
                cout << i + 1 << ". " << movies[i]->getTitle()
                     << " | " << movies[i]->getLanguage()
                     << " | " << movies[i]->getDuration() << " min\n";
        }
        else if (choice == 2) {
            int movieChoice;
            cout << "Choose movie number: "; cin >> movieChoice;
            if (movieChoice < 1 || movieChoice > (int)movies.size()) { cout << "Invalid movie choice.\n"; continue; }
            for (auto& show : shows)
                if (show.getMovie() == movies[movieChoice - 1])
                    cout << "Show ID " << show.getShowId() << " | Screen "
                         << show.getScreen()->getScreenNumber() << " | "
                         << show.getStartTime() << "\n";
        }
        else if (choice == 3) {
            int id; cout << "Enter Show ID: "; cin >> id;
            bool found = false;
            for (auto& show : shows)
                if (show.getShowId() == id) { show.displaySeats(); found = true; }
            if (!found) cout << "Invalid Show ID.\n";
        }
        else if (choice == 4) {
            int showId;
            cout << "Enter Show ID: "; cin >> showId;
            Show* selectedShow = nullptr;
            for (auto& show : shows) if (show.getShowId() == showId) selectedShow = &show;
            if (!selectedShow) { cout << "Invalid Show ID.\n"; continue; }

            string name, phone;
            cout << "Customer name: "; cin >> ws; getline(cin, name);
            cout << "Phone: "; cin >> phone;
            Customer customer(name, phone);

            int method;
            cout << "1. UPI  2. Card  3. Cash\nChoose payment method: "; cin >> method;
            if (method == 1) { UpiPayment p; bookingService.bookTicket(&customer, selectedShow, p); }
            else if (method == 2) { CardPayment p; bookingService.bookTicket(&customer, selectedShow, p); }
            else if (method == 3) { CashPayment p; bookingService.bookTicket(&customer, selectedShow, p); }
            else cout << "Invalid payment method.\n";
        }
        else if (choice == 5) {
            int id; cout << "Enter Booking ID: "; cin >> id;
            bookingService.cancelBooking(id);
        }
        else if (choice != 0) cout << "Invalid menu choice.\n";
    } while (choice != 0);

    cout << "Thank you for using Movie Ticket Booking System.\n";
    return 0;
}

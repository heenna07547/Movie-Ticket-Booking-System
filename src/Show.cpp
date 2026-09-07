#pragma once

#include "Movie.cpp"
#include "Screen.cpp"
#include "ShowSeat.cpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Show {
private:
    int showId;
    Movie* movie;      // Aggregation
    Screen* screen;    // Aggregation
    string startTime;
    vector<ShowSeat> showSeats; // Composition
public:
    Show(int id, Movie* movie, Screen* screen, string time)
        : showId(id), movie(movie), screen(screen), startTime(time) {
        for (const Seat& seat : screen->getSeats()) showSeats.push_back(ShowSeat(seat));
    }
    int getShowId() const { return showId; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }
    vector<ShowSeat>& getShowSeats() { return showSeats; }
    ShowSeat* findSeat(string number) {
        for (auto& seat : showSeats)
            if (seat.getNumber() == number) return &seat;
        return nullptr;
    }
    void displaySeats() {
        for (const auto& seat : showSeats)
            cout << seat.getNumber() << "(" << seat.getTypeName() << "): "
                 << (seat.isAvailable() ? "AVAILABLE" : "BOOKED") << "\n";
    }
};

#pragma once

#include "Screen.cpp"
#include <vector>
#include <string>
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen> screens;
public:
    Cinema(string name) {
        this->name = name;
        screens.push_back(Screen(1));
        screens.push_back(Screen(2));
    }
    string getName() const { return name; }
    vector<Screen>& getScreens() { return screens; }
};

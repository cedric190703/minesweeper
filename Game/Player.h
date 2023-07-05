#pragma once
#include <string>

using namespace std;

class Player {
private:
    string name;
    int score;
public:
    Player(string name) : name(name) {
        this->score = 0;
    };
    ~Player() {};
    int getScore() { return this->score; };
    string getName() { return this->name; };
    void incScore() { this->score++; };
};
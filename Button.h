#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Player.h"

class Button {
public:
    Button(int id, std::string instructions, Player& player);
    void run();

private:
    int id;
    std::string instructions;
    Player player;
};

#endif // BUTTON_H

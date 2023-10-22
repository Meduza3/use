#ifndef BUTTON_H
#define BUTTON_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BOLD "\033[1m"
#define ITALIC "\033[3m"

#include <string>
#include "player.h"

class USEinput {
    public:
        USEinput(int id, std::string instructions, Player& player);
        void run();

    private:
        int id;
        std::string instructions;
        Player& player;
};

#endif // BUTTON_H

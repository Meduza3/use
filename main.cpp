#include "player.h"
#include "button.h"
#include <iostream>
#include <string>

int main () {
    Player player;

    std::cout << "Input what instruction you want for button 0:" << std::endl;
    std::string instructions0;
    std::getline(std::cin, instructions0);
    Button button0 = Button(0, instructions0, player);

    std::cout << "Input what instruction you want for button 1:" << std::endl;
    std::string instructions1;
    std::getline(std::cin, instructions1);
    Button button1 = Button(1, instructions1, player);

    std::cout << "Input what instruction you want for button 2:" << std::endl;
    std::string instructions2;
    std::getline(std::cin, instructions2);
    Button button2 = Button(2, instructions2, player);

    std::cout << "Fight!" << std::endl;
    
    while(true) {
        std::cout << "Waiting for input... Got: ";
        std::string firstInput;
        std::getline(std::cin, firstInput);
        if (firstInput == "0") {
            button0.run();
        } else if (firstInput == "1") {
            button1.run();
        } else if (firstInput == "2") {
            button2.run();
        } else {
            break;
        }
        std::cout << "The player is at " << player.getXPos() << std::endl;
    }
}
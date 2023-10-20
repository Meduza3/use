#include "player.h"
#include "button.h"
#include <iostream>
#include <string>
#include <csignal>
#include "compiler.h"
#include <fstream>
#include <SFML/Graphics.hpp>

void signalHandler(int signum) {
    std::cout << std::endl << RESET; // Set color back to default
    exit(signum);
}

int main () {

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.display();

    Player player;
    std::cout << RESET;

    signal(SIGINT, signalHandler); // Handle Ctrl+C

    std::cout << "Input what instruction you want for button 0:" << std::endl;


    std::string instructions0;
    std::getline(std::cin, instructions0);
    if(instructions0[0] == '/'){
        std::ifstream inputFile(instructions0.substr(1));
        if (inputFile.is_open()) {
            std::string contents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            inputFile.close();
            instructions0 = contents; // Pass contents to function
        }
    }
    if(Compiler::validate(instructions0) < 0){
        std::cout << RED << "USElang syntax error. " << "Terminating with error code " << BOLD << Compiler::validate(instructions0) << RESET << std::endl;
        return -1;
    }
    Button button0 = Button(0, instructions0, player);


    std::cout << RESET << "Input what instruction you want for button 1:" << std::endl;
    std::string instructions1;
    std::getline(std::cin, instructions1);
    if(instructions1[0] == '/'){
        std::ifstream inputFile(instructions1.substr(1));
        if (inputFile.is_open()) {
            std::string contents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            inputFile.close();
            instructions1 = contents; // Pass contents to function
        }
    }
    if(Compiler::validate(instructions1) < 0){
        std::cout << RED << "USElang syntax error. " << "Terminating with error code " << BOLD << Compiler::validate(instructions1) << RESET << std::endl;
        return -1;
    }
    Button button1 = Button(1, instructions1, player);

    std::cout << BOLD << "Fight!" << RESET << std::endl;
    
    while(true) {
        std::cout << "Waiting for input... Got: " << RED;
        std::string firstInput;
        std::getline(std::cin, firstInput);
        if (firstInput == "0") {
            button0.run();
        } else if (firstInput == "1") {
            button1.run();
        } else {
            break;
        }
    }
    std::cout << RED << "Invalid input. " << BOLD << "Terminating." << RESET << std::endl;
}
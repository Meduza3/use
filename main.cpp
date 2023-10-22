#include "player.h"
#include "useinput.h"
#include <iostream>
#include <string>
#include <csignal>
#include "compiler.h"
#include <fstream>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>

void signalHandler(int signum) {
    std::cout << std::endl << RESET; // Set color back to default
    exit(signum);
}

void eventHandler(sf::RenderWindow& window, bool& isRunning) {
    while(isRunning) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                isRunning = false;
            }
        }
    }
}

void userInputHandler(Player& player, USEinput& button0, USEinput& button1, sf::RenderWindow& window) {
    auto lastRunTime = std::chrono::high_resolution_clock::now();

    while(true){
        auto currentTime = std::chrono::high_resolution_clock::now();
        if(window.hasFocus()){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0)){
                auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastRunTime).count();
                if(elapsedTime >= 15){
                    button0.run();
                    lastRunTime = currentTime;
                }
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)){
                auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastRunTime).count();
                if(elapsedTime >= 15){
                    button1.run();
                    lastRunTime = currentTime;
                }
            }   
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Add a small delay to avoid high CPU usage
    }
}


int main () {

    sf::RenderWindow window(sf::VideoMode(400, 300), "USE Skill Engine", sf::Style::Default);

    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(400, 300));
    window.setView(view);
    bool isRunning = true;

    window.display();



    Player player;
    std::cout << RESET;

    signal(SIGINT, signalHandler); // Handle Ctrl+C

    std::cout << "Input what instruction you want for UseInput 0:" << std::endl;


    std::string instructions0;
    std::getline(std::cin, instructions0);
    if(instructions0[0] == '/'){
        std::ifstream inputFile(instructions0.substr(1));
        if (inputFile.is_open()) {
            std::string contents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            inputFile.close();
            instructions0 = contents; // Pass contents to function
        }
    } else if (instructions0 == ""){
        std::ifstream inputFile("uselang_examples/example0.use");
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
    USEinput button0 = USEinput(0, instructions0, player);


    std::cout << RESET << "Input what instruction you want for UseInput 1:" << std::endl;
    std::string instructions1;
    std::getline(std::cin, instructions1);
    if(instructions1[0] == '/'){
        std::ifstream inputFile(instructions1.substr(1));
        if (inputFile.is_open()) {
            std::string contents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            inputFile.close();
            instructions1 = contents; // Pass contents to function
        }
    } else if (instructions1 == ""){
        std::ifstream inputFile("uselang_examples/example1.use");
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
    USEinput button1 = USEinput(1, instructions1, player);

    std::cout << BOLD << "Fight!" << RESET << std::endl;

    std::thread eventThread(eventHandler, std::ref(window), std::ref(isRunning));
    std::thread inputThread(userInputHandler, std::ref(player), std::ref(button0), std::ref(button1), std::ref(window));


    while(isRunning) {
        window.clear();
        sf::CircleShape circle(20);
        circle.setPosition(player.getXPos(), player.getYPos());
        window.draw(circle);
        window.display();
    }

    inputThread.join();
    eventThread.join();
    std::cout << RED << "Invalid UseInput. " << BOLD << "Terminating." << RESET << std::endl;
}
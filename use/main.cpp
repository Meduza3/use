#include "player.h"
#include "useinput.h"
#include <iostream>
#include <string>
#include <csignal>
#include "compiler.h"
#include "userInputHandler.h"
#include <fstream>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <vector>
#if defined(_WIN32) || defined(_WIN64)
    // Code specific to Windows
    #include <Windows.h>
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    // Code specific to Linux, Unix, or macOS
    #include <X11/Xlib.h>
    #undef None
#endif


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

void splash(){
    sf::Texture texture;
    texture.loadFromFile("img/splash.png");
    sf::RenderWindow splash(sf::VideoMode(texture.getSize().x, texture.getSize().y), "USE Skill Engine", sf::Style::None);
    
    #if defined(_WIN32) || defined(_WIN64)

        int screen_width = GetSystemMetrics(SM_CXSCREEN);
        int screen_height = GetSystemMetrics(SM_CYSCREEN);

    #elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)

        Display* d = XOpenDisplay(NULL);
        Screen* screen = XScreenOfDisplay(d, DefaultScreen(d));

        int screen_width = WidthOfScreen(screen);
        int screen_height = HeightOfScreen(screen);

        XCloseDisplay(d);

    #endif

    int splash_x = (screen_width - splash.getSize().x) / 2;
    int splash_y = (screen_height - splash.getSize().y) / 2;

    splash.setPosition(sf::Vector2i(splash_x, splash_y));

    sf::Sprite sprite(texture);
    splash.draw(sprite);
    splash.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    splash.close();



}

int main () {
    
    splash();

    sf::RenderWindow window(sf::VideoMode(400, 300), "USE Skill Engine", sf::Style::Default);

    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(400, 300));
    window.setView(view);
    bool isRunning = true;
    sf::CircleShape circle(20);
    circle.setPosition(0, 0);
    window.draw(circle);
    window.display();



    Player player;
    std::cout << RESET;

    signal(SIGINT, signalHandler); // Handle Ctrl+C

    //Array of UseInputs
    std::vector<USEinput> useInputs;
    while(true){
        std::cout << "If you'd like to add a UseInput, type add. To fight, type something else." << std::endl;
        std::string input;
        std::getline(std::cin, input);
        if(input == "add"){

            std::cout << "Press the button you'd like to bind to the UseInput." << std::endl;
            std::string button;
            std::getline(std::cin, button);
            sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(button[0]);

            std::cout << "Input what instruction you want for UseInput " << useInputs.size() << ":" << std::endl;
            std::string instructions;
            std::getline(std::cin, instructions);
            if(instructions[0] == '/'){
                std::ifstream inputFile(instructions.substr(1));
                if (inputFile.is_open()) {
                    std::string contents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
                    inputFile.close();
                    instructions = contents; // Pass contents to function
                }
            } else if (instructions == ""){
                std::ifstream inputFile("uselang_examples/example1.use");
                if (inputFile.is_open()) {
                    std::string contents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
                    inputFile.close();
                    instructions = contents; // Pass contents to function
                }
            }
            if(Compiler::validate(instructions) < 0){
                std::cout << RED << "USElang syntax error. " << "Terminating with error code " << BOLD << Compiler::validate(instructions) << RESET << std::endl;
                return -1;
            }

            useInputs.push_back(USEinput(key, instructions, player));
        } else {
            break;
        }
    }

    std::cout << BOLD << "Fight!" << RESET << std::endl;
    std::cout << useInputs.size() << std::endl;
    for (int i = 0; i < useInputs.size(); ++i) {
        std::cout << useInputs[i].getId() << " " << useInputs[i].getInstructions() << std::endl;
    }
    std::thread eventThread(eventHandler, std::ref(window), std::ref(isRunning));
    std::thread inputThread(userInputHandler, std::ref(player), useInputs, std::ref(window));


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
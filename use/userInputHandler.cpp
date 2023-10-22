#include "userInputHandler.h"

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
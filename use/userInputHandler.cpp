#include "userInputHandler.h"

void userInputHandler(Player& player, std::vector<USEinput> useInputs, sf::RenderWindow& window) {
    auto lastRunTime = std::chrono::high_resolution_clock::now();

    while (true) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        if (window.hasFocus()) {
            for (auto& input : useInputs) {
                sf::Keyboard::Key keyCode = static_cast<sf::Keyboard::Key>(std::toupper(input.getId()));
                if (sf::Keyboard::isKeyPressed(keyCode)) {
                    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastRunTime).count();
                    if (elapsedTime >= 15) {
                        input.run();
                        lastRunTime = currentTime;
                    }
                }
            }
        }
    }
}

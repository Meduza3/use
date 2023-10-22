#include "player.h"
#include "useinput.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <thread>
void userInputHandler(Player& player, std::vector<USEinput> useInputs, sf::RenderWindow& window);
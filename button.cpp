#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "button.h"
#include "player.h"

        Button::Button(int id, std::string instructions, Player& player) {
            this->id = id;
            this->instructions = instructions;
            this->player = player;
        }

        void Button::run(){
            std::cout << "The button " << id << " is running: " << instructions << std::endl;
            std::istringstream iss(instructions);
            std::vector<std::string> actions(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

            for(size_t i = 0; i < actions.size(); i++){
                if(actions[i] == "MOVE") {
                    player.setXPos(std::stoi(actions[i+1]));
                    std::cout << "Evaluating \"MOVE \" " << actions[i+1] << "\": Moving player by " << actions[i+1] << std::endl;
                    i++;
                } else if(actions[i] == "SHOOT") {
                    std::cout << "Evaluating \"SHOOT\": Shooting!" << std::endl;
                }
            }
        
        }   
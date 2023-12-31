#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "useinput.h"
#include "player.h"



        USEinput::USEinput(int id, std::string instructions, Player& player)
                    : id(id), instructions(instructions), player(player) {
        }


        void USEinput::run(){
            std::cout << RESET << "The UseInput " << BOLD GREEN << id << RESET << " is running: " << ITALIC << instructions << RESET << std::endl;
            std::istringstream iss(instructions);
            std::vector<std::string> actions(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

            for(size_t i = 0; i < actions.size(); i++){
                if(actions[i] == "MOVE") {
                    if(actions[i+1] == "X"){
                        player.setXPos(player.getXPos() + std::stoi(actions[i+2]));
                    } else if(actions[i+1] == "Y"){
                        player.setYPos(player.getYPos() + std::stoi(actions[i+2]));
                    } else if(actions[i+1] == "Z"){
                        player.setZPos(player.getZPos() + std::stoi(actions[i+2]));
                    }
                    std::cout << "Evaluating " << BLUE << "\"MOVE " << actions[i+1] << " " << actions[i+2] << "\"" << RESET << ": Moving player by " << actions[i+2] << " in " << actions[i+1] << std::endl;
                    i++;
                    i++;
                } else if(actions[i] == "PUNCH") {
                    std::cout << "Evaluating " << BLUE << "\"PUNCH\"" << RESET << ": Punching!" << std::endl;
                } else if(actions[i] == "PRINT") {
                    std::cout << "Evaluating " << BLUE << "\"PRINT " << actions[i+1] << "\"" << RESET << ": ";
                    if(actions[i+1] == "POS"){
                        std::cout << "Printing: " << BOLD BLUE << "The player is at " << "(" << player.getXPos() << ", " << player.getYPos() << ", " << player.getZPos() << ")" << RESET << std::endl;
                    }
                    i++;
                }
            }
        
        }   
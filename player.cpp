#include <iostream>
#include "player.h"

        void Player::move(int direction, int distance){
            std::cout << "Moving in " << direction << ":" << distance << std::endl;
        }

        void Player::shoot(){
            //Shoot hitscan middle of camera
        }

        void Player::setXPos(double x_pos){
            this->x_pos = x_pos;
        }

        double Player::getXPos() {
            return x_pos;
        }
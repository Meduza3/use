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

        void Player::setYPos(double y_pos){
            this->y_pos = y_pos;
        }

        double Player::getYPos() {
            return y_pos;
        }

        void Player::setZPos(double z_pos){
            this->z_pos = z_pos;
        }

        double Player::getZPos() {
            return z_pos;
        }
        
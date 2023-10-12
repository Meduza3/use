#include <iostream>
#include "Player.h"

        void Player::move(int direction, int distance){
            std::cout << "Moving in " << direction << ":" << distance << std::endl;
        }

        void Player::shoot(){
            //Shoot hitscan middle of camera
        }
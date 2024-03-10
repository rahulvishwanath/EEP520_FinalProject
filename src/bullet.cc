#include <iostream>
#include "bullet.h"

using namespace enviro;

// Put your implementations here
void bulletController::init() {

    // Handling the Collision of the bullet with the enemy
    notice_collisions_with("Enemy", [&](Event &e) {     
        std::cout << "Bullet collided with Enemy!" << std::endl;
        remove_agent(id());
    });

    // Handling the Collision of the bullet with the blockh
    notice_collisions_with("blockh", [&](Event &e) {
        std::cout << "Bullet collided with Block!" << std::endl;
        remove_agent(id());
    });

    // Handling the Collision of the bullet with the blockv
    notice_collisions_with("blockv", [&](Event &e) {
        std::cout << "Bullet collided with Block!" << std::endl;
        remove_agent(id());
    });

    // Handling the Collision of the bullet with the player
    notice_collisions_with("Player", [&](Event &e) {
        std::cout << "Bullet collided with Player!" << std::endl;
        remove_agent(id());
    });

}



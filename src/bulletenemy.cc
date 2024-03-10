#include <iostream>
#include "bulletenemy.h"

using namespace enviro;

// Put your implementations here

using namespace enviro;

// Put your implementations here
void bulletenemyController::init() {

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

    // Handling the Collision of the bullet with the bullet
    notice_collisions_with("Bullet", [&](Event &e) {
        std::cout << "Bullet collided with Bullet!" << std::endl;
        remove_agent(id());
    });

    // Handling the Collision of the bullet with the bulletenemy
    notice_collisions_with("BulletEnemy", [&](Event &e) {
        std::cout << "Bullet collided with BulletEnemy!" << std::endl;
        remove_agent(id());
    });

}
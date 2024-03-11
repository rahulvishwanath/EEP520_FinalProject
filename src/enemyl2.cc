#include <iostream>
#include "enemyl2.h"

using namespace enviro;

// Put your implementations here

void enemyl2Controller::init() {
 
    // Handling collisions with blockv
    notice_collisions_with("blockv", [&](Event &e) {
        std::cout << "Enemy collided with Block!" << std::endl;
        patrol_direction *= -1; // Reverse direction of patrol
    });

    // Handling collisions with blockh
    notice_collisions_with("blockh", [&](Event &e) {
        std::cout << "Enemy collided with Block!" << std::endl;
        patrol_direction *= -1; // Reverse direction of patrol
    });

    // Watch for the player's position and save it
    watch("player_position", [&](Event &e) {
        player_pos.x = e.value()["x"];
        player_pos.y = e.value()["y"];
    });
   
}

void enemyl2Controller::update() {

    // Check if the player is within range
    if ( sensor_value(0) < patrol_range || sensor_value(1) < patrol_range){
        // Enable chasing and shooting
        chasing = true;
        shooting = true;
    }
    
    // Simple patrolling behavior when not chasing
    if (!chasing){
        printf("patrolling\n");
        omni_apply_force(0,10*patrol_direction); // Apply a force to the enemy to move it in the patrol direction
    }

    // Check if chasing is enabled
    if ( chasing ) {
        printf("chasing\n");
        omni_move_toward(player_pos.x, player_pos.y, patrol_speed); // Move towards the player
    }

    // Check if shooting is enabled
    if ( shooting ) {
        // Shoot at the player with a timer so that the enemy does not shoot too often
        const double SHOOT_INTERVAL = 2.0; // Time in seconds between shots
        shoot_timer += shoot_increment;
        if (shoot_timer >= SHOOT_INTERVAL) {
            shoot_timer = 0; // Reset timer
            shoot(); // Call the shoot function
    }
    }
    
    // Wach for collision with the bullet
    notice_collisions_with("Bullet", [&](Event &e) {
        std::cout << "Enemy collided with Bullet!" << std::endl;
        remove_agent(id()); // Remove the enemy
    });

}

void enemyl2Controller::shoot(){

    // check if the player is to the left or right of the enemy
    if (player_pos.x > position().x) {
        // Player is to the right
        Agent& bullet = add_agent("bulletenemy", x()+15 , y(), 0, {{"fill", "red"}, {"stroke", "black"}});
        bullet.omni_apply_force(100,0); // Apply a force to the bullet to the right
    } else {
        // Player is to the left
        Agent& bullet = add_agent("bulletenemy", x()-15 , y(), 0, {{"fill", "red"}, {"stroke", "black"}});
        bullet.omni_apply_force(-100,0); // Apply a force to the bullet to the left
    }
}
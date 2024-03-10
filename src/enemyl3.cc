#include <iostream>
#include "enemyl3.h"

using namespace enviro;

// Put your implementations here

void enemyl3Controller::init() {

  printf("enemy l2 initialized\n");
        
// Handling collisions with blockv
    notice_collisions_with("blockv", [&](Event &e) {
        std::cout << "Enemy collided with Block!" << std::endl;

        // Reverse direction of patrol
        patrol_direction *= -1;
    });


    notice_collisions_with("blockh", [&](Event &e) {
        std::cout << "Enemy collided with Block!" << std::endl;

        // Reverse direction of patrol
        patrol_direction *= -1;
    });

    // Watch for the player's position and update it
    watch("player_position", [&](Event &e) {
        player_pos.x = e.value()["x"];
        player_pos.y = e.value()["y"];
    });
   
}

void enemyl3Controller::update() {

    // Check if the player is within range
    if ( sensor_value(0) < patrol_range || sensor_value(1) < patrol_range){
        // enable shooting
        shooting = true;
    }
    
    printf("chase: %d\n", chasing);
    printf("shoot: %d\n", shooting);

    // Check if chasing is enabled
    if ( chasing ) {
        // Move towards the player
        printf("chasing\n");
        omni_move_toward(player_pos.x, player_pos.y, patrol_speed);
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
        remove_agent(id());
    });

}

void enemyl3Controller::shoot(){

    // check if the player is to the left or right of the enemy
    if (player_pos.x > position().x) {
        // Player is to the right
        Agent& bullet = add_agent("bulletenemy", x()+15 , y(), 0, {{"fill", "red"}, {"stroke", "black"}});
        bullet.omni_apply_force(100,0);
    } else {
        // Player is to the left
        Agent& bullet = add_agent("bulletenemy", x()-15 , y(), 0, {{"fill", "red"}, {"stroke", "black"}});
        bullet.omni_apply_force(-100,0);
    }
}
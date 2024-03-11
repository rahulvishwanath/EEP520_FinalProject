#include <iostream>
#include "player.h"

using namespace enviro;

void PlayerController::init() {

    // watch for keydown event ie. when a key is pressed and apply force to the player
    watch("keydown", [&](Event& e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "d" ) { 
                apply_force(displacement, 0); // Apply a force to the player to move it in the right direction
                thrust += displacement; // saving thrust value
                bullet_direction = 1; // change the direction of the bullet

            } else if ( k == "a" ) { 
                apply_force(-displacement, 0); // Apply a force to the player to move it in the left direction
                thrust += -displacement; // saving thrust value
                bullet_direction = -1; // change the direction of the bullet
                
            } else if ( k == "w" ) { 
                omni_apply_force(0, -displacement); // Apply a force to the player to move it in the up direction
                torque += -displacement; // saving torque value
                bullet_direction = 2; // change the direction of the bullet
                
            } else if ( k == "s" ) { 
                omni_apply_force(0, displacement); // Apply a force to the player to move it in the down direction
                torque += displacement; // saving torque value
                bullet_direction = -2; // change the direction of the bullet
                
            }else if ( k == " " ) { 
                shoot(); // Call the shoot function
            }
        });
}   
    


void PlayerController::update() {

    
    // If no key is pressed, stop the player
    // This is to ensure that the player stops when the key is released, but the player does not stop immediately
    if ( thrust < 0 ) {
        apply_force(displacement, 0);
        thrust += displacement;
    }else if ( thrust > 0 ) {
        apply_force(-displacement, 0);
        thrust -= displacement;
    }
    else{
        apply_force(0, 0);
    }
    if ( torque < 0 ) {
        omni_apply_force(0, -displacement);
        torque += displacement;
    }else if ( torque > 0 ) {
        omni_apply_force(0, displacement);
        torque -= displacement;
    } else {
        omni_apply_force(0, 0);
    }
   

   // Handling the Collision of the player with the bullet 
    notice_collisions_with("bulletenemy", [&](Event &e) {
        std::cout << "Player collided with Bullet!" << std::endl;
        remove_agent(id()); // Remove the player
    });

    // watch for collision with enemy
    notice_collisions_with("Enemy", [&](Event &e) {
        std::cout << "Player collided with Enemy!" << std::endl;
        remove_agent(id()); // Remove the player
    });

    // watch for collision with enemyl2
    notice_collisions_with("enemyl2", [&](Event &e) {
        std::cout << "Player collided with EnemyL2!" << std::endl;
        remove_agent(id()); // Remove the player
    });

    // watch for collision with enemyl3
    notice_collisions_with("enemyl3", [&](Event &e) {
        std::cout << "Player collided with EnemyL3!" << std::endl;
        remove_agent(id()); // Remove the player
    });

    // Publish the position of the player
    emit(Event("player_position", {{"x", position().x}, {"y", position().y}}));


}


void PlayerController::shoot() {
    
    // Check for the direction of the bullet and set the x and y values accordingly
    if (bullet_direction == 1) {
        x = position().x + 15;
        y = position().y;
        x_axis = 1;
        y_axis = 0;
    } else if (bullet_direction == -1) {
        x = position().x - 15;
        y = position().y;
        x_axis = -1;
        y_axis = 0;
    } else if (bullet_direction == 2) {
        x = position().x;
        y = position().y - 15;
        y_axis = -1;
        x_axis = 0;
    } else if (bullet_direction == -2) {
        x = position().x;
        y = position().y + 15;
        y_axis = 1;
        x_axis = 0;
    }
   
    // Initialize the bullet and apply force to it
    // Apply a force to the bullet
    Agent& bullet = add_agent("Bullet", x, y, 0, {{"fill", "blue"}, {"stroke", "black"}});
    bullet.omni_apply_force(x_axis*100, y_axis*100); // Apply a force to the bullet

}


    
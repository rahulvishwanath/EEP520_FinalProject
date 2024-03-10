/**
 * @file player.h
 * @brief This file contains the declaration of the PlayerController and Player classes.
 * The PlayerController class is used to control the player class. It is a subclass of the Process and AgentInterface classes.
 * 
 * @author Rahul Vishwanath
 *
 * This header file declares the message class and its methods.
 */

#ifndef __PLAYER_AGENT__H
#define __PLAYER_AGENT__H 

#include "enviro.h"
using namespace enviro;

/**
 * @class PlayerController
 * @brief The PlayerController class is used to control the player class. It is a subclass of the Process and AgentInterface classes.
 *
 */

class PlayerController : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the PlayerController class.
     */
    PlayerController() : Process(), AgentInterface() {}

    /**
     * @brief The init method for the PlayerController class.
     * It handles the initialization of the player.
     * It handles the control of the player with the arrow keys, and shoots with the space bar.
     * It publishes the position of the player.
     * 
     */
    void init() ;

    /**
     * @brief The start method for the PlayerController class.
     * Does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the PlayerController class.
     * It handles the movement of the player when the keyboard is not pressed.
     * It handles the shooting of the player.
     * It handles the collision of the player with the bullet and kills it
     * It handles the collision of the player with the enemy and kills it.
     */
    void update();

    /**
     * @brief The stop method for the PlayerController class.
     * Does not have any specific implementation.
     */
    void stop() {}

    /**
     * @brief The shoot method for the PlayerController class.
     * It handles the shooting of the player.
     * It handles the creation of the bullet.
     * It handles the direction of the bullet.
     */
    void shoot();

    private:
    // Variables to keep track of the player's state

    double thrust = 0 , torque = 0;
    double displacement = 30;
    double hit_timer = 0;
    double x=15, y=0;
    int bullet_direction = 1;
    int x_axis = 1 , y_axis = 0;
    int hits = 0;
    
    
};


/**
 * @class Player
 * @brief The Player class is used to create a player.
 * The Player class is a subclass of the Agent class and is used to create a player.
 */
class Player : public Agent {
    public:

    /**
     * @brief The constructor for the Player class.
     * @param spec The json object that contains the specifications for the player.
     * @param world The world in which the player is created.
     */
    Player(json spec, World& world) : Agent(spec, world) {
        add_process(c);
        // prevent rotation of the player
        prevent_rotation();
    }
    private:
    // The PlayerController object that controls the player.
    PlayerController c;
    
};

DECLARE_INTERFACE(Player)

#endif
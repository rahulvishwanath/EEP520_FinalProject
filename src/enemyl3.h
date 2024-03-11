/**
 * @file enemyl3.h
 * @brief The file contains the declaration for the enemyl3 class and its methods.
 * The enemyl3 class is a subclass of the Agent class and is used to create an enemy that chases the player and shoots at the player from the start.
 *
 * @author Rahul Vishwanath
 *
 * This header file declares the enemyl3 class and its methods.
 */

#ifndef __ENEMYL3_AGENT__H
#define __ENEMYL3_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class enemyl3Controller
 * @brief The enemyl3Controller class is used to control the enemyl3 class. It is a subclass of the Process and AgentInterface classes.
 * and is used to create an enemy that chases the player 
 * and shoots at the player when the palyer from the start of Level 3.
 *
 */

class enemyl3Controller : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the enemyl3Controller class.
     */
    enemyl3Controller() : Process(), AgentInterface() {}

    /**
    * @brief The init method for the enemyl3Controller class.
    * It handles the initialization of the enemyl3.
    * It handles the collision of the enemyl3 with the wall.
    * It handles the watch that keeps the record of the player's position.
    */
    void init();

    /**
    * @brief The start method for the enemyController class.
    * Does not have any specific implementation.
    */
    void start() {}

    /**
    * @brief The update method for the enemyController class.
    * It handles the movement of the enemy.
    * It handles the chase of the player by the enemy.
    * It handles the collision of the enemy with the bullet.
    * It handles the shooting of the enemy when the player is within shooting range.
    */
    void update();

    /**
    * @brief The stop method for the enemyController class.
    * Does not have any specific implementation.
    */
    void stop() {}

    /**
    * @brief The shoot method for the enemyController class.
    * It handles the shooting of the enemy.
    * It handles direction of the bullet.
    */
    void shoot();

    private:
    // Variables to keep track of the enemy's state
    double patrol_direction = 1;
    double patrol_range = 100;
    double patrol_speed = 0.02;
    double hit_timer = 0;
    double shoot_timer = 0;
    double shoot_increment = 0.1;
    bool chasing = true; // The enemy chases the player from the start
    bool shooting = false;
    cpVect player_pos;
    int hits = 0;

};

/**
 * @class enemyl3
 * @brief The enemyl3 class is a subclass of the Agent class and is used
 * to create an enemy that chases the player and shoots at the player.
 */
class enemyl3 : public Agent {
    public:
    /**
    * @brief The constructor for the enemyl3 class.
    * @param spec The json object that contains the specifications for the enemy.
    * @param world The world in which the enemy is created.
    */
    enemyl3(json spec, World& world) : Agent(spec, world) {
        add_process(c);
        prevent_rotation();
    }
    private:
    // The enemyl3Controller object that controls the enemy.
    enemyl3Controller c;
};

DECLARE_INTERFACE(enemyl3)

#endif
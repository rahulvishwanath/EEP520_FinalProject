/**
 * @file enemy.h
 * @brief The file contains the enemy class and its methods.
 * The enemy class is a subclass of the Agent class and is used to create an enemy that shoots at the player when the player is in range.
 *
 * @author Rahul Vishwanath
 *
 * This header file declares the enemy class and its methods.
 */
#ifndef __ENEMY_AGENT__H
#define __ENEMY_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class enemyController
 * @brief The enemyController class is used to control the enemy class. It is a subclass of the Process and AgentInterface classes.
 *
 */
class enemyController : public Process, public AgentInterface {

    public:
    /**
    * @brief The constructor for the enemyController class.
    */
    enemyController() : Process(), AgentInterface() {}

    /**
    * @brief The init method for the enemyController class.
    * It handles the patrol direction of the enemy when it hits the wall.
    * It handles the collision of the enemy with the wall.
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
    * It handles the patrol of the enemy.
    * It handles the shooting of the enemy when the player is within shooting range.
    * It handles the collision of the enemy with the bullet.
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
    bool shooting = false;
    cpVect player_pos;
    int hits = 0;
    

};

/**
 * @class enemy
 * @brief The enemy class is used to create an enemy that chases the player and shoots at the player.
 * The enemy class is a subclass of the Agent class and is used to create an enemy that chases the player and shoots at the player.
 */

class enemy : public Agent {
    public:
    /**
    * @brief The constructor for the enemy class.
    * @param spec The JSON object that contains the specifications for the enemy class.
    * @param world The World object that contains the world in which the enemy class is created.
    */
    enemy(json spec, World& world) : Agent(spec, world) {
        add_process(c);
        prevent_rotation();
    }
    private:
    // The enemyController object that controls the enemy.
    enemyController c;
    
};

DECLARE_INTERFACE(enemy)

#endif
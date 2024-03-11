/**
 * @file enemyl2.h
 * @brief The file contains the declaration for the enemyl2class and its methods.
 * The enemyl2 class is a subclass of the Agent class and is used to create an enemy that chases the player 
 * and shoots at the player when the palyer is within a given range.
 *
 * @author Rahul Vishwanath
 *
 * This header file declares the enemyl2 class and its methods.
 */
#ifndef __ENEMYL2_AGENT__H
#define __ENEMYL2_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class enemyl2Controller
 * @brief The enemyl2Controller class is used to control the enemyl2 class. It is a subclass of the Process and AgentInterface classes.
 *
 */
class enemyl2Controller : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the enemyl2Controller class.
     */
    enemyl2Controller() : Process(), AgentInterface() {}

    /**
    * @brief The init method for the enemyl2Controller class.
    * It handles the patrol direction of the enemyl2 when it hits the wall.
    * It handles the collision of the enemyl2 with the wall.
    * It handles the watch that keeps the record of the player's position. 
    */
    void init();

    /**
    * @brief The start method for the enemyl2Controller class.
    * Does not have any specific implementation.
    */
    void start() {}

    /**
    * @brief The update method for the enemyl2Controller class.
    * It handles the movement of the enemyl2.
    * It handles the patrol of the enemyl2.
    * It handles the shooting of the enemyl2 when the player is within range.
    * It handles the chasing of the player by the enemyl2 when the player is within range.
    * It handles the collision of the enemyl2 with the bullet.
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
    bool chasing = false;
    bool shooting = false;
    cpVect player_pos;
    int hits = 0;
};

/**
 * @class enemyl2
 * @brief The enemyl2 class is used to create an enemy that chases the player and shoots at the player.
 */
class enemyl2 : public Agent {
    public:
    /**
    * @brief The constructor for the enemyl2 class.
    * @param spec The json object that contains the specifications for the enemy.
    * @param world The world in which the enemy is created.
    */
    enemyl2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
        prevent_rotation();

    }
    private:
    // The enemyl2Controller object that controls the enemy.
    enemyl2Controller c;
};

DECLARE_INTERFACE(enemyl2)

#endif
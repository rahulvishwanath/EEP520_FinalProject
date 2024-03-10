/**
 * @file bullet.h
 * @brief This file contains the declaration for the bullet class and its methods.
* The bullet class is a subclass of the Agent class and is used to create a bullet that is shot by the player.
* The bullet class is used to create a bullet that is shot by the player.
* The bullet class is used to create a bullet that is shot by the enemy.
 * @author Rahul Vishwanath
 *
 * This header file declares the bullet class and its methods.
 */

#ifndef __BULLET_AGENT__H
#define __BULLET_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
* @class bulletController
* @brief The bulletController class is used to control the bullet class. It is a subclass of the Process and AgentInterface classes.
*
*/
class bulletController : public Process, public AgentInterface {

    public:
    /**
    * @brief The constructor for the bulletController class.
    */
    bulletController() : Process(), AgentInterface() {}
    /**
    * @brief The init method for the bulletController class.
    * It handles the initialization of the bullet.
    * It handles the collision of the bullet with the wall.
    * It handles the collision of the bullet with the enemy.
    * It handles the collision of the bullet with the player.
    */
    void init();

    /**
    * @brief The start method for the bulletController class.
    * Does not have any specific implementation.
    */
    void start() {}

    /**
    * @brief The update method for the bulletController class.
    * Does not have any specific implementation.
    */
    void update() {}

    /**
    * @brief The stop method for the bulletController class.
    * Does not have any specific implementation.
    */
    void stop() {}
};

/**
* @class bullet
* @brief The bullet class is used to create a bullet that is shot by the player.
*/
class bullet : public Agent {
    public:
    /**
    * @brief The constructor for the bullet class.
    * @param spec The json object that contains the specifications for the bullet.
    * @param world The world in which the bullet is created.
    */
    bullet(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    // The bulletController object that controls the bullet.
    bulletController c;
};

DECLARE_INTERFACE(bullet)

#endif
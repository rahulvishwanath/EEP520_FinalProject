/**
 * @file bulletenemy.h
 * @brief This file contains the declaration for the bulletenemyy class and its methods.
 * The bulletenemyy class is a subclass of the Agent class and is used to create a bullet that is shot by the enemy.
 * The bulletenemyy class is used to create a bullet that is shot by the enemy.
 *
 * @author Rahul Vishwanath
 *
 * This header file declares the bulletenemyy class and its methods.
 */

#ifndef __BULLETENEMY_AGENT__H
#define __BULLETENEMY_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class bulletenemyController
 * @brief The bulletenemyController class is used to control the bulletenemy class. It is a subclass of the Process and AgentInterface classes.
 *
 */

class bulletenemyController : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the bulletenemyController class.
     */
    bulletenemyController() : Process(), AgentInterface() {}

    /**
     * @brief The init method for the bulletenemyController class.
     * It handles the initialization of the bulletenemy.
     * It handles the collision of the bulletenemy with the wall.
     * It handles the collision of the bulletenemy with the player.
     * It handles the collision of the bulletenemy with the bullet.
     * It handles the collision of the bulletenemy with the bulletenemy.
     * It handles the collision of the bulletenemy with the enemyl2.
     * It handles the collision of the bulletenemy with the enemyl3.
     */
    void init() ;

    /**
     * @brief The start method for the bulletenemyController class.
     * Does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the bulletenemyController class.
     * Does not have any specific implementation.
     */
    void update() {}

    /**
     * @brief The stop method for the bulletenemyController class.
     * Does not have any specific implementation.
     */
    void stop() {}

};

/**
 * @class bulletenemy
 * @brief The bulletenemy class is a subclass of the Agent class and is used
 * to create a bullet that is shot by the enemy.
 */
class bulletenemy : public Agent {
    public:
    /**
    * @brief The constructor for the bulletenemy class.
    * @param spec The json object that contains the specifications for the bullet.
    * @param world The world in which the bullet is created.
    */
    bulletenemy(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    // The bulletenemyController object that controls the bullet.
    bulletenemyController c;
};

DECLARE_INTERFACE(bulletenemy)

#endif
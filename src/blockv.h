/**
 * @file blockv.h
 * @brief This file contains the declaration for the blockv class. Define the constructor and the methods for the blockv class.
 * The blockv class is a subclass of the Agent class and is used to create a veritical wall of blocks.
 *
 * @author Rahul Vishwanath
 *
 * This header file declares the blockv class and its methods. 
 */
#ifndef __BLOCKV_AGENT__H
#define __BLOCKV_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
* @class blockvController
* @brief The blockvController class is used to control the blockv class. It is a subclass of the Process and AgentInterface classes.
*
*/

class blockvController : public Process, public AgentInterface {

    public:
    /**
    * @brief The constructor for the blockvController class.
    */
    blockvController() : Process(), AgentInterface() {}

    /**
    * @brief The init method for the blockvController class.
    * Does not have any specific implementation.
    */
    void init() {}

    /**
    * @brief The start method for the blockvController class.
    * Does not have any specific implementation.
    */
    void start() {}

    /**
    * @brief The update method for the blockvController class.
    * Does not have any specific implementation.
    */
    void update() {}

    /**
    * @brief The stop method for the blockvController class.
    * Does not have any specific implementation.
    */
    void stop() {}

};

/**
* @class blockv
* @brief The blockv class is used to create a vertical wall of blocks.
* The blockv class is a subclass of the Agent class and is used
* to create a vertical wall of blocks.
*/

class blockv : public Agent {
    public:
    /**
    * @brief The constructor for the blockv class.
    * @param spec The JSON object that contains the specifications for the blockv class.
    * @param world The World object that contains the world in which the blockv class is created.
    */
    blockv(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:

    // The blockvController object that is used to control the blockv class.
    blockvController c;
};

DECLARE_INTERFACE(blockv)

#endif
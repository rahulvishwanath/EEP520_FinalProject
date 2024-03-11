/**
 * @file blockh.h
 * @brief This file contains the declaration for the blockh class. Define the constructor and the methods for the blockh class.
 * The blockh class is a subclass of the Agent class and is used to create a horizontal wall of blocks. 
 *
 * @author Rahul Vishwanath
 *
 * This header file declares the blockh class and its methods. 
 */

#ifndef __BLOCKH_AGENT__H
#define __BLOCKH_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
* @class blockhController
* @brief The blockhController class is used to control the blockh class. It is a subclass of the Process and AgentInterface classes.
*
*/

class blockhController : public Process, public AgentInterface {


    public:
    /**
    * @brief The constructor for the blockhController class.
    * Does not have any specific implementation.
    */
    blockhController() : Process(), AgentInterface() {}

    /**
    * @brief The init method for the blockhController class.
    * Does not have any specific implementation.
    */
    void init() {}

    /**
    * @brief The start method for the blockhController class.
    * Does not have any specific implementation.
    */
    void start() {}

    /**
    * @brief The update method for the blockhController class.
    * Does not have any specific implementation.
    */
    void update() {}

    /**
    * @brief The stop method for the blockhController class.
    * Does not have any specific implementation.
    */
    void stop() {}

};

/**
* @class blockh
* @brief The blockh class is used to create a horizontal wall of blocks.
* The blockh class is a subclass of the Agent class and is used
* to create a horizontal wall of blocks.
*/
class blockh : public Agent {
    public:
    /**
    * @brief The constructor for the blockh class.
    * @param spec The JSON object that contains the specifications for the blockh class.
    * @param world The world object that the blockh class is in.
    */
    blockh(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:

    // The blockhController object that is used to control the blockh class.
    blockhController c;
};

DECLARE_INTERFACE(blockh)

#endif
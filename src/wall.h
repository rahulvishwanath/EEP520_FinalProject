/**
 * @file wall.h
 * @brief This file contains the declaration of the wall class and its methods.
 * The wall class is a subclass of the Agent class and is used to create a wall.
 * 
 * @author Rahul Vishwanath
 *
 * This header file declares the message class and its methods.
 */
 
#ifndef __WALL_AGENT__H
#define __WALL_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class wallController
 * @brief The wallController class is used to control the wall class. It is a subclass of the Process and AgentInterface classes.
 *
 */
class wallController : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the wallController class.
     */
    wallController() : Process(), AgentInterface() {}

    /**
     * @brief The init method for the wallController class.
     * Does not have any specific implementation.
     */
    void init() {}

    /**
     * @brief The start method for the wallController class.
     * Does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the wallController class.
     * It handles the initialization of the wall, the side walls and the maze layout.
     */
    void update();

    /**
     * @brief The stop method for the wallController class.
     * Does not have any specific implementation.
     */
    void stop() {}

    private:
    // bool initialize is used to check if the wall has been created.
    bool initialize = true;

};

/**
 * @class wall
 * @brief The wall class is used to create a wall.
 * The wall class is a subclass of the Agent class and is used to create a wall.
 */
class wall : public Agent {
    public:
    /**
     * @brief The constructor for the wall class.
     * @param spec The json object that contains the specifications for the wall.
     * @param world The world in which the wall is created.
     */
    wall(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    // The wallController object that controls the wall.
    wallController c;
};

DECLARE_INTERFACE(wall)

#endif
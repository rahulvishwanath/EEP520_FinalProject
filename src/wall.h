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
     * It handles the initialization of the wall, the side walls and the maze layout, depending on the level of the game.
     */
    void init() ;

    /**
     * @brief The start method for the wallController class.
     * Does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the wallController class.
     * Does not have any specific implementation.
     */
    void update() {}

    /**
     * @brief The stop method for the wallController class.
     * Does not have any specific implementation.
     */
    void stop() {}

    /**
     * @brief The create_level1_wall method for the wallController class.
     * It creates the wall for level 1.
     */
    void create_level1_wall();

    /**
     * @brief The create_level2_wall method for the wallController class.
     * It creates the wall for level 2.
     */
    void create_level2_wall();

    /**
     * @brief The create_level3_wall method for the wallController class.
     * It creates the wall for level 3.
     */
    void create_level3_wall();

    private:
    // bool initialize is used to check if the wall has been created.
    bool initialize = true;
    int level = 1; // The initital level of the game.
    std::vector<int> wall_ids; // The ids of the walls in the game.

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
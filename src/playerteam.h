/**
 * @file playerteam.h
 * @brief This file contains the declaration of the playerteam class and its methods.
 * The playerteam class is a subclass of the Agent class and is used to create a team of players.
 * The playerteam class is used to create a team of players.
 * @author Rahul Vishwanath
 *
 * This header file declares the message class and its methods.
 */

#ifndef __PLAYERTEAM_AGENT__H
#define __PLAYERTEAM_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class playerteamController
 * @brief The playerteamController class is used to control the playerteam class. It is a subclass of the Process and AgentInterface classes.
 *
 */

class playerteamController : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the playerteamController class.
     */
    playerteamController() : Process(), AgentInterface() {}

    /**
     * @brief The init method for the playerteamController class.
     * It handles the display of the message on the screen.
     */
    void init() ;

    /**
     * @brief The start method for the playerteamController class.
     * Does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the playerteamController class.
     * Does not have any specific implementation.
     */
    void update() ;

    /**
     * @brief The stop method for the playerteamController class.
     * Does not have any specific implementation.
     */
    void stop() {}

    /**
     * @brief The create_level1_message method for the playerteamController class.
     * It creates the message for level 1.
     */
    void create_level1_message();

    /**
     * @brief The create_level2_message method for the playerteamController class.
     * It creates the message for level 2.
     */
    void create_level2_message();

    /**
     * @brief The create_level3_message method for the playerteamController class.
     * It creates the message for level 3.
     */
    void create_level3_message();

    /**
     * @brief The create_gameover_message method for the playerteamController class.
     * It creates the gameover message.
     */
    void create_gameover_message();

    /**
     * @brief The create_gamecomplete_message method for the playerteamController class.
     * It creates the game complete message.
     */
    void create_gamecomplete_message ();

    private:
    //  The boolean variable initialize is used to check if the player has been created.
    bool initialize = true;
    int player_id; // track the id of the player in the team.
    int level = 1; // track the level of the game.
    int message_id; // track the id of the message on the screen.
    bool publish_gameover = true;

};

class playerteam : public Agent {
    public:
    playerteam(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    playerteamController c;
};

DECLARE_INTERFACE(playerteam)

#endif
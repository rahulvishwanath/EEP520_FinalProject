#include <iostream>
#include "playerteam.h"

using namespace enviro;

void playerteamController::init() {
    // Add Welcome message
    enviro::Agent& msg_agent_title = add_agent("message", -335, -300, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent_title.label("Welcome To The Game..!!", 0, 0);

    // Add Level information
    enviro::Agent& msg_agent_level = add_agent("message", -335, -280, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent_level.label("Level 1", 0, 0);


}

void playerteamController::update() {
    // If the initialize flag is true, then create the player.
    if (initialize) {
        initialize = false;
        enviro::Agent& player_agent = add_agent("Player", 50, 50, 0, {{"fill", "blue"}, {"stroke", "black"}});
        player_id = player_agent.get_id();
    }
}
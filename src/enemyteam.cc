#include <iostream>
#include "enemyteam.h"

using namespace enviro;


void enemyteamController::update() {
    // If the initialize flag is true, then create the enemy team.
    if (initialize) {
        initialize = false; // Set the initialize flag to false.
        Agent &enemy_1 = add_agent("Enemy", 200, 180, 0, {{"fill", "red"}, {"stroke", "black"}});
        enemy_ids.push_back(enemy_1.get_id());
        Agent &enemy_2 = add_agent("Enemy", -200, 180, 0, {{"fill", "red"}, {"stroke", "black"}});
        enemy_ids.push_back(enemy_2.get_id());
        Agent &enemy_3 = add_agent("Enemy", 200, -180, 0, {{"fill", "red"}, {"stroke", "black"}});
        enemy_ids.push_back(enemy_3.get_id());
        Agent &enemy_4 = add_agent("Enemy", -200, -180, 0, {{"fill", "red"}, {"stroke", "black"}});
        enemy_ids.push_back(enemy_4.get_id());
        
    }
}
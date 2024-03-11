#include <iostream>
#include "enemyteam.h"

using namespace enviro;


void enemyteamController::init() {

    // watch for emit Level2 event
    watch("level2", [&](Event& e) {
        level = 2; // set the level to 2

        // delete the level 1 enemies and set enemy_ids to empty 
        for (auto& id : enemy_ids) {
            remove_agent(id);
        }  
        enemy_ids.clear();
        create_level2_enemies(); //calling create_level2_enemies to create the enemy team
    });

    // watch for emit Level3 event
    watch("level3", [&](Event& e) {
        level = 3; // set the level to 3
        // delete the level 2 enemies and set enemy_ids to empty 
        for (auto& id : enemy_ids) {
            remove_agent(id);
        }
         enemy_ids.clear();
        create_level3_enemies(); //calling create_level3_enemies to create the enemy team
    });

    // check the level, initialize flags and create the enemy team
    if (initialize) {
        initialize = false; // Set the initialize flag to false.
        // Check for the level of the game
        if (level == 1) {
            create_level1_enemies(); //calling create_level1_enemies to create the enemy team
            publish_level2 = true;
        }else if (level == 2) {
            create_level2_enemies(); //calling create_level2_enemies to create the enemy team
            publish_level3 = true;
        }else if (level == 3) {
            create_level3_enemies(); //calling create_level3_enemies to create the enemy team
            publish_gamecomplete = true;
        }
    }
}

void enemyteamController::create_level1_enemies(){
    // Create the enemies for level 1
    enviro::Agent& enemy_agent_1 = add_agent("Enemy", 200, -100, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("Enemy", 200, 100, 0, {{"fill", "red"}, {"stroke", "black"}});

    // save the agent id in a vector
    enemy_ids.push_back(enemy_agent_1.get_id());
    enemy_ids.push_back(enemy_agent_2.get_id());
}

void enemyteamController::create_level2_enemies(){
    // Create the enemies for level 2
    enviro::Agent& enemy_agent_1 = add_agent("enemyl2", 150, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("enemyl2", -150, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_3 = add_agent("enemyl2", 100, -50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_4 = add_agent("enemyl2", -100, 150, 0, {{"fill", "red"}, {"stroke", "black"}});

    // save the agent id in a vector
    enemy_ids.push_back(enemy_agent_1.get_id());
    enemy_ids.push_back(enemy_agent_2.get_id());
    enemy_ids.push_back(enemy_agent_3.get_id());
    enemy_ids.push_back(enemy_agent_4.get_id());
}

void enemyteamController::create_level3_enemies(){
    // Create the enemies for level 3
    enviro::Agent& enemy_agent_1 = add_agent("enemyl3", -250, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("enemyl3", 250, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_3 = add_agent("enemyl3", 50, 80, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_4 = add_agent("enemyl3", -50, -80, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_5 = add_agent("enemyl3", 150, 150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_6 = add_agent("enemyl3", -150, -150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_7 = add_agent("enemyl3", 150, -150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_8 = add_agent("enemyl3", -150, 150, 0, {{"fill", "red"}, {"stroke", "black"}});

    // save the agent id in a vector
    enemy_ids.push_back(enemy_agent_1.get_id());
    enemy_ids.push_back(enemy_agent_2.get_id());
    enemy_ids.push_back(enemy_agent_3.get_id());
    enemy_ids.push_back(enemy_agent_4.get_id());
    enemy_ids.push_back(enemy_agent_5.get_id());
    enemy_ids.push_back(enemy_agent_6.get_id());
    enemy_ids.push_back(enemy_agent_7.get_id());
    enemy_ids.push_back(enemy_agent_8.get_id());
}

void enemyteamController::update() {
    
    // check enemy_ids to see if any of the enemies are dead.
    if (level == 1) {
        // if both enemies are dead, then emit level2 event.
        if ((! agent_exists(enemy_ids[0])) && (! agent_exists(enemy_ids[1])) && (publish_level2)) {
            printf("Level 1 completed\n");
            emit(Event("level2")); // emit level2 event
            publish_level2 = false; // set the publish_level2 flag to false
        }
    }else if (level == 2) {

        // if all the enemies are dead, then emit level3 event.
        if ((! agent_exists(enemy_ids[0])) && (! agent_exists(enemy_ids[1])) && (! agent_exists(enemy_ids[2])) && (! agent_exists(enemy_ids[3])) && (publish_level3)) {
            printf("Level 2 completed\n");
            emit(Event("level3")); // emit level3 event
            publish_level3 = false; // set the publish_level3 flag to false
        }
    }else if (level == 3) {
        // if all the enemies are dead, then emit level1 event.
        if ((! agent_exists(enemy_ids[0])) && (! agent_exists(enemy_ids[1])) && (! agent_exists(enemy_ids[2])) && (! agent_exists(enemy_ids[3])) && (! agent_exists(enemy_ids[4])) && (! agent_exists(enemy_ids[5])) && (! agent_exists(enemy_ids[6])) && (! agent_exists(enemy_ids[7])) && (publish_gamecomplete)) {
            printf("Level 3 completed\n"); 
            emit(Event("GameCompleted")); // emit GameCompleted event
            publish_gamecomplete = false; // set the publish_gamecomplete flag to false
        }
    }
}
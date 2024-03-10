#include <iostream>
#include "enemyteam.h"

using namespace enviro;


void enemyteamController::init() {
    // If the initialize flag is true, then create the enemy team.

    // watch for emit Level2 event
    watch("level2", [&](Event& e) {
        printf("Level 2 event received in enemycontroller\n");
        level = 2;
        // delete the level 1 enemies and set enemy_ids to empty 
        for (auto& id : enemy_ids) {
            remove_agent(id);
        }  
        enemy_ids.clear();
        //calling create_level2_enemies to create the enemy team
        create_level2_enemies();
    });

    // watch for emit Level3 event
    watch("level3", [&](Event& e) {
        printf("Level 3 event received in enemycontroller\n");
        level = 3;
        // delete the level 2 enemies and set enemy_ids to empty 
        for (auto& id : enemy_ids) {
            remove_agent(id);
        }
         enemy_ids.clear();

        //calling create_level3_enemies to create the enemy team
        create_level3_enemies();
    });

    printf("Enemy team level: %d\n", level);
    printf("Enemy team initialize: %d\n", initialize);

    if (initialize) {
        initialize = false; // Set the initialize flag to false.
        // Check for the level of the game
        if (level == 1) {
            create_level1_enemies();
            publish_level2 = true;
        }else if (level == 2) {
            create_level2_enemies();
            publish_level3 = true;
        }else if (level == 3) {
            create_level3_enemies();
            publish_gamecomplete = true;
        }
    }
}

void enemyteamController::create_level1_enemies(){
    // Create the enemies for level 1
    enviro::Agent& enemy_agent_1 = add_agent("Enemy", 200, -100, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("Enemy", 200, 100, 0, {{"fill", "red"}, {"stroke", "black"}});
    enemy_ids.push_back(enemy_agent_1.get_id());
    enemy_ids.push_back(enemy_agent_2.get_id());
}

void enemyteamController::create_level2_enemies(){
    // Create the enemies for level 2
    enviro::Agent& enemy_agent_1 = add_agent("Enemy", 150, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("Enemy", -150, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_3 = add_agent("Enemy", 100, -50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_4 = add_agent("Enemy", -100, 150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enemy_ids.push_back(enemy_agent_1.get_id());
    enemy_ids.push_back(enemy_agent_2.get_id());
    enemy_ids.push_back(enemy_agent_3.get_id());
    enemy_ids.push_back(enemy_agent_4.get_id());
}

void enemyteamController::create_level3_enemies(){
    // Create the enemies for level 3
    enviro::Agent& enemy_agent_1 = add_agent("Enemy", -250, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_2 = add_agent("Enemy", 250, 50, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_3 = add_agent("Enemy", 50, 80, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_4 = add_agent("Enemy", -50, -80, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_5 = add_agent("Enemy", 150, 150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_6 = add_agent("Enemy", -150, -150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_7 = add_agent("Enemy", 150, -150, 0, {{"fill", "red"}, {"stroke", "black"}});
    enviro::Agent& enemy_agent_8 = add_agent("Enemy", -150, 150, 0, {{"fill", "red"}, {"stroke", "black"}});
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
            emit(Event("level2"));
            publish_level2 = false;
        }
    }else if (level == 2) {

        // if all the enemies are dead, then emit level3 event.
        if ((! agent_exists(enemy_ids[0])) && (! agent_exists(enemy_ids[1])) && (! agent_exists(enemy_ids[2])) && (! agent_exists(enemy_ids[3])) && (publish_level3)) {
            printf("Level 2 completed\n");
            emit(Event("level3"));
            publish_level3 = false;
        }
    }else if (level == 3) {
        // if all the enemies are dead, then emit level1 event.
        if ((! agent_exists(enemy_ids[0])) && (! agent_exists(enemy_ids[1])) && (! agent_exists(enemy_ids[2])) && (! agent_exists(enemy_ids[3])) && (! agent_exists(enemy_ids[4])) && (! agent_exists(enemy_ids[5])) && (! agent_exists(enemy_ids[6])) && (! agent_exists(enemy_ids[7])) && (publish_gamecomplete)) {
            printf("Level 3 completed\n");
            emit(Event("GameCompleted"));
            publish_gamecomplete = false;
        }
    }
}
#include <iostream>
#include "wall.h"

using namespace enviro;

// Put your implementations here
void wallController::init() {
    
    // watch for emit Level2 event
    watch("level2", [&](Event& e) {
        level = 2;
        initialize = true;

        // remove the level 1 wall and set wall_ids to empty
        for (auto& id : wall_ids) {
            remove_agent(id);
        }
        wall_ids.clear();
        create_level2_wall(); //calling create_level2_wall to create the wall
    });

    // watch for emit Level3 event
    watch("level3", [&](Event& e) {
        level = 3;
        initialize = true;

        // remove the level 2 wall and set wall_ids to empty
        for (auto& id : wall_ids) {
            remove_agent(id);
        }
        wall_ids.clear();
        create_level3_wall(); //calling create_level3_wall to create the wall
    });

    // If the initialize flag is true, then create the wall.
    if (initialize) {
         initialize = false; // Set the initialize flag to false.
        // Check for the level of the game
        if (level == 1) {
            create_level1_wall(); //calling create_level1_wall to create the wall
        }else if (level == 2) {
            create_level2_wall(); //calling create_level2_wall to create the wall
        }else if (level == 3) {
            create_level3_wall(); //calling create_level3_wall to create the wall
        }
    }       
}

void wallController::create_level1_wall(){
     // Create the horizontal wall like the inbetween ones
        std::vector<std::pair<double, double>> wallh_1 = {{0, 0}, {50, 0}, {-50, 0}, {100, 0}, {-100, 0}, {150, 0}, {-150, 0}, {200, 0}, {-200, 0},{250, 0},{300, 0}};
        for (auto& pos : wallh_1) {
            // create the wall and save the agent id in a vector
            Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }

        // Create the horizontal wall like the top and bottom ones
        std::vector<std::pair<double, double>> wallh_b = {{0, 200}, {50, 200}, {-50, 200}, {100, 200}, {-100, 200}, {150, 200}, {-150, 200}, {200, 200}, {-200, 200},{250, 200}, {-250,200},{300, 200},{-300,200},
                                                        {0, -200}, {50, -200}, {-50, -200}, {100, -200}, {-100, -200}, {150, -200}, {-150, -200}, {200, -200}, {-200, -200},{250, -200}, {-250,-200},{300, -200},{-300,-200}};
        for (auto& pos : wallh_b) {
            Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }

        // Create the vertical wall like the right and left ones
        std::vector<std::pair<double, double>> wallv_1 = {{300, 0}, {300, 50}, {300, -50}, {300, 100}, {300, -100}, {300, 150}, {300, -150}, {300, 200},
                                                        {-330, 0}, {-330, 50}, {-330, -50}, {-330, 100}, {-330, -100}, {-330, 150}, {-330, -150}, {-330, 200}};
        for (auto& pos : wallv_1) {
            Agent& wall = add_agent("blockv", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }
}

void wallController::create_level2_wall(){
     // Create the horizontal wall like the inbetween ones
        std::vector<std::pair<double, double>> wallh_1 = {{0, 0}, {50, 0}, {-50, 0}, {100, 0}, {-100, 0}, {150, 0}, {-150, 0}, {200, 0}, {-200, 0},
        {0, 100}, {50, 100}, {-50, 100}, {100, 100}, {-100, 100}, {150, 100}, {-150, 100}, {200, 100}, {-200, 100},{250, 100},{300, 100}};       
        for (auto& pos : wallh_1) {
            Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }

        // Create the horizontal wall like the top and bottom ones
        std::vector<std::pair<double, double>> wallh_b = {{0, 200}, {50, 200}, {-50, 200}, {100, 200}, {-100, 200}, {150, 200}, {-150, 200}, {200, 200}, {-200, 200},{250, 200}, {-250,200},{300, 200},{-300,200},
                                                        {0, -200}, {50, -200}, {-50, -200}, {100, -200}, {-100, -200}, {150, -200}, {-150, -200}, {200, -200}, {-200, -200},{250, -200}, {-250,-200},{300, -200},{-300,-200}};
        for (auto& pos : wallh_b) {
            Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }

        // Create the vertical wall like the right and left ones
        std::vector<std::pair<double, double>> wallv_1 = {{300, 0}, {300, 50}, {300, -50}, {300, 100}, {300, -100}, {300, 150}, {300, -150}, {300, 200},
                                                        {-330, 0}, {-330, 50}, {-330, -50}, {-330, 100}, {-330, -100}, {-330, 150}, {-330, -150}, {-330, 200}};
        for (auto& pos : wallv_1) {
            Agent& wall = add_agent("blockv", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }
}

void wallController::create_level3_wall(){
     // Create the horizontal wall like the inbetween ones
        std::vector<std::pair<double, double>> wallh_1 = {{0, 0}, {50, 0}, {-50, 0}, {100, 0}, {-100, 0}, {150, 0}, {-150, 0}, {200, 0}, {-200, 0},{-250, 0},{-300, 0},
        {0, 100}, {50, 100}, {-50, 100}, {100, 100}, {-100, 100}, {150, 100}, {-150, 100}, {200, 100}, {-200, 100},{250, 100},{300, 100},
        {0, -100}, {50, -100}, {-50, -100}, {100, -100}, {-100, -100}, {150, -100}, {-150, -100}, {200, -100}, {-200, -100},{250, -100},{300, -100}};
        for (auto& pos : wallh_1) {
            Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }

        // Create the horizontal wall like the top and bottom ones
        std::vector<std::pair<double, double>> wallh_b = {{0, 200}, {50, 200}, {-50, 200}, {100, 200}, {-100, 200}, {150, 200}, {-150, 200}, {200, 200}, {-200, 200},{250, 200}, {-250,200},{300, 200},{-300,200},
                                                        {0, -200}, {50, -200}, {-50, -200}, {100, -200}, {-100, -200}, {150, -200}, {-150, -200}, {200, -200}, {-200, -200},{250, -200}, {-250,-200},{300, -200},{-300,-200}};
        for (auto& pos : wallh_b) {
            Agent& wall = add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }

        // Create the vertical wall like the right and left ones
        std::vector<std::pair<double, double>> wallv_1 = {{300, 0}, {300, 50}, {300, -50}, {300, 100}, {300, -100}, {300, 150}, {300, -150}, {300, 200},
                                                        {-330, 0}, {-330, 50}, {-330, -50}, {-330, 100}, {-330, -100}, {-330, 150}, {-330, -150}, {-330, 200}};
        for (auto& pos : wallv_1) {
            Agent& wall = add_agent("blockv", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
            wall_ids.push_back(wall.get_id());
        }
}
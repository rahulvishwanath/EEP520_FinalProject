#include <iostream>
#include "wall.h"

using namespace enviro;

// Put your implementations here
void wallController::update() {
    
    // If the initialize flag is true, then create the wall.
    if (initialize) {
        initialize = false; // Set the initialize flag to false.

        // Create the horizontal wall like the inbetween ones
        std::vector<std::pair<double, double>> wallh_1 = {{0, 0}, {50, 0}, {-50, 0}, {100, 0}, {-100, 0}, {150, 0}, {-150, 0}, {200, 0}, {-200, 0},{-250, 0},{-300, 0},
        {0, 100}, {50, 100}, {-50, 100}, {100, 100}, {-100, 100}, {150, 100}, {-150, 100}, {200, 100}, {-200, 100},{250, 100},{300, 100},
        {0, -100}, {50, -100}, {-50, -100}, {100, -100}, {-100, -100}, {150, -100}, {-150, -100}, {200, -100}, {-200, -100},{250, -100},{300, -100}};
        for (auto& pos : wallh_1) {
            add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
        }

        // Create the horizontal wall like the top and bottom ones
        std::vector<std::pair<double, double>> wallh_b = {{0, 200}, {50, 200}, {-50, 200}, {100, 200}, {-100, 200}, {150, 200}, {-150, 200}, {200, 200}, {-200, 200},{250, 200}, {-250,200},{300, 200},{-300,200},
                                                        {0, -200}, {50, -200}, {-50, -200}, {100, -200}, {-100, -200}, {150, -200}, {-150, -200}, {200, -200}, {-200, -200},{250, -200}, {-250,-200},{300, -200},{-300,-200}};
        for (auto& pos : wallh_b) {
            add_agent("blockh", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
        }

        // Create the vertical wall like the right and left ones
        std::vector<std::pair<double, double>> wallv_1 = {{300, 0}, {300, 50}, {300, -50}, {300, 100}, {300, -100}, {300, 150}, {300, -150}, {300, 200},
                                                        {-330, 0}, {-330, 50}, {-330, -50}, {-330, 100}, {-330, -100}, {-330, 150}, {-330, -150}, {-330, 200}};
        for (auto& pos : wallv_1) {
            add_agent("blockv", pos.first, pos.second, 0, {{"fill", "orange"}, {"stroke", "black"}});
        }
}
}
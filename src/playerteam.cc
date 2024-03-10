#include <iostream>
#include "playerteam.h"

using namespace enviro;

void playerteamController::init() {
    // Add Welcome message
    enviro::Agent& msg_agent_title = add_agent("message", -335, -300, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent_title.label("Welcome To The Game..!! It's Kill or be Killed. Survival of the skillful..Lets HUNT..!!", 0, 0);

    enviro::Agent& msg_agent_tip = add_agent("message", -335, -280, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent_tip.label("Use the a,s,d,f to navigate (Tap the keys, gives better control).. use space to shoot in the last pressed direction..use the momemtum for ur advantage", 0, 0);


    // watch for emit Level2 event
    watch("level2", [&](Event& e) {
        printf("Level 2 event received in playerteam\n");
        level = 2;

        // remove the level 1 message and set message_id to empty
        remove_agent(message_id);
        message_id = 0;

        //calling create_level2_message to create the message
        create_level2_message();
    });

    // watch for emit Level3 event
    watch("level3", [&](Event& e) {
        printf("Level 3 event received in playerteam\n");
        level = 3;

        // remove the level 2 message and set message_id to empty
        remove_agent(message_id);
        message_id = 0;

        //calling create_level3_message to create the message
        create_level3_message();
    });

    // watch for emit GameComplete event
     watch("GameCompleted", [&](Event& e) {
        printf(" GameCompleted event received in playerteam\n");
        level = 0;

        // remove the message and set message_id to empty
        remove_agent(message_id);
        message_id = 0;

        //calling create_gamecomplete_message to create the message
        create_gamecomplete_message();
    }); 


    printf("playerteam level: %d\n", level);
    printf("playerteam initialize: %d\n", initialize);

    // If the initialize flag is true, then create the wall.
    if (initialize) {
         initialize = false; // Set the initialize flag to false.
         // Create the player
        enviro::Agent& player_agent = add_agent("Player", 50, 50, 0, {{"fill", "blue"}, {"stroke", "black"}});
        player_id = player_agent.get_id();

        // Check for the level of the game
        if (level == 1) {
            create_level1_message();
        }else if (level == 2) {
            create_level2_message();
        }else if (level == 3) {
            create_level3_message();
        }
    }       


}

void playerteamController::update() {
    //check if the player is killed 
    if ((! agent_exists(player_id)) && (publish_gameover)) {
        publish_gameover = false;
        emit(Event("gameover"));

        // delete the  level message and set message_id to empty
        remove_agent(message_id);
        message_id = 0;

        // Create the game over message
        create_gameover_message();
    }


}    

void playerteamController::create_level1_message(){
    // Create the message for level 1
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Level 1 : EASY..!    Enemies will SHOOT if you get too close..!!", 0, 0);
    message_id = msg_agent.get_id();
}

void playerteamController::create_level2_message(){
    // Create the message for level 2
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Level 2 : MEDIUM..!!   Enemies will SHOOT and CHASE if you get too close..!!", 0, 0);
    message_id = msg_agent.get_id();
}

void playerteamController::create_level3_message(){
    // Create the message for level 3
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Level 3 : HARD..!!!  Enemies are looking for blood, they will CHASE you from the start and try to kill you..!!", 0, 0);
    message_id = msg_agent.get_id();
}

void playerteamController::create_gameover_message(){
    // Create the game over message
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Game Over..!!!!! The hunter got HUNTED.. Re-launch the game if you like to try again.! ", 0, 0);
    message_id = msg_agent.get_id();
}

void playerteamController::create_gamecomplete_message(){
    // Create the game over message
    enviro::Agent& msg_agent = add_agent("message", -335, -260, 0, {{"color", "black"}, {"fill", "white"}, {"stroke", "white"}});
    msg_agent.label("Congratulations..!! You are a true HUNTER.! Re-launch the game if you like to play again.!", 0, 0);
    message_id = msg_agent.get_id();
}
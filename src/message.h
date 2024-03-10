/**
 * @file message.h
 * @brief This file contains the declaration for the message class and its methods.
 * The message class is a subclass of the Agent class and is used to create a message that is displayed on the screen.
 * This used to display a message on the screen.
 * 
 * @author Rahul Vishwanath
 *
 * This header file declares the message class and its methods.
 */
#ifndef __MESSAGE_AGENT__H
#define __MESSAGE_AGENT__H 

#include "enviro.h"

using namespace enviro;

/**
 * @class messageController
 * @brief The messageController class is used to control the message class. It is a subclass of the Process and AgentInterface classes.
 *
 */
class messageController : public Process, public AgentInterface {

    public:
    /**
     * @brief The constructor for the messageController class.
     */
    messageController() : Process(), AgentInterface() {}

    /**
     * @brief The init method for the messageController class.
     * Does not have any specific implementation.
     */
    void init() {}

    /**
     * @brief The start method for the messageController class.
     * Does not have any specific implementation.
     */
    void start() {}

    /**
     * @brief The update method for the messageController class.
     * Does not have any specific implementation.
     */
    void update() {}

    /**
     * @brief The stop method for the messageController class.
     * Does not have any specific implementation.
     */
    void stop() {}

};

/**
 * @class message
 * @brief The message class is used to create a message that is displayed on the screen.
 * The message class is a subclass of the Agent class and is used to create a message that is displayed on the screen.
 */
class message : public Agent {

    public:
    /**
     * @brief The constructor for the message class.
     * @param spec The JSON specification for the message.
     * @param world The world in which the message is created.
     */
    message(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }

    private:
    // The messageController object that controls the message.
    messageController c;
};

DECLARE_INTERFACE(message)

#endif
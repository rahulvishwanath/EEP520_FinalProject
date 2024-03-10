#ifndef __BLOCK_AGENT__H
#define __BLOCK_AGENT__H 

#include "enviro.h"

using namespace enviro;

class blockController : public Process, public AgentInterface {

    public:
    blockController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

    private:
    // using data from block.json to initialize block
    bool initialize = true;

};

class block : public Agent {
    public:
    block(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    blockController c;
};

DECLARE_INTERFACE(block)

#endif
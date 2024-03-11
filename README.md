# Hunter vs Hunted [Final Project for Software Engineering for Embedded Applications EE P 520]

This Repository contains the code and implementation plan for my final project in EE P 520 [Software Engineering for Embedded Applications], taught by *Sep Makhsous*. This project is a implemention of a multi-level game [Hunter vs Hunted] that uses "Enviro" framework by Klavinslab[^1].


## Overview
The goal of this project is build an game that is fun, engaging and intervative which used the "Enviro" framework. The project should be buit in such a way that it uses and extends the "Enviro" framwork and in the process learn about Finite State Machines and their implementations. Computer games played a huge role in my childhood, and expecially Space Invaders and pacman. I wanted to build a game that is like the combination of both the games combined. 

Hence, settled on the idea of a maze like game that is called the Hunter vs the Hunted. That has a Player that traverses around a maze, while shooting the enemies that are generated at each level. The enemies abilities and volume increase with increse in level of the game. The enemies have the ability to patrol a given area, shoot the Player when it comes within a certain range, follow/chase the Player when it comes within a certain range. The abilities can be one or more combination of the mentioned ones depending in the difficulty of the level. These are the agents/components for the game:

### Game Components
1. Player Agent:
    - Movements that can be controlled through keyboard.
    - Shooting in the direction of the last pressed direction when space bar is pressed.

2. Enemy Agents:
    - Patrol within a defined area or chase the player.
    - Ability to shoot at the player when in range. 
    - Abilities grow with increase in level

3. Maze Environment:
    - Consisting of walls and pathways
    - Automatic change in layout with increase in level

4. Projectiles:
    - Represented by bullets 
    - Collision detection with Player, Enemy and Walls.

5. Game Mechanics:
    - Level increases after eliminating all enemies.
    - As Level increases the number of enemies in each level increases.
    - Increased difficulty with advancing levels.
    - Level 1 : Enemies will patrol a given area and shoot when the Player comes within a certain range.
    - Level 2 : Enemies will patrol a given area, Will start shooting and chasing the player when the Player comes within a certain range.
    - Level 3 : Enemies will chasing and shooting at the player from the start of the game.

## Key Challenges and Solutions

### Implementation Plan
Coming up with the implementation plan on how to built the game, what all agents it will require and the working abilities of components was challenge. I started out by making a list of tasks and the order in which they need to be completed to be have a good idea on what needs to be done and what to expect next. Here is the Implemention plan that I wrote:
- Setup Enviro Environment:
- Design basic functionality of the Blocks/Maze:
- Developing the Player Agent Funtionality:
- Creating Enemy Agents behaviour:
- Implement working of Bullets:
- Incorporate basic functionality of components to form a level
- Extend the levels with higher difficulties
- Testing, and Debugging:

### Implementing Multiple agents of the same components
While the Enviro framework made it easy of create agents of the component, understanding how I can track the number of agents are created, and how many are killed in the game was a challenging task. Initially, I tried initializing multiple agents of the same compoment, in the same init() function of the original component. This fed to a continous loop of just the agents being created continously. After thinking, I have implemented seperate agents [team agents], that are reponsible for creating and maintaining list of the sub agents that were created by it. This team agents keep track of the availabilty of the created agents and raised a emit EVENT when certain conditions are met like :
For Example : Using enemyteam agent to create multiple agents of enemies, enemyteam agent keeps track of the number of enemy agents it created and publishes a event when all the agents are unavailable. Depending on the current level of the game, enemyteam agent publishes Level2, Level3 and gamecomplete events that are captured by other agents for increasing the levels.

### Implementing Enemies with different abilities
As the goal was to make the game harded for each level, It was important to be able to create enemies with changing and increasing abilities. Initially, I tried using flags, that can be changed depending by the current level to be able to change the abilities like chasing and when to chase. This was wild goose chase. So, I settled on the easier way to handle this, by creating different agents for different levels of the game. This allowed me to create Enemies with increasing difficulties as the level increased.

### Handing Friendly Fire
Since both the Enemy and the Player has the ability to shoot, I was facing issues with friendly fire inbetween the enemies. Initially, I was using the same bullet agent for both the Player and Enemy. Since the bullet was make to handle collision with the enemies, the bullets fired by the enemies were killing a few of their own. So, I created different bullet agents bullet,bulletenemy for the Player and the Enemy respectively. Using this I was able to eliminate friendly fire. 

# Installation

## Docker Images
Assuming that Docker is already installed in your system. A docker image must be loaded to run the enviro server from a bash prompt. If you do not have docker installed, please visit Docker Installation[^2]

To start, run the below command:
````
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.1 bash
````
Use the below commands to start esm, make the project and start the enviro server as:
````
esm start
make
enviro
````
Then navigate to `http://localhost` and begin the gameplay!   
To end the game, press `Ctrl-C` in the `bash` terminal to stop the enviro server.

## Usage

After loading the "Enviro" environment, and navigation to the localhost, You should be able to see the game in your browser.
Here are a few instructions you should keep in mind,

### Instructions

1. Take some time to read the messages on the game, I have provided a few tips and ideas on how to approach the game.
2. The level increases after all the enemies are killed on a certain level.
3. The Player is not made to stop immediately on key release on purpose, It is to make the game a little challenging
4. Tapping the keys are the best way to move the Player, Holding down the keys while the player is about to be killed can occasionally lead the game to crash as the Player agent is looking for key.
5. Re-launch enviro when game over over

### Controls

`a` - Move Left
`d` - Move Right
`w` - Move Up
`s` - Move Down
`Spacebar` - Shoot a bullet in the direction of the last pressed key (Unlimited Shoots.!)


## Acknowledgements
We would like to acknowledge the following sources of information and code used in this project:
- [^1]: Enviro, https://github.com/klavinslab/enviro
- [^2]: Docker Install, https://docs.docker.com/engine/install/
- https://github.com/klavinslab/elma.git

Special Mentions Sep's course repo, which I referred for generic idea and gameflow
- https://github.com/sosper30/eep520-wi24/


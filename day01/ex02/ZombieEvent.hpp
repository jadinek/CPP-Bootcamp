#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent{
    public:
    ZombieEvent();
    ~ZombieEvent();
    void setZombieType();
    Zombie* newZombie(std::string name);
    Zombie* randomChump();

    private:
    std::string type;
};

#endif
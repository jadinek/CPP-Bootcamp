#ifndef ZOMBIEHOARD_HPP
#define ZOMBIEHOARD_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieHoard{
    public:
    ZombieHoard();
    ZombieHoard(int N);
    ~ZombieHoard();
    void createHoard(int N);
    void announce();

    private:
    int N;
    Zombie* hoard;
};

#endif
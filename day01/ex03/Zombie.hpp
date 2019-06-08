#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
    Zombie();
    Zombie(std::string aName);
    Zombie(std::string aName, std::string theType);
    ~Zombie();
    std::string randomNameGen();
    void announce();

    private:
    std::string name;
    std::string type;
};

#endif
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    public:
    Weapon();
    Weapon(std::string aType);
    std::string const &getType();
    void setType(std::string aType);

    private:
    std::string type;
};

#endif
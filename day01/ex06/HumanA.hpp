#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    public:
    HumanA(std::string aName, Weapon &aWeapon);
    ~HumanA();
    void attack() const;

    private:
    Weapon &weapon;
    std::string name;
};

#endif
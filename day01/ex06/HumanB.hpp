#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
    HumanB(std::string aName);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon &aWeapon);

    private:
    Weapon *weapon;
    std::string name;
};

#endif
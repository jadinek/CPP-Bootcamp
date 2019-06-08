#include "HumanA.hpp"

HumanA::HumanA(std::string aName, Weapon &aWeapon):weapon(aWeapon), name(aName){};

HumanA::~HumanA(){};

void HumanA::attack() const{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
};
#include "HumanB.hpp"

HumanB::HumanB(std::string aName):name(aName){};

HumanB::~HumanB(){
};

void HumanB::attack() const{
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
};

void HumanB::setWeapon(Weapon &aWeapon){
    weapon = &aWeapon;
};
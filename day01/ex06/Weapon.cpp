#include "Weapon.hpp"

Weapon::Weapon(){};

Weapon::Weapon(std::string aType): type(aType){};

std::string const &Weapon::getType(){
    return this->type;
};

void Weapon::setType(std::string aType){
    type = aType;
};
#include "Zombie.hpp"

Zombie::Zombie(std::string aName):name(aName){};

Zombie::Zombie(std::string aName, std::string theType):name(aName), type(theType){};

Zombie::~Zombie(){
    std::cout << "Zombie " << name << " has been slain." << std::endl;
};

void Zombie::announce(){
    if (type == ""){
        std::string zombieTypes[9] = {"Bear", "Twink", "Cub", "Twunk", "Otter", "Drag Queen", "Wolf", "Jock", "Chub"};
        int x = rand() % 8;
        type = zombieTypes[x];
    }
    std::cout << name << ", a zombie " << type << ", wants Braiiiiiiinnnssss..." << std::endl;
};
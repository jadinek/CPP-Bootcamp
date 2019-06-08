#include "Zombie.hpp"

Zombie::Zombie(){
    name = randomNameGen();
};

std::string Zombie::randomNameGen(){
    std::string names[15] = {"Ronan", "Adam", "Gansey", "Noah", "Blue", "Henry", "Opal", "Maggie", "Mr. Gray", "Greenmantle", "Calla", "Maura", "Persephone", "Jimi", "Orla"};
    int x = rand() % 14;
    std::string name = names[x];
    return name;
};

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
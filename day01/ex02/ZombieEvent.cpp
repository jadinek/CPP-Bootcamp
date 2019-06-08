#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(){
    setZombieType();
};

ZombieEvent::~ZombieEvent(){
    std::cout << "Zombie Event object destroyed." << std::endl;
};

void ZombieEvent::setZombieType(){
    std::string zombieTypes[9] = {"Otter", "Drag Queen", "Wolf", "Jock", "Chub", "Bear", "Twink", "Cub", "Twunk"};
    int x = rand() % 8;
    type = zombieTypes[x];
};

Zombie* ZombieEvent::newZombie(std::string name){
    Zombie *newZombie = new Zombie(name, type);
    return (newZombie);
};

Zombie* ZombieEvent::randomChump(){
    std::string names[15] = {"Ronan", "Adam", "Gansey", "Noah", "Blue", "Henry", "Opal", "Maggie", "Mr. Gray", "Greenmantle", "Calla", "Maura", "Persephone", "Jimi", "Orla"};
    int x = rand() % 14;
    std::string name = names[x];

    Zombie *newZombie = new Zombie(name, type);
    newZombie->announce();
    return (newZombie);
};
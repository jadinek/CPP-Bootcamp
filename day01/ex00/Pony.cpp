#include "Pony.hpp"

Pony::Pony(std::string aName, std::string aColour, int theAge):name(aName), colour(aColour), age(theAge){};

Pony::~Pony(){
    std::cout << "Your pony has died." << std::endl;
};

void Pony::getPony() const{
    std::cout << name << " is the goodest, best pony that ever lived." << std::endl;
    std::cout << name << " is " << colour << " and " << age << " years old." << std::endl;
};

void ponyOnTheStack(){
    std::cout << "A pony on the STACK:" << std::endl;
    Pony aPony("jon", "black", 2);
    aPony.getPony();
};

void ponyOnTheHeap(){
    std::cout << "A pony on the HEAP:" << std::endl;
    Pony *anotherPony = new Pony("sansa", "red", 3);
    anotherPony->getPony();

    delete anotherPony;
};
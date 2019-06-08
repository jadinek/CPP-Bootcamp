#include "Brain.hpp"

Brain::Brain(){
    mass = 0;
    name = "";
    colour = "";
    std::sprintf(tempAddress, "%p\n", this);
    address = std::string(tempAddress);
};

std::string Brain::identify() const{
    return (address);
};
#include "Human.hpp"

Human::Human(){
    aBrain = new Brain();
};

Human::~Human(){
    delete aBrain;
};

std::string Human::identify() const{
    return(aBrain->identify());
};

Brain Human::getBrain() const{
    return *aBrain;
};
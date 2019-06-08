#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    public:
    Brain();
    std::string identify() const;

    private:
    double mass;
    std::string name;
    std::string colour;
    std::string address;
    char tempAddress[40];
};

#endif
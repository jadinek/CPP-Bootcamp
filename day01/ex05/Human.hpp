#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

class Human{
    public:
    Human();
    ~Human();
    std::string identify() const;
    Brain getBrain() const;

    private:
    const Brain* aBrain;
};

#endif
#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony{
    public:
    Pony(std::string aName, std::string aColour, int theAge);
    ~Pony();
    void getPony() const;

    private:
    std::string name, colour;
    int age;
};

void ponyOnTheStack();
void ponyOnTheHeap();

#endif
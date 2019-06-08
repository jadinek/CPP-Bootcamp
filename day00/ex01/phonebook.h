#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class Person{
    public:
    void addPerson();
    void getPerson(Person aPerson) const;
    void search(Person aPerson[], int index) const;
    std::string display(std::string aString) const;

    private:
    std::string firstName, lastName, nickname, login, postalAddress, emailAddress;
    std::string phoneNumber, DoB, favouriteMeal, underwearColour, darkestSecret;
};

void getCommand(Person persons[], int index);

#endif
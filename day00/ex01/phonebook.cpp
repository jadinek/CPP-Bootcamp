#include "phonebook.h"

void Person::addPerson(){
    std::cout << "Please enter information for new contact." << std::endl;
    std::cout << "Enter new contact's first name:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, firstName);
    std::cout << "Last name:" << std::endl;
    std::getline(std::cin, lastName);
    std::cout << "Nickname:" << std::endl;
    std::getline(std::cin, nickname);
    std::cout << "Login:" << std::endl;
    std::getline(std::cin, login);
    std::cout << "Postal address:" << std::endl;
    std::getline(std::cin, postalAddress);
    std::cout << "Email address:" << std::endl;
    std::getline(std::cin, emailAddress);
    std::cout << "Phone number:" << std::endl;
    std::getline(std::cin, phoneNumber);
    std::cout << "Date of birth:" << std::endl;
    std::getline(std::cin, DoB);
    std::cout << "Favourite meal:" << std::endl;
    std::getline(std::cin, favouriteMeal);
    std::cout << "Underwear colour:" << std::endl;
    std::getline(std::cin, underwearColour);
    std::cout << "Darkest Secret:" << std::endl;
    std::getline(std::cin, darkestSecret);
};

void Person::search(Person aPerson[], int index) const{
    int x = 0;

    std::cout << "     index|";
    std::cout << "first name|";
    std::cout << " last name|";
    std::cout << "  nickname|" << std::endl;

    while(x < index)
    {
        std::cout << "         " << x << "|";
        std::cout << display(aPerson[x].firstName) << "|";
        std::cout << display(aPerson[x].lastName) << "|";
        std::cout << display(aPerson[x].nickname)  << "|" << std::endl;
        x++;
    }

    if (index!= 0){
        std::cout << "Please select a contact using the relevant index: ";
        std::cin >> x;
        if (x < index){
            getPerson(aPerson[x]);
        }
        else {
            std::cout << "Index out of range." << std::endl;
        }
    }

};

std::string Person::display(std::string aString) const{
    std::string newString;
    const char * c = aString.c_str();

    if (std::strlen(c) > 10){
        newString = aString.std::string::substr(0, 9) + ".";
    }
    else if (std::strlen(c) == 10){
        return (aString);
    }
    else{
        newString = aString;
        while (std::strlen(newString.c_str()) != 10){
            newString = " " + newString;
        }
    }
    return (newString);
};

void Person::getPerson(Person aPerson) const{
    std::cout << aPerson.firstName << std::endl;
    std::cout << aPerson.lastName << std::endl;
    std::cout << aPerson.nickname << std::endl;
    std::cout << aPerson.login << std::endl;
    std::cout << aPerson.postalAddress;
    std::cout << aPerson.emailAddress << std::endl;
    std::cout << aPerson.phoneNumber << std::endl;
    std::cout << aPerson.DoB << std::endl;
    std::cout << aPerson.favouriteMeal << std::endl;
    std::cout << aPerson.underwearColour << std::endl;
    std::cout << aPerson.darkestSecret << std::endl;
};

void getCommand(Person persons[], int index){
    std::string inputcommand;
    

    std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
    std::cin >> inputcommand;

    if (inputcommand == "ADD"){
        if (index == 8){
                std::cout << "This phonebook is full." << std::endl;
                std::exit(1);
        }
        else if (index < 8){
            persons[index].addPerson();
            index++;
        }
    }
    if (inputcommand == "SEARCH"){
        persons[8].search(persons, index);
    }
    if (inputcommand == "EXIT"){
        std::exit(1);
    }
    if (inputcommand != "ADD" && inputcommand != "SEARCH" && inputcommand != "EXIT"){
        std::cout << "Invalid command. Please try again." << std::endl;
    }
    while (inputcommand != "EXIT"){
    getCommand(persons, index);
    }
};
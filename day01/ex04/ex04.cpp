#include <iostream>

int main(){

    std::string myString = "HI THIS IS BRAIN";
    std::string *point = &myString;
    std::string &reference = myString;

    std::cout << *point << std::endl;
    std::cout << reference << std::endl;
    return 0;
}
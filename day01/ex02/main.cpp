#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(){
    
    srand(time(0));
    ZombieEvent Zombie1;

    std::cout << '\n' << "A STACK ZOMBIE HOARD APPROCHES" << std::endl;
    Zombie Zombie2("Jon");
    Zombie2.announce();
    Zombie Zombie3("Sansa", "Lady");
    Zombie3.announce();
    std::cout << std::endl;

    std::cout << "A HEAP ZOMBIE HOARD APPROCHES" << std::endl;
    Zombie *Zombie4 = Zombie1.randomChump();
    Zombie *Zombie5 = Zombie1.newZombie("Ghost");
    Zombie5->announce();
    Zombie *Zombie6  = new Zombie("Glendower", "King");
    Zombie6->announce();
    std::cout << std::endl;

    std::cout << "KILL THEM ALL" << std::endl;
    delete Zombie4;
    delete Zombie5;
    delete Zombie6;

    return 0;
}
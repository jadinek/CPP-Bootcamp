#include "ZombieHoard.hpp"

int main(){
    
    srand(time(0));
    ZombieHoard theHoard = ZombieHoard(5); 
    theHoard.announce();
    std::cout << std::endl;
    
    return 0;
}
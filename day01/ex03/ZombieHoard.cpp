#include "ZombieHoard.hpp"

ZombieHoard::ZombieHoard(){};

ZombieHoard::ZombieHoard(int N):N(N){
    createHoard(N);
};

ZombieHoard::~ZombieHoard(){
    delete [] hoard;
    std::cout << "The hoard has been destroyed." << std::endl;
};

void ZombieHoard::createHoard(int N){

    hoard = new Zombie[N];
};

void ZombieHoard::announce(){
    while (N > 0){
        hoard[N-1].announce();
        N--;
    }
};
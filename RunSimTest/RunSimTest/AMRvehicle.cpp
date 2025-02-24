#include "AMRvehicle.h"
#include <iostream>
using namespace std;
AMRvehicle::AMRvehicle(double l, double w, double h, double x, double y)
    : length(l), width(w), height(h), posX(x), posY(y), isDriving(false), nextPosX(x), nextPosY(y) {
}

void AMRvehicle::printInfo() const
{
    
        std::cout << "AMR Vehicle Info:" << std::endl;
        std::cout << "Dimensions (LxWxH): " << length << " x " << width << " x " << height << std::endl;
        std::cout << "Current Position (X, Y): " << posX << " , " << posY << std::endl;
        std::cout << "Is Driving: " << (isDriving ? "Yes" : "No") << std::endl;
        std::cout << "Next Position (X, Y): " << nextPosX << " , " << nextPosY << std::endl;
    
}

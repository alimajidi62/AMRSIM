#include <iostream>
#include <string>
using namespace std;
class MotorSim {
private:
    double acceleration;
    double maxSpeed;
    double currentSpeed;

public:
    MotorSim() : acceleration(0), maxSpeed(0), currentSpeed(0) {}

    void setAcceleration(double accel) {
        acceleration = accel;
    }

    void setMaxSpeed(double speed) {
        maxSpeed = speed;
    }

    void updateSpeed(double time) {
        currentSpeed += acceleration * time;
        if (currentSpeed > maxSpeed) {
            currentSpeed = maxSpeed;
        }
    }

    double getCurrentSpeed() const {
        return currentSpeed;
    }

    std::string getStatus() const {
        return "Current Speed: " + to_string(currentSpeed) + " m/s, Max Speed: " + std::to_string(maxSpeed) + " m/s";;
    }
};

//int main() {
//    MotorSim motor;
//    motor.setAcceleration(2.0); // 2 m/s^2
//    motor.setMaxSpeed(10.0); // 10 m/s
//
//    motor.updateSpeed(1.0); // Update speed after 1 second
//    std::cout << motor.getStatus() << std::endl;
//
//    motor.updateSpeed(2.0); // Update speed after another 2 seconds
//    std::cout << motor.getStatus() << std::endl;
//
//    return 0;
//}
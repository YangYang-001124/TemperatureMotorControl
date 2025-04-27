#include "Motor.h"
#include <iostream>

// Constructor initializes hardware ID, revision and sets initial motor state to 'Stop'
Motor::Motor(const std::string& hardwareId, int REV) : hardwareId_(hardwareId), REV_(REV), currentState_(MotorState::Stop) {}

// Rotate motor to the right
void Motor::rotateRight() {
    currentState_ = MotorState::RotateRight;
    std::cout << "[Motor " << hardwareId_ << " REV-" << REV_ << "] Rotating Right" << std::endl;
}

// Rotate motor to the left
void Motor::rotateLeft() {
    currentState_ = MotorState::RotateLeft;
    std::cout << "[Motor " << hardwareId_ << " REV-" << REV_ << "] Rotating Left" << std::endl;
}

// Stop the motor
void Motor::stop() {
    currentState_ = MotorState::Stop;
    std::cout << "[Motor " << hardwareId_ << " REV-" << REV_<< "] Stopped" << std::endl;
}

// Get the current state of the motor
MotorState Motor::getState() const {
    return currentState_;
}
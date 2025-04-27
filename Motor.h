#ifndef MOTOR_H
#define MOTOR_H

#include <string>

// Enum to represent the motor state
enum class MotorState {
    RotateRight,
    RotateLeft,
    Stop
};

// Motor control class
class Motor {
public:
    // Constructor with hardware ID and revision
    Motor(const std::string& hardwareId, int REV);

    // Motor actions
    void rotateRight();
    void rotateLeft();
    void stop();

    // Get current motor state
    MotorState getState() const;

private:
    std::string hardwareId_;     // Unique hardware identifier
    int REV_;                    // Revision number
    MotorState currentState_;    // Current state of the motor
};

#endif // MOTOR_H
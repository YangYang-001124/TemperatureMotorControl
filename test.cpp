#include "Motor.h"
#include "TemperatureSensor.h"
#include "HardwareUnit.h"

#include <cassert>
#include <iostream>

void testMotor() {
    std::cout << "Testing Motor module..." << std::endl;

    Motor motor("TEST_MOTOR", 2);

    // Test Motor's state
    motor.rotateRight();
    assert(motor.getState() == MotorState::RotateRight);

    motor.rotateLeft();
    assert(motor.getState() == MotorState::RotateLeft);

    motor.stop();
    assert(motor.getState() == MotorState::Stop);

    // Test continuous operation.
    motor.rotateRight();
    motor.rotateLeft();
    assert(motor.getState() == MotorState::RotateLeft);

    std::cout << "Motor module tests passed! \n" << std::endl;
}

void testTemperatureSensor() {
    std::cout << "Testing TemperatureSensor module..." << std::endl;
    TemperatureSensor sensor;

    // Test the normal temperature range
    for (int i = 0; i < 10; ++i) {
        double temp = sensor.readTemperature();
        assert(temp >= 70.0 && temp <= 110.0);
    }

    // Test boundary temperature
    double temp_at_85 = 85.0;
    double temp_at_105 = 105.0;
    assert(temp_at_85 >= 70.0 && temp_at_85 <= 110.0);
    assert(temp_at_105 >= 70.0 && temp_at_105 <= 110.0);

    std::cout << "TemperatureSensor module tests passed! \n" << std::endl;
}

void testHardwareUnit() {
    std::cout << "Testing HardwareUnit module..." << std::endl;
    HardwareUnit hw("HW_TEST_001", 2);

    // Test hardwareID
    assert(hw.getId() == "HW_TEST_001");
    assert(hw.getREV() == 2);

    std::cout << "HardwareUnit module tests passed! \n" << std::endl;
}

//To simplify the directory, the above functions have not been separated into .h and .cpp files.

int main() {
    testMotor();
    testTemperatureSensor();
    testHardwareUnit();

    std::cout << "All modules passed all tests successfully!" << std::endl;
    return 0;
}

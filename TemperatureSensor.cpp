#include "TemperatureSensor.h"
#include <cstdlib>
#include <ctime>

// Constructor: initialize random seed for temperature simulation
TemperatureSensor::TemperatureSensor() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Simulate reading a temperature value between 70°C and 110°C
double TemperatureSensor::readTemperature() {
    return 70 + static_cast<double>(std::rand() % 400) / 10.0;
}

#include "Motor.h"
#include "TemperatureSensor.h"
#include "HardwareUnit.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

//Get current time for log storing
std::string getCurrentTime() {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}

int main() {
    // Initialize hardware unit, temperature sensor, and motor
    HardwareUnit hardware("ABC123", 0);
    TemperatureSensor sensor;
    Motor motor(hardware.getId(), hardware.getREV());

    std::ofstream logFile("TMC_log.txt");

    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1;
    }

    logFile << "=== Motor " << hardware.getId() << " REV-" << hardware.getREV() << " ===\n" << std::endl;

    // Main control loop: sample temperature (simulated) and control motor every 100ms
    while (true) {
        auto start = std::chrono::steady_clock::now(); // Record loop start time

        // Read current temperature
        double temperature = sensor.readTemperature();
        std::cout << "[Sensor] Current Temperature: " << temperature << " °C" << std::endl;

        std::string motorAction;

        // Control logic
        if (temperature < 85.0) {
            motor.rotateRight();
            motorAction = "Rotating Right";
        } else if (temperature >= 85.0 && temperature < 105.0) {
            motor.rotateLeft();
            motorAction = "Rotating Left";
        } else {
            motor.stop();
            motorAction = "Stopping";
        }

        //Store the info to log file
        logFile << getCurrentTime() << " | Temp: " << temperature 
                << "°C | Motor: " << motorAction << std::endl;
        logFile.flush();

        // Sleep until 100ms have passed since loop start
        std::this_thread::sleep_until(start + std::chrono::milliseconds(100));
    }

    return 0;
}

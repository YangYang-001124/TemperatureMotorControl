# Temperature Monitoring and Motor Control System

## Description
This project implements a real-time temperature monitoring and motor control system in C++, targeting a Linux-based environment.  
The system continuously samples temperature values and controls motor actions according to predefined thresholds, ensuring minimal timing jitter and structured hardware compatibility.

---

## Features
- Temperature sampling every 100 milliseconds.
- Motor control based on temperature:
  - Temperature < 85°C → Rotate Right
  - 85°C ≤ Temperature < 105°C → Rotate Left
  - Temperature ≥ 105°C → Stop Motor
- Hardware revision support via modular structure.
- Real-time log file generation (`TMC_log.txt`) with timestamps.
- Structured unit testing for all system modules.

---

## Project Structure
```bash
TemperatureMotorControl/ 
├── main.cpp 
├── Motor.h / Motor.cpp # Motor control module 
├── TemperatureSensor.h / TemperatureSensor.cpp # Temperature simulation module 
├── HardwareUnit.h / HardwareUnit.cpp # Hardware ID and revision module 
├── test.cpp # Unit testing script 
├── TEST_PLAN.md # Test plan and testing strategy 
├── README.md
```

---

## How to Build
Navigate to the TemperatureMotorControl project directory first.  
Install `g++`.

### Build and Run Main Program
```bash
g++ main.cpp Motor.cpp TemperatureSensor.cpp HardwareUnit.cpp -o temp_motor_control -std=c++17
./temp_motor_control
```

### Build and Run Test Program
```bash
g++ test.cpp Motor.cpp TemperatureSensor.cpp HardwareUnit.cpp -o test_temp_motor_control -std=c++17
./test_temp_motor_control
```

## The Main Program Will:
- Continuously monitor simulated temperature values.
- Control motor actions accordingly.
- Output logs to the console and save logs to TMC_log.txt.

## Testing
- Unit tests are implemented in test.cpp.
- The testing approach is described in detail in TEST_PLAN.md.

## Requirements
- C++17 compatible compiler (e.g., g++).
- Linux-based environment (e.g., Ubuntu 22.04 LTS or later).
- Basic terminal access.

## Author
Yang Yang  
April 2025

#include "HardwareUnit.h"

// Constructor: initialize hardware ID and revision
HardwareUnit::HardwareUnit(const std::string& id, int REV) : id_(id), REV_(REV) {}

// Return the hardware ID and revision
std::string HardwareUnit::getId() const {
    return id_;
}

int HardwareUnit::getREV() const {
    return REV_;
}
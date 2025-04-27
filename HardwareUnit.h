#ifndef HARDWAREUNIT_H
#define HARDWAREUNIT_H

#include <string>

// Hardware unit class for different revisions (e.g., REV-0, REV-1)
class HardwareUnit {
public:
    // Constructor with hardware ID and revision
    HardwareUnit(const std::string& id, int REV);

    // Get the unique hardware ID and revision
    std::string getId() const;
    int getREV() const;

private:
    std::string id_;    // Unique hardware identifier
    int REV_;           // Hardware revision number (e.g., 0 for REV-0, 1 for REV-1)
};

#endif // HARDWAREUNIT_H
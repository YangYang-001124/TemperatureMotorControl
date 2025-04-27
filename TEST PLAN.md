# TEST_PLAN.md

## Testing Strategy

To ensure system correctness and robustness, the following structured testing approach was applied:

---

## 1. Motor Module

### Test Cases:
- **rotateRight()** sets motor state to **RotateRight**.
- **rotateLeft()** sets motor state to **RotateLeft**.
- **stop()** sets motor state to **Stop**.
- **Consecutive actions** (e.g., rotateRight() -> rotateLeft()) update state properly.

### Boundary Testing:
- Multiple actions are tested consecutively to verify robustness.

---

## 2. Temperature Sensor Module

### Test Cases:
- **readTemperature()** returns a value between **70°C and 110°C**.

### Boundary Testing:
- Specific edge values (e.g., 85.0°C, 105.0°C) are verified to be within the acceptable range.

---

## 3. Hardware Unit Module

### Test Cases:
- **getId()** returns the correct hardwareID initialized through the constructor.

---

## Test Methods
- All modules are tested independently using C++ `assert()` checks.
- Each test immediately validates expected outcomes.
- Boundary cases and normal cases are both covered.

---

## Test Result
- All test cases passed successfully in local validation.
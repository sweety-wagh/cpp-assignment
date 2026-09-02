#include <iostream>

int main() {
    // Simulated hardware memory registers using C++14 binary literals
    int statusReg  = 0b10110001;  // Read-only from firmware side
    int controlReg = 0b00000000;  // Firmware writes here
    int dataReg    = 0b11001010;  // For reassignment demo

    std::cout << "--- Initial Register Values ---\n";
    std::cout << "statusReg  : " << statusReg << "\n";
    std::cout << "controlReg : " << controlReg << "\n\n";

    // =========================================================================
    // Requirement 1: regPtr1 (Pointer to Constant Data)
    // =========================================================================
    // The data pointed to cannot be modified, but the pointer direction can change.
    const int* regPtr1 = &statusReg;
    
    std::cout << "regPtr1 points to value: " << *regPtr1 << "\n";

    // Attempting a write through regPtr1:
    // *regPtr1 = 0b11111111; 
    // ERROR EXPLANATION: Read-only variable is not assignable. 
    // The 'const' prefix protects the data value from being overwritten.

    // Attempting a repoint:
    regPtr1 = &dataReg; // SUCCESSFUL: The pointer address itself is not constant.
    std::cout << "regPtr1 successfully repointed to dataReg value: " << *regPtr1 << "\n\n";


    // =========================================================================
    // Requirement 2: regPtr2 (Constant Pointer to Mutable Data)
    // =========================================================================
    // The data pointed to can change, but the pointer must always look at the same address.
    int* const regPtr2 = &controlReg;

    // Writing a new value through regPtr2:
    *regPtr2 = 0b00001111; // SUCCESSFUL: The underlying integer value is mutable.
    std::cout << "regPtr2 modified controlReg to: " << controlReg << "\n";

    // Attempting a repoint:
    // regPtr2 = &dataReg;
    // ERROR EXPLANATION: Cannot assign to a variable that is const.
    // The 'const' placement after '*' fixes the pointer to its initialized address.


    // =========================================================================
    // Requirement 3: regPtr3 (Constant Pointer to Constant Data)
    // =========================================================================
    // Neither the address path nor the underlying value can change.
    const int* const regPtr3 = &statusReg;

    std::cout << "\nregPtr3 points to value: " << *regPtr3 << "\n";

    // Attempting a write:
    // *regPtr3 = 0b00000000;
    // ERROR EXPLANATION: Cannot write through a pointer to const.

    // Attempting a repoint:
    // regPtr3 = &dataReg;
    // ERROR EXPLANATION: Cannot reassign a const pointer.

    return 0;
}

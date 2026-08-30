#include <iostream>

// --- V1: Call by Value (Original Buggy Version) ---
// Why it fails: It copies the arguments into local variables inside the function scope. 
// Modifying copies leaves the original variables in the calling function untouched.
void resetSensorPairV1(int reading1, int reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

// --- V2: Call by Reference (Fix 1) ---
// Uses aliases (&) to modify the original variables directly.
void resetSensorPairV2(int& reading1, int& reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

// --- V3: Call by Pointer (Fix 2) ---
// Uses memory addresses (*) and dereferencing to swap the original variable contents.
void resetSensorPairV3(int* reading1, int* pointer2) {
    if (reading1 != nullptr && pointer2 != nullptr) {
        int temp = *reading1;
        *reading1 = *pointer2;
        *pointer2 = temp;
    }
}

int main() {
    /* 
     * ROOT CAUSE ANALYSIS COMMENT BLOCK (Minimum 4 lines):
     * Version 1 (resetSensorPairV1) fails because it passes arguments "by value".
     * This creates entirely new, independent copies of the integers on the stack frame.
     * The swapping operation only manipulates these local, short-lived copies.
     * Once V1 finishes execution, its stack frame is cleared, leaving the original main variables completely unchanged.
     */

    int A = 55;
    int B = 12;

    // --- V1 Test ---
    std::cout << "--- V1: Call by Value ---\n";
    std::cout << "Before : A=" << A << "  B=" << B << "\n";
    resetSensorPairV1(A, B);
    std::cout << "After  : A=" << A << "  B=" << B << "   <- values unchanged\n\n";

    // --- V2 Test ---
    std::cout << "--- V2: Call by Reference ---\n";
    std::cout << "Before : A=" << A << "  B=" << B << "\n";
    resetSensorPairV2(A, B);
    std::cout << "After  : A=" << A << "  B=" << B << "   <- values swapped\n\n";

    // --- V3 Test ---
    std::cout << "--- V3: Call by Pointer ---\n";
    std::cout << "Before : A=" << A << "  B=" << B << "\n";
    resetSensorPairV3(&A, &B);
    std::cout << "After  : A=" << A << "  B=" << B << "   <- values swapped back\n";

    return 0;
}

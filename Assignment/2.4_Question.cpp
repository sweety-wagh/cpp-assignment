#include <iostream>

using namespace std;

// --- Pointer-to-Pointer Packet Parser ---
bool parsePacket(const int* rawData, int size, int** outMin, int** outMax) {
    // If size <= 0 : return false, leave output pointers unchanged
    if (size <= 0 || rawData == nullptr) {
        return false;
    }

    // Initialize trackers with the first element's address
    const int* minElementPtr = rawData;
    const int* maxElementPtr = rawData;

    // Loop through the packet to locate min and max elements
    for (int i = 1; i < size; i++) {
        if (*(rawData + i) < *minElementPtr) {
            minElementPtr = (rawData + i);
        }
        if (*(rawData + i) > *maxElementPtr) {
            maxElementPtr = (rawData + i);
        }
    }

    /*
     * NOTE ON CONST-CASTING:
     * Because the assignment signature defines outMin/outMax as 'int**' 
     * but rawData arrives as a 'const int*', we safely use const_cast 
     * to drop the const qualifier so the pointers point directly back 
     * into the original mutable packet buffer inside main().
     */
    *outMin = const_cast<int*>(minElementPtr);
    *outMax = const_cast<int*>(maxElementPtr);

    return true;
}

int main() {
    // Code block provided exactly as given in assignment spec:
    int packet[] = {45, 12, 67, 8, 55, 31};
    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}

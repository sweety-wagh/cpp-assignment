#include <iostream>
#include <cmath>   // For sqrt() and fabs()

// --- Function 1: Compute Root Mean Square (RMS) ---
double computeRMS(double* signal, int n) {
    double sum_squares = 0.0;
    double* ptr = signal;
    
    for (int i = 0; i < n; i++) {
        sum_squares += (*ptr) * (*ptr);
        ptr++; // Advance pointer to next element
    }
    
    return std::sqrt(sum_squares / n);
}

// --- Function 2: Normalise Signal In-Place ---
void normalise(double* signal, int n) {
    // First, find the maximum absolute value in the array
    double max_abs = 0.0;
    double* ptr = signal;
    
    for (int i = 0; i < n; i++) {
        double current_abs = std::fabs(*ptr);
        if (current_abs > max_abs) {
            max_abs = current_abs;
        }
        ptr++;
    }
    
    // Prevent division by zero if array contains only zeros
    if (max_abs == 0.0) return;
    
    // Divide every element by max_abs
    ptr = signal; // Reset pointer to start
    for (int i = 0; i < n; i++) {
        *ptr /= max_abs;
        ptr++;
    }
}

// --- Function 3: Count Zero Crossings ---
int countZeroCrossings(double* signal, int n) {
    if (n < 2) return 0;
    
    int count = 0;
    double* ptr = signal;
    
    for (int i = 0; i < n - 1; i++) {
        double current = *ptr;
        double next = *(ptr + 1);
        
        // Product is negative if one number is positive and the other is negative
        if ((current > 0 && next < 0) || (current < 0 && next > 0)) {
            count++;
        }
        ptr++;
    }
    
    return count;
}

// --- Function 4: Apply Gain In-Place ---
void applyGain(double* signal, int n, double gainFactor) {
    double* ptr = signal;
    for (int i = 0; i < n; i++) {
        *ptr *= gainFactor;
        ptr++;
    }
}

// --- Helper Function to Print Array using Pointers ---
void printArray(const std::string& label, double* signal, int n) {
    std::cout << label << ": [";
    double* ptr = signal;
    for (int i = 0; i < n; i++) {
        std::cout << *ptr;
        if (i < n - 1) std::cout << ", ";
        ptr++;
    }
    std::cout << "]\n";
}

int main() {
    // Given test signal
    const int n = 7;
    double testSignal[n] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};

    std::cout << "=================== INITIAL STATE ===================\n";
    printArray("Test signal", testSignal, n);
    
    // 1. Compute & Print RMS
    double rms = computeRMS(testSignal, n);
    std::cout << "Initial RMS: " << rms << "\n";
    
    // 2. Count & Print Zero Crossings
    int crossings = countZeroCrossings(testSignal, n);
    std::cout << "Zero Crossings: " << crossings << "\n\n";

    // 3. Normalise & Print Pipeline Step
    std::cout << "=================== NORMALISATION ===================\n";
    normalise(testSignal, n);
    printArray("After normalise()", testSignal, n);
    std::cout << "Post-Normalise RMS: " << computeRMS(testSignal, n) << "\n\n";

    // 4. Apply Gain & Print Pipeline Step
    std::cout << "=================== APPLYING GAIN ===================\n";
    double gain = 1.5;
    std::cout << "Applying Gain Factor: " << gain << "\n";
    applyGain(testSignal, n, gain);
    printArray("After applyGain()", testSignal, n);
    std::cout << "Post-Gain RMS: " << computeRMS(testSignal, n) << "\n";

    return 0;
}

#include <iostream>
#include <cmath>

// Define M_PI if it isn't automatically defined by <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --- Function 1: Compute Euclidean Distance ---
inline double distanceBetween(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

// --- Function 2: Convert Degrees to Radians ---
inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

// --- Function 3: Clamp a Value to a Specific Range ---
inline double clamp(double value, double minVal, double maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

// --- Function 4: Check if within Safe Zone Circle ---
inline bool isInSafeZone(double x, double y, double cx, double cy, double radius) {
    // If the distance from center is less than or equal to radius, it's inside
    return distanceBetween(x, y, cx, cy) <= radius;
}

int main() {
    // Requirements set by assignment
    const double homeX = 0.0;
    const double homeY = 0.0;
    const double safeZoneRadius = 50.0;

    // Define 3 test waypoints (X, Y)
    // Waypoint 1: Well inside the radius
    // Waypoint 2: Exactly on the border (30-40-50 triangle)
    // Waypoint 3: Far outside the safe zone
    double waypoints[3][2] = {
        {10.5, 20.0},
        {30.0, 40.0},
        {55.0, 12.5}
    };

    std::cout << "Home Position : (" << homeX << ", " << homeY << ")\n";
    std::cout << "Safe Zone Rad : " << safeZoneRadius << " units\n";
    std::cout << "-----------------------------------------------\n";

    for (int i = 0; i < 3; i++) {
        double wpX = waypoints[i][0];
        double wpY = waypoints[i][1];

        // Calculate distance from home
        double dist = distanceBetween(homeX, homeY, wpX, wpY);
        
        // Determine safe-zone presence
        bool safe = isInSafeZone(wpX, wpY, homeX, homeY, safeZoneRadius);

        std::cout << "Waypoint " << (i + 1) << "    : (" << wpX << ", " << wpY << ")\n";
        std::cout << " Distance     : " << dist << " units\n";
        std::cout << " Safe Zone?   : " << (safe ? "YES (Within Boundary)" : "NO (Breached)") << "\n";
        std::cout << "-----------------------------------------------\n";
    }

    // Quick demonstration of clamp utility functioning
    std::cout << "Bonus Clamp Demo (Clamping 120.0 between 0 and 100): " 
              << clamp(120.0, 0.0, 100.0) << "\n";

    return 0;
}

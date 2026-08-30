#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a threshold for system shutdown if not explicitly passed
// (Commonly 60°C or critical + 15°C in standard embedded sensor exercises)
#define SHUTDOWN_THRESHOLD 60

int main(int argc, char *argv[]) {
    // 1. Check for missing arguments
    if (argc < 4) {
        printf("Usage   : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>\n");
        printf("Error   : Missing arguments.\n");
        return 1;
    }

    // Parse input values from command line arguments
    int warn_threshold = atoi(argv[1]);
    int critical_threshold = atoi(argv[2]);
    int num_readings = atoi(argv[3]);

    // 2. Validate inputs according to the requirements
    if (warn_threshold >= critical_threshold) {
        printf("Usage   : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>\n");
        printf("Error   : Validation failed. Warning threshold must be less than critical threshold.\n");
        return 1;
    }

    if (num_readings < 1 || num_readings > 500) {
        printf("Usage   : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>\n");
        printf("Error   : Validation failed. Number of readings must be between 1 and 500.\n");
        return 1;
    }

    // Print configuration alignment to match the exact requirement format
    printf("Config  : Warn=%d°C  Critical=%d°C  Readings=%d\n", warn_threshold, critical_threshold, num_readings);

    // Seed the random number generator for simulation variety
    srand(time(NULL));

    // Category counters
    int normal_count = 0;
    int warning_count = 0;
    int critical_count = 0;
    int shutdown_count = 0;

    // 3. Simulate and classify readings
    for (int i = 0; i < num_readings; i++) {
        int temperature = rand() % 70; // Generates values between 0 and 69

        if (temperature < warn_threshold) {
            normal_count++;
        } else if (temperature < critical_threshold) {
            warning_count++;
        } else if (temperature < SHUTDOWN_THRESHOLD) {
            critical_count++;
        } else {
            shutdown_count++;
        }
    }

    // Print summary output with exact colon column positioning alignment
    printf("Results : Normal:%d  Warning:%d  Critical:%d  Shutdown:%d\n", 
           normal_count, warning_count, critical_count, shutdown_count);

    return 0;
}

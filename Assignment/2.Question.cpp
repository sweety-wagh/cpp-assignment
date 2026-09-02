#include <iostream>

using namespace std;

void runSensorAnalysis(int N) {
    int skipped = 0, valid_count = 0;
    int normal = 0, warning = 0, critical = 0, shutdown = 0;
    int first_crit_idx = -1;
    double temp, total_sum = 0, first_crit_val = 0;
    double min_val = 0.0, max_val = 0.0;

    cout << "Enter " << N << " temperatures:\n";
    
    for (int i = 1; i <= N; i++) {
        cin >> temp;

        // 1. Skip errors
        if (temp < 0) {
            skipped++;
            continue; 
        }

        // 2. Track valid data
        valid_count++;
        total_sum += temp;

        // 3. Smart Min and Max Initialization
        if (valid_count == 1) {
            min_val = temp; // Set the baseline minimum
            max_val = temp; // Set the baseline maximum
        } else {
            if (temp < min_val) min_val = temp;
            if (temp > max_val) max_val = temp;
        }

        // 4. Find first reading >= 45°C
        if (temp >= 45.0 && first_crit_idx == -1) {
            first_crit_idx = valid_count;
            first_crit_val = temp;
        }

        // 5. Count categories
        if (temp < 30.0) normal++;
        else if (temp < 45.0) warning++;
        else if (temp < 55.0) critical++;
        else shutdown++;
    }

    // Print final results
    cout << "\nReadings entered : " << N << endl;
    cout << "Skipped (errors) : " << skipped << endl;
    
    if (first_crit_idx != -1) {
        cout << "First CRITICAL   : Index " << first_crit_idx << " -> " << first_crit_val << "C" << endl;
    }
    
    double avg = (valid_count > 0) ? (total_sum / valid_count) : 0.0;
    cout << "Min : " << min_val << "C  Max : " << max_val << "C  Avg : " << avg << "C\n";
    cout << "Normal:" << normal << "  Warning:" << warning << "  Critical:" << critical << "  Shutdown:" << shutdown << endl;
}

int main() {
    int N;
    cout << "Enter number of readings: ";
    cin >> N;

    runSensorAnalysis(N);

    return 0;
}

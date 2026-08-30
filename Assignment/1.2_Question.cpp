#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Array to store maximum 100 temperature readings
    double temperature[100];

    int n;

    // Counters
    int skipped = 0;
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    // Variables for calculations
    double sum = 0;
    double minTemp = 0;
    double maxTemp = 0;
    int validCount = 0;


    // ------------------------------------------------
    // 1. Accept N
    // ------------------------------------------------

    cout << "Enter number of readings: ";
    cin >> n;


    // ------------------------------------------------
    // 2. Read N temperature values
    // ------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        cin >> temperature[i];
    }


    // ------------------------------------------------
    // 3. Process all readings
    // ------------------------------------------------

    cout << "Readings entered : " << n << endl;

    cout << "Valid readings   : ";

    for (int i = 0; i < n; i++)
    {
        // If temperature is negative,
        // it is a sensor error.
        if (temperature[i] < 0)
        {
            skipped++;

            // Skip this iteration
            continue;
        }


        // Print valid reading
        cout << fixed << setprecision(1)
             << temperature[i] << "  ";


        // Count valid readings
        validCount++;


        // Add temperature to sum
        sum = sum + temperature[i];


        // ------------------------------------------------
        // Find minimum and maximum
        // ------------------------------------------------

        // First valid reading becomes
        // both minimum and maximum
        if (validCount == 1)
        {
            minTemp = temperature[i];
            maxTemp = temperature[i];
        }

        // Check minimum
        if (temperature[i] < minTemp)
        {
            minTemp = temperature[i];
        }

        // Check maximum
        if (temperature[i] > maxTemp)
        {
            maxTemp = temperature[i];
        }


        // ------------------------------------------------
        // Count categories
        // ------------------------------------------------

        if (temperature[i] < 25)
        {
            normal++;
        }
        else if (temperature[i] < 45)
        {
            warning++;
        }
        else if (temperature[i] <= 50.2)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }


    cout << endl;


    // ------------------------------------------------
    // 4. Print skipped errors
    // ------------------------------------------------

    cout << "Skipped (errors) : " << skipped << endl;


    // ------------------------------------------------
    // 5. Find FIRST reading >= 45
    // ------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        if (temperature[i] >= 45)
        {
            cout << endl;

            // +1 because sample uses position starting from 1
            cout << "First CRITICAL   : Index "
                 << i + 1
                 << " -> "
                 << fixed << setprecision(1)
                 << temperature[i]
                 << " C"
                 << endl;

            // Stop searching
            break;
        }
    }


    // ------------------------------------------------
    // 6. Calculate average
    // ------------------------------------------------

    double average = sum / validCount;


    // ------------------------------------------------
    // 7. Print min, max and average
    // ------------------------------------------------

    cout << endl;

    cout << fixed << setprecision(2);

    cout << "Min : " << minTemp << " C    ";

    cout << "Max : " << maxTemp << " C    ";

    cout << "Avg : " << average << " C"
         << endl;


    // ------------------------------------------------
    // 8. Print category counts
    // ------------------------------------------------

    cout << endl;

    cout << "Normal:" << normal
         << "   Warning:" << warning
         << "   Critical:" << critical
         << "   Shutdown:" << shutdown
         << endl;


    return 0;
}
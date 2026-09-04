#include<iostream>
using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup; 

public:
    // Fixed: Default Constructor now properly initializes the const string bloodGroup
    Patient() : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "default" << endl;
    }

    Patient(int id, const string& n) : patientId(id), name(n), age(0), ward("Emergency"), bloodGroup("O+") {
        cout << "emergency" << endl;
    }

    Patient(int id, const string& n, int a, const string& w, const string& bg) : patientId(id), name(n), age(a), ward(w), bloodGroup(bg) {
        cout << "new patient" << endl;
    }

    // Destructor
    ~Patient() {
        cout << "[destructor] " << name << " discharged." << endl;
    }

    // Regular Methods
    void displayRecord() const {
        cout << "patientId: " << patientId << endl;
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "ward: " << ward << endl;
        cout << "bloodGroup: " << bloodGroup << endl;
        cout << "-----------------------" << endl;
    }

    void transferWard(const string& newWard) {
        cout << "Ward Transfer: " << name << " -> " << newWard << endl;
        ward = newWard;
    }
};

int main() {
    Patient p1(1101, "swee", 21, "cart", "o+");
    Patient p2(1102, "raj"); // Fixed name slightly to match your output requirements
    Patient p3;

    cout << "\n=== HEAP ARRAY ALLOCATION ===" << endl;
    Patient* heapArray = new Patient[4];
    
    for(int i = 0; i < 4; i++) {
        heapArray[i].displayRecord();
    }

    cout << "\n=== OPERATION ===" << endl;
    p2.transferWard("ICU");

    cout << "\n=== HEAP DEALLOCATION (delete[]) ===" << endl;
    delete[] heapArray;

    cout << "\n=== CLOSING MAIN (Stack Cleanup) ===" << endl;
    // Fixed: Removed duplicate return
    return 0; 
}
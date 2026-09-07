#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Optional Bonus Structures for Padding Demonstration
struct Layout1 { char c1; int i; char c2; };
struct Layout2 { int i; char c1; char c2; };

class Employee {
private:
    // Private data members
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    // Static counter
    static int employeeCount;

public:
    // Constructor handles auto-assigning unique empId starting at 1001
    Employee() {
        employeeCount++;
        empId = 1000 + employeeCount;
        name = "Unknown";
        department = "Operations";
        grade = 'D';
        basicSalary = 10000.0;
        isActive = true;
    }

    // --- Public Setters (with validation) ---
    bool setName(const string& n) {
        if (n.empty()) {
            cout << "ERROR: Name cannot be empty.\n";
            return false;
        }
        name = n;
        return true;
    }

    bool setDepartment(const string& dept) {
        if (dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations") {
            department = dept;
            return true;
        }
        cout << "ERROR: '" << dept << "' is not a registered department.\n";
        return false;
    }

    bool setGrade(char g) {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D') {
            grade = g;
            return true;
        }
        cout << "ERROR: Invalid grade '" << g << "'. Accepted values: A, B, C, D.\n";
        return false;
    }

    bool setBasicSalary(double salary) {
        if (salary >= 10000.0 && salary <= 500000.0) {
            basicSalary = salary;
            return true;
        }
        cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected.\n";
        return false;
    }

    void deactivate() {
        isActive = false;
    }

    // --- Public Getters (All marked const) ---
    int getEmpId() const { return empId; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    char getGrade() const { return grade; }
    double getBasicSalary() const { return basicSalary; }
    bool getIsActive() const { return isActive; }

    // --- Business Logic (All marked const) ---
    double computeAllowances() const {
        switch (grade) {
            case 'A': return basicSalary * 0.40;
            case 'B': return basicSalary * 0.30;
            case 'C': return basicSalary * 0.20;
            case 'D': return basicSalary * 0.10;
            default:  return 0.0;
        }
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();
        if (gross <= 50000.0) {
            return 0.0;
        } else if (gross <= 100000.0) {
            return (gross - 50000.0) * 0.10;
        } else {
            return 5000.0 + ((gross - 100000.0) * 0.20);
        }
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const {
        if (!isActive) return;

        int allowancePct = (grade == 'A') ? 40 : (grade == 'B') ? 30 : (grade == 'C') ? 20 : 10;

        cout << "============================================\n";
        cout << "EMPLOYEE PAYSLIP -- AUG 2026\n";
        cout << "============================================\n";
        cout << left << setw(12) << "Emp ID"      << ": " << empId << "\n";
        cout << left << setw(12) << "Name"        << ": " << name << "\n";
        cout << left << setw(12) << "Department"  << ": " << department << "\n";
        cout << left << setw(12) << "Grade"       << ": " << grade << "\n";
        cout << left << setw(12) << "Status"      << ": " << (isActive ? "Active" : "Inactive") << "\n";
        cout << "-------------------------------------------\n";
        cout << fixed << setprecision(2);
        cout << left << setw(17) << "Basic Salary"     << ":  Rs. " << right << setw(10) << basicSalary << "\n";
        cout << left << "Allowances (" << allowancePct << "%)" << setw(11) << "" << ":  Rs. " << right << setw(10) << computeAllowances() << "\n";
        cout << left << setw(17) << "Gross Salary"    << ":  Rs. " << right << setw(10) << computeGrossSalary() << "\n";
        cout << "-------------------------------------------\n";
        cout << left << setw(17) << "Tax Deduction"   << ":  Rs. " << right << setw(10) << computeTax() << "\n";
        cout << left << setw(17) << "Net Salary"      << ":  Rs. " << right << setw(10) << computeNetSalary() << "\n";
        cout << "============================================\n\n";
    }

    // --- Input Processing ---
    void acceptDetails() {
        string inName, inDept;
        char inGrade;
        double inSalary;

        cout << "----- Entering Details for Employee #" << empId << " -----\n";
        
        cin.ignore(cin.rdbuf()->in_avail(), '\n'); // Clear residual markers cleanly
        cout << "Enter name: ";
        getline(cin, inName);
        while (!setName(inName)) {
            cout << "Re-enter name: ";
            getline(cin, inName);
        }

        cout << "Enter department: ";
        getline(cin, inDept);
        while (!setDepartment(inDept)) {
            cout << "Re-enter department: ";
            getline(cin, inDept);
        }

        cout << "Enter grade: ";
        cin >> inGrade;
        while (!setGrade(inGrade)) {
            cout << "Re-enter grade: ";
            cin >> inGrade;
        }

        cout << "Enter basic salary: ";
        cin >> inSalary;
        while (!setBasicSalary(inSalary)) {
            cout << "Re-enter basic salary: ";
            cin >> inSalary;
        }
        cout << "--------------------------------------------------------\n\n";
    }

    static int getEmployeeCount() {
        return employeeCount;
    }
};

// Initialize the static variable
int Employee::employeeCount = 0;

int main() {
    // Create objects -- one on stack, two on heap
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Data ingestion phase
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    /* 
     * COMPILER ERROR REFLECTION:
     * Un-commenting the statements below will throw a compilation error:
     * "error: 'int Employee::empId' is private within this context"
     * Reason: These data members are sealed under the 'private' access specifier.
     * Encapsulation completely prevents outside scopes or raw code handles from 
     * directly overwriting state parameters bypassing internal validation systems.
     */
    // e1.empId = 999;
    // e1.basicSalary = -1000;

    // Generate Payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Simulate a resignation
    e3->deactivate();
    if (!e3->getIsActive()) {
        cout << e3->getName() << " is no longer active. Payroll skipped.\n\n";
    }

    cout << "Total Employees : " << Employee::getEmployeeCount() << "\n\n";

    // Clean up heap memory allocations
    delete e2;
    delete e3;

    // --- Bonus Execution and Print Block ---
    cout << "================= BONUS STRUCT DEMO =================\n";
    cout << "sizeof(Layout1): " << sizeof(Layout1) << " bytes\n";
    cout << "sizeof(Layout2): " << sizeof(Layout2) << " bytes\n";
    
    /* 
     * STRUCT PADDING & MEMORY ALIGNMENT EXPLANATION:
     * CPUs read memory in word-sized chunks (typically 4 or 8 bytes) rather than single bytes.
     * To maximize memory bus read efficiency, compilers align variables to boundaries equal to their size.
     * 
     * In Layout1 (char, int, char):
     * - c1 takes 1 byte. 3 bytes of internal padding are added so 'int i' can start on a 4-byte boundary.
     * - i takes 4 bytes.
     * - c2 takes 1 byte. 3 tail padding bytes are appended to match total struct block alignment rules.
     * Total = 1 + (3 pad) + 4 + 1 + (3 pad) = 12 bytes.
     * 
     * In Layout2 (int, char, char):
     * - i takes 4 bytes perfectly.
     * - c1 takes 1 byte.
     * - c2 takes 1 byte right next to c1. 2 tail padding bytes are appended to pad out to 4.
     * Total = 4 + 1 + 1 + (2 pad) = 8 bytes.
     */
    cout << "=====================================================\n";

    return 0;
}

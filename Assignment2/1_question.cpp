#include<iostream>
#include<string> 
using namespace std;

// ========================================================
// PART A — PRODUCT CLASS
// ========================================================
class Product {
private:
    int ProductID;
    string name;
    double price;
    int quantity;

public:
    Product() {
        ProductID = 0;
        name = "";
        price = 0.0;
        quantity = 0;
    }

    void acceptDetails() {
        cout << "Enter ProductID: ";
        cin >> ProductID;
        cout << "Enter Name: ";
        cin >> name; 
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << ProductID << " \t " << name << " \t " << price << " \t " << quantity << " \t " << totalValue();
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    string getName() const {
        return name;
    }
};

// ========================================================
// PART B — STANDALONE OVERLOADED FUNCTIONS
// ========================================================

// 1. Integer quantity
double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

// 2. Fractional quantity (by weight)
double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

// 3. Integer quantity with tax rate percentage
double reorderCost(int qty, double unitPrice, double taxRate) {
    double baseCost = qty * unitPrice;
    return baseCost + (baseCost * (taxRate / 100.0));
}

// 4. Function with a default argument (10% applied automatically if omitted)
double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * (discountPercent / 100.0));
}


// ========================================================
// MAIN EXECUTION CONTEXT
// ========================================================
int main() {
    // --- Part A: Inventory Tracking ---
    Product arr[5];
    
    for(int i = 0; i < 5; i++) {
        cout << "\n--- Enter details for Product " << (i + 1) << " ---" << endl;
        arr[i].acceptDetails();
    }

    int thershold;
    cout << "\nEnter low stock threshold: ";
    cin >> thershold;

    cout << "\n===== INVENTORY REPORT =====" << endl;
    cout << "ID \t Name \t Price \t Qty \t Total Value" << endl;
    
    for(int i = 0; i < 5; i++) {
        arr[i].displayDetails();
        if(arr[i].isLowStock(thershold)) {
            cout << "  ← LOW STOCK";
        }
        cout << endl;
    }

    double maxval = -1.0;
    int highestValueIdx = 0;
    for(int i = 0; i < 5; i++) {
        if(arr[i].totalValue() > maxval) {
            maxval = arr[i].totalValue();
            highestValueIdx = i;
        }
    }
    
    cout << "\nHighest Value Product : " << arr[highestValueIdx].getName() 
         << " (Rs. " << arr[highestValueIdx].totalValue() << ")" << endl;

    // --- Part A-5: Low Stock Summary List ---
    cout << "Low Stock (threshold: " << thershold << ") : ";
    bool firstMatch = true;
    for (int i = 0; i < 5; i++) {
        if (arr[i].isLowStock(thershold)) {
            if (!firstMatch) {
                cout << ", ";
            }
            cout << arr[i].getName();
            firstMatch = false;
        }
    }
    if (firstMatch) {
        cout << "None";
    }
    cout << "\n" << endl;


    // --- Part B: Testing Overloaded Functions ---
    cout << "===== PART B: FUNCTION OVERLOADING TEST =====" << endl;
    
    // Call 1: Integer quantity
    cout << "Reorder Cost (Integer Qty 10 @ Rs 25.5): Rs. " 
         << reorderCost(10, 25.5) << endl;

    // Call 2: Fractional weight quantity
    cout << "Reorder Cost (Fractional Qty 12.5 @ Rs 20.0): Rs. " 
         << reorderCost(12.5, 20.0) << endl;

    // Call 3: Integer quantity with an added 18.0% tax
    cout << "Reorder Cost (Integer Qty 10 @ Rs 25.5 with 18% Tax): Rs. " 
         << reorderCost(10, 25.5, 18.0) << endl;

    // Call 4a: Discount omitting second argument (Triggers 10% default parameter)
    cout << "Apply Discount (Default 10% on Rs 200.00): Rs. " 
         << applyDiscount(200.00) << endl;

    // Call 4b: Discount passing second argument explicitly (Overrides default to 25%)
    cout << "Apply Discount (Custom 25% on Rs 200.00): Rs. " 
         << applyDiscount(200.00, 25.0) << endl;

    return 0;
}

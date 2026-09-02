
#include <iostream>
#include <string>
using namespace std;

int ID = 1001;

class Product{
private:
	int productId;
	string name;
	double price;
	int quantity;
public:
	Product(){
		productId = ID++;
	}
	// Read all fields from user
	void acceptDetails(){
		string s;
		cout<<"Enter Name: ";
		getline(cin, s);
		name = s;
		cout<<"Enter Price: ";
		getline(cin, s);
		price = stod(s);
		cout<<"Enter quantity: ";
		getline(cin,s);
		quantity = stoi(s);

	}
		// Print formatted product info
	double totalValue() const{
		return price * quantity;// price * quantity
	}
	void displayDetails() const{
		cout<<productId<<" "<<name<<" "<<price<<" "<<quantity<<" "<<totalValue();
	}
	bool isLowStock(int threshold) const{
		return quantity < threshold; // true if quantity < threshold
	}
	string getName() const{
		return name;
	}

};

	void displayLowStock(string arr[], int& size){
		for(int i = 0; i < size; i++){
			cout<<arr[i]<<" ";
		}

}
	//integer quantity
	double reorderCost(int qty, double unitPrice){
		return qty * unitPrice;
	}
	//fractional (by weight)
	double reorderCost(double qty, double unitPrice){
		return unitPrice * qty;
	}
	//with tax
	double reorderCost(int qty, double unitPrice, double taxRate){
		return qty * unitPrice * (1 + taxRate);
		//100 * 2000 * taxrate in decimals
	}

	// If no discount is passed, apply 10% by default
	double applyDiscount(double price, double discountPercent = 10.0){
		return price - (price * (discountPercent/100));
	}



int main() {

	int size = 5;
	Product p_arr[size];
	for(int i= 0; i < size; i++){
		p_arr[i].acceptDetails();
	}

	cout<<"===== INVENTORY REPORT ====="<<endl;
	cout<<"ID Name Price Qty Total Value"<<endl;
	for(int i= 0; i < size; i++){
			p_arr[i].displayDetails();
			cout<<endl;
		}

	double max_val = INT_MIN;
	string highest_v_product = "";

	for(int i = 0; i < size; i++){
		double curr_value_product = p_arr[i].totalValue();

		if(curr_value_product > max_val){
			max_val = curr_value_product;
			highest_v_product = p_arr[i].getName();
		}
	}

	int threshold = 10;
	string arr[size];

	for(int i = 0; i < size; i++){
			bool isValid = p_arr[i].isLowStock(threshold);
			if(isValid){
				arr[i] = p_arr[i].getName();
			}
		}

	cout<<"Highest Value Product: "<<highest_v_product<<" "<<max_val<<" Rs"<<endl;
	cout<<"Low Stock "<<"Threshold: "<<threshold<<": ";
	displayLowStock(arr,size);

	cout<<reorderCost(10, 120)<<endl;
	cout<<reorderCost(20, 200)<<endl;
	cout<<reorderCost(45, 250, 10)<<endl;
	cout<<applyDiscount(2000, 20)<<endl;

return 0;
}

#include <iostream>
using namespace std;

int main() {
	int statusReg = 0b10110001; // Read-only from firmware side
	int controlReg = 0b00000000; // Firmware writes here
	int dataReg = 0b11001010; // For reassignment demo

	const int* regPtr1 = &statusReg;
	cout<<"Value of statusReg: "<<statusReg<<endl;
	cout<<"Value of regPtr1 (holds address of statusReg): "<<regPtr1<<endl;
	//*regPtr1 = 10; error: assignment of read-only location '* regPtr1'
	//we cannot change the value of the statusReg because we have defined a const int type of pointer variable
	int a = 10;
	regPtr1 = &a; //this can be done because the pointer variable is not constant.
	cout<<"Value of new regPtr1: "<<regPtr1<<endl;

	cout<<endl;
	cout<<endl;
	int* const regPtr2 = &controlReg;
	cout<<"Value of regPtr2 (holds address of controlReg): "<<regPtr2<<endl;
	cout<<"Value of controlReg: "<<controlReg<<endl;
	//here we can change the value of controlReg, because the pointer variable is just int pointer, not a const
	*regPtr2 = 10;
	cout<<"Value of changed controlReg: "<<controlReg<<endl;
//	regPtr2 = &a; //not allowed error: assignment of read-only variable 'regPtr2'
	//cannot change the the value it holds because we have made the pointer variable itself a constant

	cout<<endl;
	cout<<endl;
	const int* const regPtr3 = &dataReg;
	//here i cannot change the value of integer which pointer is pointng to as well as the pointer varible's value
	cout<<"Value of regPtr3 (holds address of dataReg): "<<regPtr3<<endl;
	cout<<"Value of dataReg: "<<dataReg<<endl;
//	*regPtr3 = 10; error: assignment of read-only location '*(const int*)regPtr3'
//	regPtr3 = &a;  error: assignment of read-only variable 'regPtr3'

	return 0;
}

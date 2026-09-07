
#include <iostream>
#include <cmath>
using namespace std;

inline double distanceBetween(double x1, double y1, double x2, double y2){
	 double ret = sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
	 return ret;
}
inline double toRadians(double degrees){
	double ret = degrees * (M_PI / 180.0);
	return ret;
}

inline double clamp(double value, double minVal, double maxVal){
// Restrict value to [minVal, maxVal]
	if(value < minVal){
		value = minVal;
	}
	if(value > maxVal){
		value = maxVal;
	}

	return value;
}

void displayResults(bool isSafe, double x2, double y2){
	if(isSafe){
			cout<<"Cordinates : "<<x2<<" "<<y2<<" Safe"<<endl<<"Distance: "<<distanceBetween(0,0,x2,y2)<<endl;
		}
	else{
		cout<<"Cordinates : "<<x2<<" "<<y2<<" Not Safe"<<endl<<"Distance: "<<distanceBetween(0,0,x2,y2)<<endl;
	}
	cout<<endl;
}

// true if point (x,y) is within the circle centred at (cx,cy) with given radius
inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){
	double dist = distanceBetween(x, y, cx, cy);
	if(dist <= radius) return true;

	return false;
}


int main() {
	double x2 = 10;
	double y2 = 10;

	double x3 = 50;
	double y3 = 50;

	double x4 = 55;
	double y4 = 55;

//	double dist = distanceBetween(0, 0, x2, y2);
//	cout<<"Distance between the home position and waypoint: "<<dist<<endl;

	bool isSafe = isInSafeZone(x2,y2,0,0,50);
	displayResults(isSafe, x2,y2);

	isSafe = isInSafeZone(x3,y3,0,0,50);
	displayResults(isSafe,x3,y3);

	isSafe = isInSafeZone(x4,y4,0,0,50);
	displayResults(isSafe,x4,y4);

	cout<<"------------------Clamp---------------------"<<endl;
	double clamp_ret = clamp(150, 100, 200);
	cout<<"No Change as it's within range: "<<clamp_ret<<endl;

	clamp_ret = clamp(10, 100, 200);
	cout<<"Change to minimum value as it's below that: "<<clamp_ret<<endl;

	clamp_ret = clamp(250, 100, 200);
	cout<<"Change to maximum value as it's above that: "<<clamp_ret<<endl;

	cout<<"------------------Degree to radians---------------------"<<endl;
	double radians_ret = toRadians(150);
	cout<<"Radians: "<<radians_ret<<endl;



	return 0;
}


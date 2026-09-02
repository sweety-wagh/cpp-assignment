
#include <iostream>
using namespace std;

void getStatusCount(double temperature, int& normal_cnt, int& warning_cnt, int& critical_cnt, int& shutdown_cnt, double& custom_warning_temp, double& custom_critical_temp){
	if(temperature < 0){

		}
		else if(temperature >= 0 && temperature < custom_warning_temp){
			normal_cnt++;
		}
		else if(temperature >= custom_warning_temp && temperature < custom_critical_temp){
			warning_cnt++;
		}
		else if(temperature >= custom_critical_temp && temperature <= 59){
			critical_cnt++;
		}
		else{
			shutdown_cnt++;
		}
}



int main(int argc, char* argv[]) {
	if(argc < 4){
		cout<<"Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>"<<endl;
		cout<<"Error : Missing arguments."<<endl;
		return 1;
	}

	double warn_temp = (double)stoi(argv[1]);
	double critical_temp = (double)stoi(argv[2]);
	double reading = (double)stoi(argv[3]);

	if(warn_temp > critical_temp){
		cout<<"INVALID TEMP"<<endl;
		return 1;
	}
	if(reading < 0 || reading > 100){
		cout<<"INVALID READINGS"<<endl;
		return 1;
	}
	cout<<"Config : "<<"Warn= "<<warn_temp<<" "<<"Critical= "<<critical_temp<<" "<<"Readings= "<<reading<<endl;
	int n = reading;
	int normal_cnt =0;
	int warning_cnt =0;
	int critical_cnt =0;
	int shutdown_cnt =0;

	while(n--){
		double random_val = rand() % 70;
//		cout<<"Random Value: "<<random_val<<endl;
		getStatusCount(random_val, normal_cnt, warning_cnt, critical_cnt, shutdown_cnt, warn_temp, critical_temp);
	}
	cout<<"Results : "<<"Normal: " <<normal_cnt<<" "<<"Warning: "<<warning_cnt<<" "<<"Critical: "<<critical_cnt<<" "<<"Shutdown: "<<shutdown_cnt<<" "<<endl;

	return 0;
}
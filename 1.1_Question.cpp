#include <iostream>
using namespace std;

int getrange(double range){
    if (range<0){
        return -1;
    }else if (range>=0 && range<=29){
        return 0;
    }else if (range>=30 && range<=44){
        return 1;
     }else if (range>=45&& range<=59){
        return 2;
     }else {
        return 3;
     }
    }
    
    void statusLabel(int statusCode){

        switch(statusCode){
            case -1:
            cout<<"Status :Sensor Error"<<endl;
            cout<< "Action :Sensor fault-check wiring"<<endl;
            break;
            
            case 0 :
            cout<<"Status :Normal"<<endl;
            cout<< "Action :No action required"<<endl;
            break;

            case 1 :
            cout<<"Status :Warning"<<endl;
            cout<< "Action :Alert sent to supervisor"<<endl;
            break;

            case 2 :
            cout<<"Status :Critical"<<endl;
            cout<< "Action :Cooling system triggered"<<endl;
            break;

            default :
            cout<<"Status :Shutdown"<<endl;
            cout<< "Action :Emergency shutdown initiated"<<endl;
            break;

        }
    }



 int main(){
    double Reading;
    cout<<"enter sensor reading"<<endl;
    cin>>Reading;
    
    cout << "Temperature: " << Reading << "C / " << (Reading * 9.0 / 5.0) + 32.0 << "F" << endl;


    int statusCode=getrange(Reading);
    statusLabel(statusCode);
    
    
    (Reading>25)?cout<<"Above Average":cout<<"below Average"<<endl;

    cout << "Temperature: " << Reading << "C / " << (Reading * 9.0 / 5.0) + 32.0 << "F" << endl;
    
    return 0;

 }
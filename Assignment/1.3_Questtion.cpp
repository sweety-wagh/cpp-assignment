#include<iostream>
using namespace std;

void hottestRoom(double arr[3][3]){

    int max = arr[0][0];
    int floor = 0;
    int room = 0;
    
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(max < arr[i][j]){
                max = arr[i][j];
                floor = i+1;
                room = j+1;
            }
        }
    }

    cout<< "Hottest Room : "<<"Floor " << floor << ", "<< "Room"  << room << "->"<< max <<"C"<<endl;
}

void hottestFloor(double arr[3][3]){
    double max = (arr[0][0] + arr[0][1] + arr[0][2]) / 3;
    int floor = 1;
    for(int i = 1;i<3;i++){

        int sum = 0;
        for(int j = 0;j<3;j++){
            sum+=arr[i][j];
        }

        double avg = sum / 3;

        if(avg > max){
            max = avg;
            floor = i+1;
        }
    }

    cout<<" Hottest Floor : Floor "<< floor <<  "(avg " << max << "C)"  << endl;
}

void warnings(double arr[3][3]){

    int count = 0;

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(arr[i][j] >= 30 ){
                count++;
            }
        }
    }

    cout << "Rooms at WARNING or above : "<< count  << endl;
}

int main(){

    cout<<"Enter the data of 9 rooms!!" << endl;
    double arr[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"\tRoom1 \tRoom2 \tRoom3" << endl;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<"Floor 1:";
            cout<<arr[i][j] << "\t";
        }
        cout<<endl;
    }

    hottestRoom(arr);
    hottestFloor(arr);
    warnings(arr);

    return 0;
}
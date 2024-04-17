#include<iostream>
using namespace std;
class Vehicle   {
private:
    double speed,weight;
public:
    Vehicle(double s,double w): speed(s),weight(w){}
    void run() const  {
        cout << "Weight "<<weight<<", speed "<<speed<<endl;
    }
}; 
 
class Car: public Vehicle {
private:
    int seatNum;
public:
    Car(double s,double w,int n):   Vehicle(s,w),seatNum(n)      {}
    void run() const  {
        Vehicle::run();
        cout << "seatNum: " << seatNum << endl;
    }
}; 
class Bicycle: public Vehicle  {
private:
    int height;
public:
    Bicycle(double s,double w,int h):  Vehicle(s,w),height(h)          {}
    void run() const  {
       Vehicle::run();
       cout<<"height:"<<height<<endl;
    }
};
int main(){
    Car car(100, 300, 4);
    Bicycle bic(20,20,24);
    car.run();
    bic.run();
}



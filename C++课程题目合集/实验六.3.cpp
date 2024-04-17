#include<iostream>
using namespace std;
class Vehicle {
protected:
	double speed;
	double weight;
public:
	Vehicle(double s = 0, double w = 0);
	virtual void run();
};
class Car :public Vehicle {
	int seatNum;
public:
	Car(double s=0, double w=0, int seat=0):Vehicle(s, w),seatNum(seat){}
	void run();
};
class Bicycle :public Vehicle {
	double height;
public:
	Bicycle(double s = 0, double w = 0, double h = 0):Vehicle(s, w),height(h){}
	void run();
};
Vehicle::Vehicle(double s,double w) {
	speed = s;
	weight = w;
}
void Vehicle::run() {
	cout << "Weight " << weight << ", speed " << speed << endl;
}

void Car::run() {
	Vehicle::run();
	cout << "seatNum: " << seatNum << endl;
}
void Bicycle::run() {
	Vehicle::run();
	cout << "height: " << height << endl;
}
int main() {
	Vehicle v(100, 500);
	v.run();
	Car car(120, 400, 6);
	car.run();
	Bicycle bicycle(30, 10, 26);
	bicycle.run();
	Vehicle* vp;
	vp = &car;
	vp->run();
	vp = &bicycle;
	vp->run();
	return 0;
} 

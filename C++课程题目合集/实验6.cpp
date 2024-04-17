#include<iostream>
#include<cmath>
using namespace std;
class Point2d {
protected:
    double _x, _y;
public:
    static double PI; //复习static成员，该值可提供给各派生类，合成类使用
    Point2d(double x0 = 0, double y0 = 0);
    double x()const; //得到x坐标
    double y()const;
    void set_x(double x0); //设置x坐标
    void set_y(double y0);
    void movetoxy(double x0, double y0); //把x,y坐标更改为x0,y0
    double disToOrigin();
    Point2d& operator+=(const Point2d& d);
    friend Point2d operator+(const Point2d& a,const  Point2d& b);
    friend bool operator<( Point2d& a,  Point2d& b);
    friend bool operator==(const Point2d& a, const Point2d& b);
    friend bool operator!=( const Point2d& a,const  Point2d& b);
    friend ostream& operator<<(ostream& o,const  Point2d& d);
};
double Point2d::PI = 0;
Point2d::Point2d(double x0 , double y0) {
	_x = x0;
	_y = y0;
}
double Point2d::x()const {
	return _x;
}
double Point2d::y()const {
	return _y;
}
void Point2d::set_x(double x0) {
	_x = x0;
}
void Point2d::set_y(double y0) {
	_y = y0;
}
void Point2d::movetoxy(double x0, double y0) {
	_x = x0;
	_y = y0;
}
double Point2d::disToOrigin() {
	
	return sqrt(_x*_x+_y*_y);
}
Point2d& Point2d::operator+=(const Point2d& d) {
	_x = _x + d._x;
	_y = _y + d._y;
	return *this;
}
Point2d operator+(const Point2d& a, const Point2d& b) {
	Point2d c(a._x + b._x, a. _y + b._y);
	return c;
}
bool operator < ( Point2d& a, Point2d& b) {
	if (a.disToOrigin()< b.disToOrigin())return 1;
	else return 0;
}
bool operator ==(const Point2d& a,const  Point2d& b) {
	if (a._x != b._x)return 0;
	else if (a._y != b._y)return 0;
	else { return 0; }
}
bool operator !=(const Point2d& a,const  Point2d& b) {
	if (a == b)return 0;
	else { return 1; }
}
ostream & operator << ( ostream & o, const Point2d & d) {
	o << "(" << d._x<< "," << d._y << ")" ;
	return o;
}
int main() {
	Point2d A(2, 1);
	Point2d B(2, 1);
	Point2d C;
	if (A == B) { cout << "equal" << endl; }
	cout << C << endl;
	A.set_x(5);
	A.set_y(6);
	cout<<A<<endl;
	C.movetoxy(5, 6);
	if (A != C) { cout << "unequal" << endl; }
	else { cout << "equal" << endl; }
	if (B < A) { cout << "smaller" << endl; }
	cout << A.disToOrigin() << "," << B.disToOrigin() << "," << C.disToOrigin() << endl;
	C += A;
	cout << C << endl;
	Point2d D = A + C;
	cout << D << endl;
}

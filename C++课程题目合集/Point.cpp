#include<iostream>
using namespace std;
class Point{
	double _x,_y;
	public:
	    Point (double x0=0,double y0=0);
		void init(double x0, double y0);
	    double x();
	    double y(); 
};
double Point::x(){
	return _x;
}
double Point::y(){
	return _y;
}
void Point::init (double x0,double y0){
	_x=x0;
	_y=y0;
}
int main(){
    Point a[1010],s;
    int n;
	double x,y;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x>>y;
    	a[i].init(x,y);
	}
	for (int i = 0; i < n; i++){
    for (int j = 0; j < n-i-1; j++){
    if (((a[j].x())*(a[j].x())+(a[j].y())*(a[j].y()))>((a[j+1].x())*(a[j+1].x())+(a[j+1].y())*(a[j+1].y()))){
    s = a[j];
    a[j] = a[j + 1];
    a[j + 1] = s;
    }
    }
    }
	for(int i=0;i<n;i++){
		cout<<a[i].x()<<" "<<a[i].y()<<endl;	
	}
	return 0;
}

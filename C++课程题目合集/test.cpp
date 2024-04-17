#include<iostream>
using namespace std;
class Point{
	double _x,_y;
	public:
	    Point (double x0=0,double y0=0);
		void init(double x0, double y0);
	    double x();
	    double y(); 
	    void swp(Point , Point);
};
double Point:: x(){
    return _x;
}
double Point::y(){
	return _y;
}
void Point::init (double x0,double y0){
	_x=x0;
	_y=y0;
}
void swap(double *a,double *b){
	double t;
	t=*a;
	*a=*b;
	*b=t;
}
void swp(Point m, Point n){
	int x;
	swap(&m.x(),&n.x());
	swap(&m.y(),&n.y());
}
int main(){
    Point a[1010];
    int n;
	cin>>n;
    for(int i=0;i<n;i++){
      double  c,v;
	  a[i].init(c,v); 
	}
	for(int i=1;i<n;i++){
		int  p=i;
		while(p>0&&(a[p].x()+a[p].y())<(a[p-1].x()+a[p-1].y())){
		    swp(a[p],p[p-1]);
			p--;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i].x()<<" "<<a[i].y()<<endl;	
	}
	return 0;
}

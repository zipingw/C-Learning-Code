#include <iostream>
using namespace std;
class Timer {
private:
    int hour, minute, sec;
public:
    Timer(){hour=minute=sec=0;}
    Timer(int h, int m,int s):hour(h),minute(m),sec(s){}
    Timer &operator++();
    const Timer operator++(int);
    friend ostream &operator<<(ostream &os,const Timer &c);
};
ostream &operator<<(ostream &os,const Timer &c){
    return os<<c.hour<<":"<<c.minute<<":"<<c.sec;
}//================================
//补充前置++和后置++的定义
Timer & Timer::operator++() 
{ if(++sec>=60){
	sec-=60;
	++minute;
}
if(minute>=60){
	minute-=60;
	++hour;
}
return *this;
}
const Timer Timer::operator++(int ){
	Timer temp(*this);
	sec++;
	if(sec>=60){
		sec-=60;
		++minute;
	}
	if(minute>=60){
	minute-=60;
	++hour;
}
	return temp;
}
//================================
int main() {
    Timer t1, t2(1,58,59);
    cout << ++t1 << "\n"; //  0:0:1
    cout << t1++ << "\n"; //  0:0:1
    cout << t1 << "\n"; //  0:0:2
    t2++;
    cout << t2 << "\n"; //  1:59:0
    ++++t2;
    cout << t2++ << "\n"; // 1:59:2
    for(int i=0; i<60; ++i) ++t2;
    //   t1++ = t2;   不允许
    cout << t2 <<"\n"; //  2:0:3
}

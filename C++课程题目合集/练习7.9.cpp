#include<iostream>
using namespace std;
class A {
public:
    A();
    A(int, int = 0);
    ~A();
private:
    int a, b;
};
A::A() : a(1),b(2)        {
    cout << "Construct1: " << a << ","<< b << endl;
}
A::A(int x, int y) :a(x),b(y)   {
    cout << "Construct2: " << a << "," << b << endl;
}
 
A::~A() {
	cout << "Destruct: " << a << "," << b << endl;
	}
int main(){ 
    A  a(3, 5), b(4), c;
    return 0;
}

#include <iostream>     
using namespace std;   
class AA {   
public:   
    AA() { cout << "AA::AA()" << endl; }   
    ~AA() { cout << "AA::~AA()" << endl; }   
};   
class BB {   
public:   
    BB() { cout << "BB::BB()" << endl; }   
    ~BB() { cout << "BB::~BB()" << endl; }   
};   
class CC : public AA {   
public:   
    CC() { cout << "CC::CC()" << endl; }   
    ~CC() { cout << "CC::~CC()" << endl; }   
private:   
    BB bb;   
};   
int main(void)   
{   CC cc;   
    return 0;   }  

#include<iostream>
using namespace std;
class Ball{
public:
Ball(int rad):radius(rad) 
{   cout << "Catch Ball" << endl;   }
~Ball() 
{   cout << "Throw Ball" << endl;         }
protected:
int radius;
};
 
class  Basketball:virtual public Ball{
public:
Basketball(int rad):Ball(rad)
  {  cout<<"Catch ball_2"<<endl;            }
~Basketball()
{          cout<<"Throw ball_2"<<endl;      }
};
 
class Football :virtual public Ball {
public:
Football(int rad):Ball(rad)
{           cout<<"Catch ball_1"<<endl;                   }
~Football() 
{            cout<<"Throw ball_1"<<endl;            }
};
 
class  Dball :public Basketball,public Football{
public:
Dball(int rad):Football(rad),Basketball(rad),Ball(rad)
{    cout << "Catch Dball" << endl;       }
~Dball()
{    cout << "Throw Dball" << endl;   }
};
int main()
{
Dball  ball(6);
return 0;
}

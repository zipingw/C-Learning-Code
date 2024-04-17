#include<iostream>
using namespace std;
//--------------------
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {
        cout<<"cons P:"+name+"\n";    }
    virtual ~Person() {
        cout<<"des P:"+name+"\n";   }};
class Student : public Person {
public:
    Student(string n) :Person(n) {
        cout<<"cons S:"+name+"\n";  }
    ~Student() {
        cout<<"des S:"+name+"\n";   }};
class Teacher : public Person {
public:
    Teacher(string n) :Person(n) {
        cout<<"cons T:"+name+"\n";    }
    ~Teacher() {
        cout<<"des T:"+name+"\n";    }};
int main() {
    Person *p[2];
    p[0] = new Teacher("Jack");
    p[1] = new Student("Mike");
    for(int i=0; i<2; i++) delete p[i];
}

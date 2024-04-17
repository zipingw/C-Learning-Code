#include<iostream>
#include<iomanip>
#include<cstring>
#include<string.h>
#include <stdlib.h>
using namespace std;
class Date{
	int year;
	int month;
	int day;
 public:
	Date(int y=1900, int m=1, int d=1):year(y),month(m),day(d){};//���캯��1 
    Date(const string& s);  //���캯��2 
	void set( int y, int m, int d );  //��������
	bool isValid(Date &);// �ж������յ�ֵ�Ƿ񹹳�һ����Ч���ڣ�ͬʱ�ж��Ƿ������� 
	bool isLeapYear(); //�ж��Ƿ�����
	int toInt() ; //������ת����������YYYYMMDD��������201903015
	Date lastDay(); //���ص�ǰ�����ǰһ�������
	Date nextDay(); //���ص�ǰ����ĺ�һ�������
	void print(); //��ӡ���ڣ���ʽ�ο�:"yyyy/mm/dd"��"yyyy-mm-dd"
	int getYear(); //���ص�ǰ�����year��ֵ
	int getMonth(); //���ص�ǰ�����month��ֵ
	int getDay(); //���ص�ǰ�����day��ֵ
	void setYear(int y);// ��y��ֵ��ֵ����ǰ�����year
	void setMonth( int m);// ��m��ֵ��ֵ����ǰ�����month
	void setDay( int d); //��d��ֵ��ֵ����ǰ�����day
    friend int compare(const Date & d1,const Date & d2);
};
int compare(const Date & d1,const Date & d2){
	if(d1.year>d2.year){return 1;}
	else if(d1.year<d2.year){return -1;}
	else {
		if(d1.month>d2.month){return 1;}
		else if(d1.month<d2.month){return -1;}
		else{
			if(d1.day>d2.day){return 1;}
			else if(d1.day<d2.day){return -1;}
			else return 0;
		}
	}
}
Date::Date(const string &s){
	year = atoi(s.substr(0,4).c_str());
	month = atoi (s.substr(5,2).c_str());
	day = atoi (s.substr(8,2).c_str());
} 
void Date::set(int y,int m,int d){
	year=y;
	month=m;
	day=d;
}
void Date::setYear(int y){
	year=y;
}
void Date::setMonth(int m){
	month =m;
}
void Date::setDay(int d){
	day=d;
}
int Date::getYear(){
	return year;
}
int Date::getMonth(){
	return month;
}
int Date::getDay(){
	return day;
}
int Date::toInt(){
	return (year*10000+month*100+day);
}
void Date::print(){
	cout<<year<<"/"<<month<<"/"<<day<<endl;
}
Date Date::lastDay(){
	if(day-1==0){
		if(month-1==0){
			year=year-1;
			month=12;
			day=31;
		}
		else{
		month-=1;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
			day=31;
		}
		else day=30;
		}
	}
	else{
		day-=1;
	}
}
Date Date::nextDay(){
	if(month==12){
		if(day==31){
			year+=1;month=1;day=1;
		}
		else{
			day+=1;
		}
	}
    else if(month==1||month==3||month==5||month==7||month==8||month==10){
    	if(day==31){
    		day=1;month+=1;
		}
		else day+=1;
	}
	else {
		if(day==30){
			day=1;month+=1;
		}
		else{
			day+=1;
		}
	}
}
bool Date::isLeapYear(){
    if(year%4==0&&year%100!=0||year%400==0){
        cout<<"is LeapYear"<<endl;
		return 1;
	}
	else {
	    cout<<"is not LeapYear"<<endl;
		return 0;
	}
	return 0;
}
bool Date::isValid(Date  &D2){
	if(month<0||month>13){
		cout<<"is not Valid"<<endl;
		return 0;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
	  if(day<0||day>31){
	  	cout<<"is not Valid"<<endl;return 0;
		}
	  else {
	  	cout<<"is Valid"<<endl;return 0;
	  } 	
	}
	else if(month==2){
	if(D2.isLeapYear()){
		if(day<0||day>29){
			cout<<"is not Valid"<<endl;
			return 0;
		}
		else{
			cout<<"is Valid"<<endl;
			return 0;
		}
	}
	else {
		if(day<0||day>28){
			cout<<"is not Valid"<<endl;
		    return 0;
		}
		else{
			cout<<"is Valid"<<endl;
			return 0;
		}
	}
	}
	else{
		if(day<0||day>30){
			cout<<"is not Valid"<<endl;
			return 0;
		}
		else{
			cout<<"is Valid"<<endl;
			return 0;
		}
	}
	return 0;
}
int main(){
	Date D1;
	D1.print();
    cout<<D1.getYear()<<" ";
	cout<<D1.getMonth()<<" ";
	cout<<D1.getDay()<<" ";
	cout<<endl;
	D1.set(2020,3,17);
	D1.print();
	D1.setYear(2000);
	D1.setMonth(12);
	D1.setDay(12);
	D1.print();
	cout<<D1.toInt()<<endl;	
	D1.isLeapYear();
	D1.nextDay();
	D1.print();
	D1.lastDay();
	D1.print();
	D1.set(2016,3,17);
	D1.isLeapYear();
	D1.set(2099,2,29);
	D1.isValid(D1);
	Date D2("2019-02-6");
	Date D3(D2);
	cout<<compare(D1,D2)<<endl;
	cout<<compare(D2,D1)<<endl;
	cout<<compare(D3,D2)<<endl; 
    return 0;	
} 

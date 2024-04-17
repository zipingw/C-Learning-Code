#include"CVector.h"
using namespace std;
#include<iostream>
#include<algorithm>
CVector::CVector() {								//构造函数
    size = 0;				
	capacity =4;									//初始为4，不可为0
    v = new int[capacity];							//动态分配空间
}
CVector::CVector(const CVector& vc) {				//拷贝构造函数
	size = vc.size;									//复制size
	capacity = vc.capacity;							//复制容量
	v = vc.v;										//复制指针首地址
	v = new int[capacity];							//动态分配数组
	for (int i = 0; i < size; i++) {
		v[i] = vc.v[i];								//复制数组数据
	}
}
CVector::~CVector() {								//析构函数
	delete[]v;										
	v = 0;											//v=0使得重复析构时 避免内存越界
}
void CVector::reserve() {							//动态扩容
	capacity *= 2;									//capacity不够时乘2
	int* newv = new int[capacity];					//新开辟一片空间，容量更大
	for (int i = 0; i < capacity-1; i++) {			//把旧的向量存放到新的更大的空间
		newv[i] = v[i];
	}
	delete[]v;										//释放原空间
	v = newv;										//将新空间首地址存到向量首地址中
}
int CVector::Insert(int a) {						//向量末尾添加一个数据，值为a
	if (++size >= capacity) {						//若size大于capacity，则增大动态分配的空间
		reserve();									
	}										
	v[size - 1] = a;								//向量中加入数据
	return 1;
}
void CVector::Erase(int a) {
	for (int i = a; i < size; i++) {				//从第a+1个数开始往前移一个
		v[i - 1] = v[i];
	}
	size --;										//调整size大小
}
void CVector::sort(bool cmp) {						//选择排序
	if (cmp) {										//cmp=true ,从小到大排序
		for (int i = 0; i < size - 1; i++) {
			int min = v[i]; int m = i;
				for (int j = i + 1; j < size; j++) {
					if (v[j] < min)
					{
						min = v[j]; m = j;
					}
				}
			swap(v[m], v[i]);
		}
	}
	if (!cmp) {										//cmp=false ，从大到小排序
		for (int i = 0; i < size - 1; i++) {
			int max = v[i]; int m = i;
			for (int j = i + 1; j < size; j++) {
				if (v[j] > max) 
				{ 
					max = v[j]; m = j; 
				}
			}
			swap(v[m], v[i]);
		}
	}
}
void CVector::MergeVector(CVector& vv) {			//合并向量	
	while (size + vv.size > capacity) {				//若两向量size值之和大于capacity
		reserve();}									//动态扩容
	for (int i = 0; i < vv.size; i++) {				//合并
		v[size + i] = vv.v[i];
	}
	size += vv.size;								//改变size
}
void CVector::output() {							//遍历输出
	for (int i = 0; i < size; i++) {
		cout << v[i]<<" ";
	}
	cout << endl;									
}
int& CVector::operator[](int pos) {					//运算符重载
	return v[pos];
}
CVector MergeSort(CVector& v1, CVector& v2) {		//合并两个向量，并排序，作为参数的向量无论是否有序皆可
	CVector v3;										//v3作为新向量
	v1.sort(true);									//v1进行正向排序
	v2.sort(true);									//v2进行正向排序
	for (int i = 0; i < v1.size; i++) {				//复制v1中的动态数组数据到v3中
		v3.Insert(v1.v[i]);
	}
	for (int i = 0; i < v2.size; i++) {				//复制v2中的动态数组数据到v3中
		v3.Insert(v2.v[i]);
	}
	v3.sort(true);									//v3正向排序
	return v3;										//返回v3
}

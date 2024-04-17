#pragma once
class CVector {
	int size;								//当前已存数据的个数
	int capacity;							//当前向量的容量
	int* v;									//动态分配出的空间的首地址
	void reserve();							//
public:
	CVector();								//构造函数
	CVector(const CVector& vc);				//拷贝构造函数
	~CVector();								//析构函数	
	int Insert(int a);						//在向量末尾插入一个值 值为a
	void Erase(int a);						//去掉向量中第a个值
	void sort(bool cmp);					//排序，cmp决定其正序还是倒序
	void MergeVector(CVector&vv );			//合并向量vv到此向量
	void output();							//遍历输出向量
	int& operator[](int pos);				//重载 []
	friend CVector MergeSort(CVector& v1, CVector& v2);		//合并排序
};
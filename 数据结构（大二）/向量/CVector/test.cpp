#include"CVector.h"
#include<iostream>
using namespace std;
int main() {
	CVector v1;
	CVector v2;
	v1.Insert(2);				
	v1.Insert(1);
	v1.Insert(3);
	v1.output();							//v1:2 1 3
	v1.sort(true);							//从小到大排序
	v1.output();							//输出检验排序功能
	v2.Insert(4);
	v2.Insert(7);
	v2.Insert(5);
	v2.Insert(6);
	v2.output();							//v2:4 7 5 6
	v2.sort(false);							//从大到小排序
	v2.output();							//输出检验排序功能
	v1.MergeVector(v2);						//合并v2到v1 v1:1 2 3 7 6 5 4
	v1.output();							//输出检验
	v1.Erase(7);							//删除第7个数据 v1:1 2 3 7 6 5
	v1.output();
	CVector v3(v1);							//验证拷贝构造函数
	v3.output();
	CVector v4 = MergeSort(v1, v3);			//v4:1 1 2 2 3 3 5 5 6 6 7 7 
	v4.output();
	CVector v5 = MergeSort(v1, v2);			//v5:1 2 3 4 5 5 6 6 7 7 
	v5.output();
}
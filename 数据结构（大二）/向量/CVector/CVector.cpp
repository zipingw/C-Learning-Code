#include"CVector.h"
using namespace std;
#include<iostream>
#include<algorithm>
CVector::CVector() {								//���캯��
    size = 0;				
	capacity =4;									//��ʼΪ4������Ϊ0
    v = new int[capacity];							//��̬����ռ�
}
CVector::CVector(const CVector& vc) {				//�������캯��
	size = vc.size;									//����size
	capacity = vc.capacity;							//��������
	v = vc.v;										//����ָ���׵�ַ
	v = new int[capacity];							//��̬��������
	for (int i = 0; i < size; i++) {
		v[i] = vc.v[i];								//������������
	}
}
CVector::~CVector() {								//��������
	delete[]v;										
	v = 0;											//v=0ʹ���ظ�����ʱ �����ڴ�Խ��
}
void CVector::reserve() {							//��̬����
	capacity *= 2;									//capacity����ʱ��2
	int* newv = new int[capacity];					//�¿���һƬ�ռ䣬��������
	for (int i = 0; i < capacity-1; i++) {			//�Ѿɵ�������ŵ��µĸ���Ŀռ�
		newv[i] = v[i];
	}
	delete[]v;										//�ͷ�ԭ�ռ�
	v = newv;										//���¿ռ��׵�ַ�浽�����׵�ַ��
}
int CVector::Insert(int a) {						//����ĩβ���һ�����ݣ�ֵΪa
	if (++size >= capacity) {						//��size����capacity��������̬����Ŀռ�
		reserve();									
	}										
	v[size - 1] = a;								//�����м�������
	return 1;
}
void CVector::Erase(int a) {
	for (int i = a; i < size; i++) {				//�ӵ�a+1������ʼ��ǰ��һ��
		v[i - 1] = v[i];
	}
	size --;										//����size��С
}
void CVector::sort(bool cmp) {						//ѡ������
	if (cmp) {										//cmp=true ,��С��������
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
	if (!cmp) {										//cmp=false ���Ӵ�С����
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
void CVector::MergeVector(CVector& vv) {			//�ϲ�����	
	while (size + vv.size > capacity) {				//��������sizeֵ֮�ʹ���capacity
		reserve();}									//��̬����
	for (int i = 0; i < vv.size; i++) {				//�ϲ�
		v[size + i] = vv.v[i];
	}
	size += vv.size;								//�ı�size
}
void CVector::output() {							//�������
	for (int i = 0; i < size; i++) {
		cout << v[i]<<" ";
	}
	cout << endl;									
}
int& CVector::operator[](int pos) {					//���������
	return v[pos];
}
CVector MergeSort(CVector& v1, CVector& v2) {		//�ϲ�������������������Ϊ���������������Ƿ�����Կ�
	CVector v3;										//v3��Ϊ������
	v1.sort(true);									//v1������������
	v2.sort(true);									//v2������������
	for (int i = 0; i < v1.size; i++) {				//����v1�еĶ�̬�������ݵ�v3��
		v3.Insert(v1.v[i]);
	}
	for (int i = 0; i < v2.size; i++) {				//����v2�еĶ�̬�������ݵ�v3��
		v3.Insert(v2.v[i]);
	}
	v3.sort(true);									//v3��������
	return v3;										//����v3
}

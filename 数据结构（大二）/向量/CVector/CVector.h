#pragma once
class CVector {
	int size;								//��ǰ�Ѵ����ݵĸ���
	int capacity;							//��ǰ����������
	int* v;									//��̬������Ŀռ���׵�ַ
	void reserve();							//
public:
	CVector();								//���캯��
	CVector(const CVector& vc);				//�������캯��
	~CVector();								//��������	
	int Insert(int a);						//������ĩβ����һ��ֵ ֵΪa
	void Erase(int a);						//ȥ�������е�a��ֵ
	void sort(bool cmp);					//����cmp�����������ǵ���
	void MergeVector(CVector&vv );			//�ϲ�����vv��������
	void output();							//�����������
	int& operator[](int pos);				//���� []
	friend CVector MergeSort(CVector& v1, CVector& v2);		//�ϲ�����
};
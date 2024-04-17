#include<iostream>
#include<vector>
using namespace std;
bool Bubble(vector<int>& vec) {
	int TTL = 0;											//ѭ������
	for (int i = 0; i < vec.size()-1;i++) {					//˫ѭ����������
		for (int j = i + 1; j < vec.size(); j++) {			
			if (vec[i] > vec[j])swap(vec[i], vec[j]);		//��һ����ǰһ���󣬽���
			TTL++;											//ѭ��������1
		}
	}
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "������������������" << endl;
	}
	else {
		cout << "ð������ѭ���ܴ���Ϊ:" << TTL << endl;
	}
	return 0;
}
bool InsertSort(vector<int>& vec) {							//��������
	int TTL = 0;											//ѭ������
	for (int i = 1; i < vec.size(); i++) {					//��ѭ����vec.size()-1��
		for (int j = i - 1; j >= 0 && vec[j + 1] < vec[j]; j--) {
			//��ѭ��j��i-1��0,ѭ����������vec[j + 1] < vec[j]�ɼ���ѭ������
			swap(vec[j + 1], vec[j]);						//����ѭ������ʱ����
															//��ʹ��i+1�������뵽ǰi������Ӧ�÷��õ�λ��
			TTL++;											//ѭ��������1
		}
	}
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "������������������" << endl;
	}
	else {
		cout << "��������ѭ���ܴ���Ϊ:" << TTL << endl;
	}
	return 0;
}
bool ShellSort(vector<int>& vec) {							//ϣ������
	int TTL=0;												//ѭ������
	for (int gap = vec.size() / 2; gap > 0; gap /= 2) {		//����Ϊ����С���䣬gap�������ȣ���2�ݼ�
		for (int i = gap; i < vec.size(); i++) {			//������Ƚ����ݣ���gapΪ���
			int j = i;
			while (j - gap >= 0 && vec[j - gap] > vec[j]) {
				swap(vec[j], vec[j - gap]);
				j = j - gap;								//�������Ϊgap������
				TTL++;										//ѭ��������1
			}
		}
	}
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "������������������" << endl;
	}
	else {
		cout << "ϣ������ѭ���ܴ���Ϊ:" << TTL << endl;
	}
	return 0;
}
int Q_Aux1(vector<int>& vec, int i, int j,int&TTL) {		//��������������1
	int key = vec[i];										//keyֵ��Ϊ��׼ֵ���ָ�����
	while (i != j) {										//iΪ�½磬jΪ�Ͻ�
															//ѭ����ֹ������i==j
		for (; j > i; j--) {								//�Ӻ���ǰ�ҵ���һ����KEYֵС����
			if (vec[j] < key) {							
				vec[i] = vec[j];							//���ҵ����������±�Ϊi��λ��
				i++;										//iλ�������룬������һ��
				break;										//�ҵ���Ӧ��ֵ ��ǰ�˳�ѭ��
			}
			TTL++;												//ѭ��������1
		}
		for (; i < j; i++) {								//��ǰ�����ҵ���һ����KEYֵ�����
			if (vec[i] > key) {								
				vec[j] = vec[i];							//���ҵ����������±�Ϊj��λ��
				j--;										//jλ�������룬��ǰ��һ��
				break;										//�ҵ���Ӧ��ֵ ��ǰ�˳�ѭ��
			}
			TTL++;												//ѭ��������1
		}
		
	}
	vec[i] = key;											//����ѭ��ʱ��i==j��keyֵ����vec[i]λ��
	return i;												//���طֽ��λ��i��
															//�±�i֮ǰ��������vec[i]С��С��i֮���������vec[i]��
}
void Q_Aux0(vector<int>& vec, int low, int high,int&TTL) {	//��������������0
	if (low < high) {										//���½�С���Ͻ�ʱִ�У����½粻С���Ͻ磬�������
		int s = Q_Aux1(vec, low, high,TTL);					//����Q_Aux1����һ�����򣬽��ֽ�ֵ�±귵��
		Q_Aux0(vec, low, s - 1,TTL);						//�ݹ飺���±��ǰ�벿�ֵ���Q_Aux0���������ɽ�ǰ�벿��ȫ������
		Q_Aux0(vec, s + 1, high,TTL);						//�ݹ飺����벿��ȫ������
	}
}
bool QuickSort(vector<int>& vec) {							//��������
	//��������ʹ�õݹ��㷨��low��high��Ϊ�ݹ麯�����Ͻ���½�
	int low = 0;											//low��ֵΪ0����Ӧvec[0]
	int high = vec.size() - 1;								//high��ֵΪvec.size()-1����Ӧ�������һ��Ԫ��
	int TTL = 0;											//TTL��¼ѭ������
	Q_Aux0(vec,low,high,TTL);								//���븨������Q_Aux0�����ø����ݹ麯��Q_Aux1
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "������������������" << endl;
	}
	else {
		cout << "��������ѭ���ܴ���Ϊ:" << TTL << endl;
	}
	return 0;
}
int main() {
	vector<int> v1;								//v1:10 9 8 7 6 5 4 3 2 1
	v1.push_back(10);
	v1.push_back(9);
	v1.push_back(8);
	v1.push_back(7);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	vector<int>v2 = v1;							//v2:10 9 8 7 6 5 4 3 2 1
	vector<int>v3 = v1;							//v3:10 9 8 7 6 5 4 3 2 1
	vector<int>v4 = v1;							//v4:10 9 8 7 6 5 4 3 2 1
	cout << "��ȫ�������������" << endl;
	cout << endl;
	Bubble(v1);									//����ȫ��������ݽ�������			
	InsertSort(v2);								
	ShellSort(v3);
	QuickSort(v4);
	cout << "��ȫ�������������" << endl;
	cout << endl;
	Bubble(v1);									//����ȫ��������ݽ�������			
	InsertSort(v2);
	ShellSort(v3);
	QuickSort(v4);
	vector<int>v5;								//v5:10000�������
	for (int i = 0; i < 10000; i++) {
		v5.push_back(rand());
	}
	vector<int>v6 = v5;
	vector<int>v7 = v5;
	vector<int>v8 = v5;
	cout << "10000�������������" << endl;
	cout << endl;
	Bubble(v5);									//��10000���������������
	InsertSort(v6);
	ShellSort(v7);
	QuickSort(v8);
}
#include<iostream>
#include<vector>
using namespace std;
void pushheap(vector<char>& v, char inValue) {  //���Ѳ��뺯��
	v.push_back(inValue);						//Ҫ����ѵ�Ԫ���ȷ�������ĩβ
	int last = v.size();						//last�洢��ǰ����Ԫ������
	int currentPos = last - 1;					//currentPosΪ��ǰ����v��ĩβԪ���±�,
												//currentPos�������ѭ������ʱ Ϊ��Ԫ��Ӧ����ŵ�λ���±�
	int parentPos = (currentPos - 1) / 2;		//parentPosΪ��ǰcurrentPos�Ķ����еĸ��ڵ��±�
	while (currentPos != 0) {					//ѭ����ֹ����:�ߵ��Ѷ�
		if (inValue > v[parentPos]) {			//��Ԫ�ش��ڸ��ڵ�Ԫ��
			v[currentPos] = v[parentPos];		//��ǰ�±�λ��Ԫ�ظ���Ϊ��ǰ���ڵ�λ��Ԫ��ֵ
			currentPos = parentPos;				//currentPos����Ϊ��ǰ���ڵ�λ���±�
			parentPos = (currentPos - 1) / 2;	//���¼���currentPos�ĸ��ڵ�λ��
		}
		else {									//��Ԫ�ز����ڸ��ڵ�Ԫ��
												//���Ѿ��ҵ���Ԫ�ظ÷ŷ��õ�λ���±꣬��currentPos
			break;								//�˳�ѭ��
		}
	}
	v[currentPos] = inValue;					//����Ԫ�ط�������ѭ���ҵ��ĸ÷��õ�λ�ã���currentPos
}
void adjustheap(vector<char>& v) {
	int last = v.size();						//last�洢��ǰ����Ԫ������
	int currentPos = 0;							//Ҫ�����Ķ���Ԫ�� ��ʼλ��ΪcurrentPos
	int childPos1 = 2 * currentPos + 1;			//childPos1 ΪcurrentPos�ڶ��νṹ�е�����λ���±�
	int childPos2 = 2 * currentPos + 2;			//childPos2	ΪcurrentPos�ڶ��νṹ�е��Һ���λ���±�
	char target = v[currentPos];				//��Ҫ�µ���Ԫ��ֵ ���� target��
	v.pop_back();								//ɾ������ĩβԪ�أ�����ǰ�������ֵ
	while (currentPos < last - 2 && childPos1 < last - 2 && childPos2 < last - 2) {
		//ѭ����ֹ��������ǰλ�ó��������±귶Χ �� ��λ�ó���
		if (target < v[childPos1]) {			//targetС������Ԫ��ֵ
			v[currentPos] = v[childPos1];		//��ǰ����λ���滻Ϊ ����Ԫ��ֵ
			currentPos = childPos1;				//currentPos����Ϊ����λ���±�
			childPos1 = 2 * currentPos + 1;		//���¼������Һ���
			childPos2 = 2 * currentPos + 2;
		}
		else if (target < v[childPos2]) {		//��target��С������Ԫ��ֵ��С���к���Ԫ��ֵ
												//�µ�����ͬ��
			v[currentPos] = v[childPos2];		
			currentPos = childPos2;
			childPos1 = 2 * currentPos + 1;
			childPos2 = 2 * currentPos + 2;
		}
		else {
			break;								//target��С����������Ԫ��ֵ���˳�ѭ��
		}
	}
	v[currentPos] = target;						//target�����ҵ����µ���ϵĸ÷��õ�λ��
}
void popheap(vector<char>& v) {				//ɾ�����ѶѶ�
	int last = v.size();					//last�洢��ǰ����Ԫ����
	swap(v[0], v[last - 1]);				//�����Ѷ�Ԫ�غͶ�βԪ��
	adjustheap(v);							//����adjust()������v��Ϊ����
											//adjust()�������������������׵�Ԫ���µ�
}
int main() {
	vector<char> v;
	//ע�Ͳ������� �����ַ� ����
	/*for (int i = 0; i < 5; i++) {
		char inValue;
		cin >> inValue;
		pushheap(v, inValue);

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}*/		
	pushheap(v, 'a');
	pushheap(v, 'b');
	pushheap(v, 'c');
	pushheap(v, 'd');
	pushheap(v, 'e');
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	popheap(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
#include<iostream>
#include<vector>
using namespace std;
bool Bubble(vector<int>& vec) {
	int TTL = 0;											//循环次数
	for (int i = 0; i < vec.size()-1;i++) {					//双循环升序排序
		for (int j = i + 1; j < vec.size(); j++) {			
			if (vec[i] > vec[j])swap(vec[i], vec[j]);		//后一个比前一个大，交换
			TTL++;											//循环次数加1
		}
	}
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "数据已有序，无需排序" << endl;
	}
	else {
		cout << "冒泡排序循环总次数为:" << TTL << endl;
	}
	return 0;
}
bool InsertSort(vector<int>& vec) {							//插入排序
	int TTL = 0;											//循环次数
	for (int i = 1; i < vec.size(); i++) {					//外循环共vec.size()-1次
		for (int j = i - 1; j >= 0 && vec[j + 1] < vec[j]; j--) {
			//内循环j从i-1到0,循环条件加上vec[j + 1] < vec[j]可减少循环次数
			swap(vec[j + 1], vec[j]);						//满足循环条件时交换
															//即使第i+1个数插入到前i个数中应该放置的位置
			TTL++;											//循环次数加1
		}
	}
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "数据已有序，无需排序" << endl;
	}
	else {
		cout << "插入排序循环总次数为:" << TTL << endl;
	}
	return 0;
}
bool ShellSort(vector<int>& vec) {							//希尔排序
	int TTL=0;												//循环次数
	for (int gap = vec.size() / 2; gap > 0; gap /= 2) {		//划分为几个小区间，gap即区间宽度，除2递减
		for (int i = gap; i < vec.size(); i++) {			//跨区间比较数据，以gap为间隔
			int j = i;
			while (j - gap >= 0 && vec[j - gap] > vec[j]) {
				swap(vec[j], vec[j - gap]);
				j = j - gap;								//遍历间隔为gap的数据
				TTL++;										//循环次数加1
			}
		}
	}
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "数据已有序，无需排序" << endl;
	}
	else {
		cout << "希尔排序循环总次数为:" << TTL << endl;
	}
	return 0;
}
int Q_Aux1(vector<int>& vec, int i, int j,int&TTL) {		//快速排序辅助函数1
	int key = vec[i];										//key值作为标准值，分割数据
	while (i != j) {										//i为下界，j为上届
															//循环终止条件：i==j
		for (; j > i; j--) {								//从后往前找到第一个比KEY值小的数
			if (vec[j] < key) {							
				vec[i] = vec[j];							//将找到的数放入下标为i的位置
				i++;										//i位置已填入，往后走一步
				break;										//找到相应的值 提前退出循环
			}
			TTL++;												//循环次数加1
		}
		for (; i < j; i++) {								//从前往后找到第一个比KEY值大的数
			if (vec[i] > key) {								
				vec[j] = vec[i];							//将找到的数放入下标为j的位置
				j--;										//j位置已填入，往前走一步
				break;										//找到相应的值 提前退出循环
			}
			TTL++;												//循环次数加1
		}
		
	}
	vec[i] = key;											//结束循环时，i==j，key值填入vec[i]位置
	return i;												//返回分界点位置i，
															//下标i之前的数都比vec[i]小，小标i之后的数都比vec[i]大
}
void Q_Aux0(vector<int>& vec, int low, int high,int&TTL) {	//快速排序辅助函数0
	if (low < high) {										//当下界小于上界时执行，若下界不小于上界，排序结束
		int s = Q_Aux1(vec, low, high,TTL);					//调用Q_Aux1进行一次排序，将分界值下标返回
		Q_Aux0(vec, low, s - 1,TTL);						//递归：对下标的前半部分调用Q_Aux0函数，即可将前半部分全部排序
		Q_Aux0(vec, s + 1, high,TTL);						//递归：将后半部分全部排序
	}
}
bool QuickSort(vector<int>& vec) {							//快速排序
	//快速排序使用递归算法，low，high作为递归函数的上届和下界
	int low = 0;											//low初值为0，对应vec[0]
	int high = vec.size() - 1;								//high初值为vec.size()-1，对应向量最后一个元素
	int TTL = 0;											//TTL记录循环次数
	Q_Aux0(vec,low,high,TTL);								//进入辅助函数Q_Aux0，调用辅助递归函数Q_Aux1
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;*/
	if (TTL == 0) {
		cout << "数据已有序，无需排序" << endl;
	}
	else {
		cout << "快速排序循环总次数为:" << TTL << endl;
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
	cout << "完全倒序的数据排序" << endl;
	cout << endl;
	Bubble(v1);									//对完全倒序的数据进行排序			
	InsertSort(v2);								
	ShellSort(v3);
	QuickSort(v4);
	cout << "完全正序的数据排序" << endl;
	cout << endl;
	Bubble(v1);									//对完全正序的数据进行排序			
	InsertSort(v2);
	ShellSort(v3);
	QuickSort(v4);
	vector<int>v5;								//v5:10000个随机数
	for (int i = 0; i < 10000; i++) {
		v5.push_back(rand());
	}
	vector<int>v6 = v5;
	vector<int>v7 = v5;
	vector<int>v8 = v5;
	cout << "10000个随机数据排序" << endl;
	cout << endl;
	Bubble(v5);									//对10000个随机数进行排序
	InsertSort(v6);
	ShellSort(v7);
	QuickSort(v8);
}
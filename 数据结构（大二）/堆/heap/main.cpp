#include<iostream>
#include<vector>
using namespace std;
void pushheap(vector<char>& v, char inValue) {  //最大堆插入函数
	v.push_back(inValue);						//要插入堆的元素先放入向量末尾
	int last = v.size();						//last存储当前向量元素数量
	int currentPos = last - 1;					//currentPos为当前向量v中末尾元素下标,
												//currentPos在下面的循环结束时 为新元素应当存放的位置下标
	int parentPos = (currentPos - 1) / 2;		//parentPos为当前currentPos的堆形中的父节点下标
	while (currentPos != 0) {					//循环终止条件:走到堆顶
		if (inValue > v[parentPos]) {			//新元素大于父节点元素
			v[currentPos] = v[parentPos];		//当前下标位置元素更改为当前父节点位置元素值
			currentPos = parentPos;				//currentPos更改为当前父节点位置下标
			parentPos = (currentPos - 1) / 2;	//重新计算currentPos的父节点位置
		}
		else {									//新元素不大于父节点元素
												//即已经找到新元素该放放置的位置下标，即currentPos
			break;								//退出循环
		}
	}
	v[currentPos] = inValue;					//将新元素放入上述循环找到的该放置的位置，即currentPos
}
void adjustheap(vector<char>& v) {
	int last = v.size();						//last存储当前向量元素数量
	int currentPos = 0;							//要调整的堆首元素 初始位置为currentPos
	int childPos1 = 2 * currentPos + 1;			//childPos1 为currentPos在堆形结构中的左孩子位置下标
	int childPos2 = 2 * currentPos + 2;			//childPos2	为currentPos在堆形结构中的右孩子位置下标
	char target = v[currentPos];				//将要下调的元素值 存在 target中
	v.pop_back();								//删除向量末尾元素，即当前堆中最大值
	while (currentPos < last - 2 && childPos1 < last - 2 && childPos2 < last - 2) {
		//循环终止条件：当前位置超出向量下标范围 或 子位置超出
		if (target < v[childPos1]) {			//target小于左孩子元素值
			v[currentPos] = v[childPos1];		//当前向量位置替换为 左孩子元素值
			currentPos = childPos1;				//currentPos调整为左孩子位置下标
			childPos1 = 2 * currentPos + 1;		//重新计算左右孩子
			childPos2 = 2 * currentPos + 2;
		}
		else if (target < v[childPos2]) {		//当target不小于左孩子元素值，小于有孩子元素值
												//下调过程同上
			v[currentPos] = v[childPos2];		
			currentPos = childPos2;
			childPos1 = 2 * currentPos + 1;
			childPos2 = 2 * currentPos + 2;
		}
		else {
			break;								//target不小于两个孩子元素值，退出循环
		}
	}
	v[currentPos] = target;						//target放入找到的下调完毕的该放置的位置
}
void popheap(vector<char>& v) {				//删除最大堆堆顶
	int last = v.size();					//last存储当前向量元素数
	swap(v[0], v[last - 1]);				//交换堆顶元素和堆尾元素
	adjustheap(v);							//调用adjust()函数，v作为参数
											//adjust()函数用来将交换到堆首的元素下调
}
int main() {
	vector<char> v;
	//注释部分用来 输入字符 建堆
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
#include<iostream>
#include<stack>
#include"Elem.h"
#include"Direction.h"
using namespace std;

bool PathList(int **maze, stack<Elem>& s,Direction D[], Elem& beginPos, Elem& endPosElem) {		//PathList函数实现找到迷宫中的路存储到栈sList中
	
	Elem pos;														//pos记录当前位置的横纵坐标及前进方向
	int x, y, di;													//x,y,di为临时存储值（空的容器）
	int row, col;													//row,col记录
	maze[1][1] = -1;												//maze[1][1]迷宫起始点，先赋值-1
	pos.x = 1; pos.y = 1; pos.di = -1;								//当前位置pos(1,1，-1)
	s.push(pos);													//起点入栈 ，适应循环体中 第19行 的出栈操作 
	while (!s.empty()) {											//s非空
		pos.x = s.top().x;											//栈顶位置赋给pos
		pos.y = s.top().y;
		pos.di = s.top().di;
		s.pop();													/*
																	划重点！！！实现遇到死路时位置回溯
																	先将当前位置pos出栈 , 若pos的下一个前进的位置可走，则再将pos入栈
																	*/
		x = pos.x; y = pos.y; di = pos.di + 1;						//x,y存下当前位置的横纵坐标，di赋值0（先以向右试探方向）
		while (di < 4 ) {											//循环终止条件：在当前位置pos基础上试探四个方向都走不通	
			row = x + D[di].incX;									//row  试探方向位置的横坐标
			col = y + D[di].incY;									//col  试探方向位置的纵坐标
			if (maze[row][col] == 0) {								//若试探方向可走
				pos.x = x; pos.y = y; pos.di = di;					//循环前存入（x,y)的pos位置以及当前可通方向di存入pos
				s.push(pos);										//当前位置及对应的前进方向入栈
				x = row; y = col;									//横纵坐标存入（x,y)
				maze[row][col] = -1;								//即将到达的位置 在maze数组中的值赋值为-1
				if (row == endPosElem.x && col ==endPosElem.y )		//若即将到达的位置为终点
				{	
					pos.x = row; pos.y = col; pos.di = di;			//终点坐标存入pos
					s.push(pos);									//pos入栈
					return true;									//结束函数
				}
				else { di = 0; }									/*
																	即将到达的位置不为终点 di置0 进入下一次循环 
																	到达下一个位置 继续试探路线
																	*/
			}
			else {													//试探方向不可走
				row -= D[di].incX;									//row 和 col 回溯到原来坐标值
				col -= D[di].incY;
				di++;												//di++ 试探下一个方向
			}
				
		}
	}
	return false;													//若循环体结束为返回true，则当前迷宫无出路
}
int main() {
	cout << "请输入迷宫的规模" << endl;											
	int x = 0; int y = 0;
	cin >> x >> y;																//迷宫的长和宽
	int** maze = new int* [x];													//双重指针动态分配二维数组，分配第一维
	for (int i = 0; i < x; i++) {														
		 maze[i] = new int[y];													//分配第二维
	}
	cout << "请输入" << x << "×" << y << "的迷宫" << endl;
	for (int i = 0; i < x; i++) {												//循环输入二维数组，即迷宫
		for (int j = 0; j < y; j++) {	
			cin >> maze[i][j];													
		}
	}
	/*				    用于测试的迷宫
						1, 1, 1, 1, 1, 1, 1, 1,									
						1, 0, 0, 0, 1, 1, 0, 1,
						1, 0, 0, 1, 0, 0, 0, 1,
						1, 0, 1, 0, 0, 1, 0, 1,
						1, 0, 0, 0, 1, 0, 0, 1,
						1, 0, 1, 1, 0, 0, 1, 1,
						1, 1, 0, 0, 1, 0, 0, 1,
						1, 1, 1, 1, 1, 1, 1, 1
	*/
	stack<Elem> sList;																	//stack模板类Elem
	Direction D[4] = { {0,1},{1,0},{0,-1},{-1,0} };										//Direction类型的数组D 表示四个前进方向
	Elem bp = { 1, 1, -1 };
	Elem ep = { x - 2,y - 2,-1 };														//迷宫终点（出口）位置
	if (PathList(maze, sList, D, bp, ep))												//调用函数 找到路线 栈sList存储路线
	{
		stack<Elem> output;																//栈output 倒序 栈sList
			while (!sList.empty()) {													//路线倒序
				output.push(sList.top());
				sList.pop();
			}
			cout << "走出该迷宫的路径如下：" << endl;
			while (!output.empty()) {													//输出路线
				cout << "(" << output.top().x << "," << output.top().y << ")" << endl;
				output.pop();
			}
	}
	else {
		cout << "此迷宫无出路" << endl;
	}
	return 0;
}  

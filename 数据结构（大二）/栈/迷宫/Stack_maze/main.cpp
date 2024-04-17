#include<iostream>
#include<stack>
#include"Elem.h"
#include"Direction.h"
using namespace std;

bool PathList(int **maze, stack<Elem>& s,Direction D[], Elem& beginPos, Elem& endPosElem) {		//PathList����ʵ���ҵ��Թ��е�·�洢��ջsList��
	
	Elem pos;														//pos��¼��ǰλ�õĺ������꼰ǰ������
	int x, y, di;													//x,y,diΪ��ʱ�洢ֵ���յ�������
	int row, col;													//row,col��¼
	maze[1][1] = -1;												//maze[1][1]�Թ���ʼ�㣬�ȸ�ֵ-1
	pos.x = 1; pos.y = 1; pos.di = -1;								//��ǰλ��pos(1,1��-1)
	s.push(pos);													//�����ջ ����Ӧѭ������ ��19�� �ĳ�ջ���� 
	while (!s.empty()) {											//s�ǿ�
		pos.x = s.top().x;											//ջ��λ�ø���pos
		pos.y = s.top().y;
		pos.di = s.top().di;
		s.pop();													/*
																	���ص㣡����ʵ��������·ʱλ�û���
																	�Ƚ���ǰλ��pos��ջ , ��pos����һ��ǰ����λ�ÿ��ߣ����ٽ�pos��ջ
																	*/
		x = pos.x; y = pos.y; di = pos.di + 1;						//x,y���µ�ǰλ�õĺ������꣬di��ֵ0������������̽����
		while (di < 4 ) {											//ѭ����ֹ�������ڵ�ǰλ��pos��������̽�ĸ������߲�ͨ	
			row = x + D[di].incX;									//row  ��̽����λ�õĺ�����
			col = y + D[di].incY;									//col  ��̽����λ�õ�������
			if (maze[row][col] == 0) {								//����̽�������
				pos.x = x; pos.y = y; pos.di = di;					//ѭ��ǰ���루x,y)��posλ���Լ���ǰ��ͨ����di����pos
				s.push(pos);										//��ǰλ�ü���Ӧ��ǰ��������ջ
				x = row; y = col;									//����������루x,y)
				maze[row][col] = -1;								//���������λ�� ��maze�����е�ֵ��ֵΪ-1
				if (row == endPosElem.x && col ==endPosElem.y )		//�����������λ��Ϊ�յ�
				{	
					pos.x = row; pos.y = col; pos.di = di;			//�յ��������pos
					s.push(pos);									//pos��ջ
					return true;									//��������
				}
				else { di = 0; }									/*
																	���������λ�ò�Ϊ�յ� di��0 ������һ��ѭ�� 
																	������һ��λ�� ������̽·��
																	*/
			}
			else {													//��̽���򲻿���
				row -= D[di].incX;									//row �� col ���ݵ�ԭ������ֵ
				col -= D[di].incY;
				di++;												//di++ ��̽��һ������
			}
				
		}
	}
	return false;													//��ѭ�������Ϊ����true����ǰ�Թ��޳�·
}
int main() {
	cout << "�������Թ��Ĺ�ģ" << endl;											
	int x = 0; int y = 0;
	cin >> x >> y;																//�Թ��ĳ��Ϳ�
	int** maze = new int* [x];													//˫��ָ�붯̬�����ά���飬�����һά
	for (int i = 0; i < x; i++) {														
		 maze[i] = new int[y];													//����ڶ�ά
	}
	cout << "������" << x << "��" << y << "���Թ�" << endl;
	for (int i = 0; i < x; i++) {												//ѭ�������ά���飬���Թ�
		for (int j = 0; j < y; j++) {	
			cin >> maze[i][j];													
		}
	}
	/*				    ���ڲ��Ե��Թ�
						1, 1, 1, 1, 1, 1, 1, 1,									
						1, 0, 0, 0, 1, 1, 0, 1,
						1, 0, 0, 1, 0, 0, 0, 1,
						1, 0, 1, 0, 0, 1, 0, 1,
						1, 0, 0, 0, 1, 0, 0, 1,
						1, 0, 1, 1, 0, 0, 1, 1,
						1, 1, 0, 0, 1, 0, 0, 1,
						1, 1, 1, 1, 1, 1, 1, 1
	*/
	stack<Elem> sList;																	//stackģ����Elem
	Direction D[4] = { {0,1},{1,0},{0,-1},{-1,0} };										//Direction���͵�����D ��ʾ�ĸ�ǰ������
	Elem bp = { 1, 1, -1 };
	Elem ep = { x - 2,y - 2,-1 };														//�Թ��յ㣨���ڣ�λ��
	if (PathList(maze, sList, D, bp, ep))												//���ú��� �ҵ�·�� ջsList�洢·��
	{
		stack<Elem> output;																//ջoutput ���� ջsList
			while (!sList.empty()) {													//·�ߵ���
				output.push(sList.top());
				sList.pop();
			}
			cout << "�߳����Թ���·�����£�" << endl;
			while (!output.empty()) {													//���·��
				cout << "(" << output.top().x << "," << output.top().y << ")" << endl;
				output.pop();
			}
	}
	else {
		cout << "���Թ��޳�·" << endl;
	}
	return 0;
}  

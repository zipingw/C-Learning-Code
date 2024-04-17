#include<iostream>
using namespace std;
//--------------------
class DNode{
  int an;
  DNode *next, *prev;
  DNode(int a):an(a),next(0),prev(0){}
  friend class DList;
};//------------------
class DList{  //˫��������
  DNode *first;
public:
  DList():first(0){}
 
  void add(int x){     // ����ֵΪx�Ľ��,��������
    DNode* p = new DNode(x);
    if(first)  //���ǿ���
      first->prev = p;
    p->next = first;
    first = p;
  }//-----------------
 
  void remove(int a){  //���ҵ��ý��,���Ƴ�,�Ҳ���������
    DNode* p=find(a);
    if(!p) return;
    if(p->next)  //pָ��Ľ�����β
      p->next->prev = p->prev;
    if(p->prev)  //pָ��Ľ�������
      p->prev->next = p->next;
    else         //pָ������
      first = p->next;
    delete p;
  }//-----------------
 
 DNode* find(int a)const{  //���Ҳ���,���ؿ�ָ��
    for(DNode* p=first; p; p=p->next)
      if(p->an==a)
        return p;
    return 0;
  }//-----------------
  void display()const{
    for(DNode* p=first; p; p=p->next)
      cout<<"*"<<p->an;
  }//-----------------
 ~DList(){
    for(DNode* p; p=first; delete p)
      first = first->next;
  }
};//------------------
int main(){
  DList list;
  for(int i=1; i<6; i++)
    list.add(i);
  for(int j=1; j<6; j++)
    list.remove(2*j);
  list.display();
}//-------------------

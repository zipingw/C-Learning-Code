#include<iostream>
using namespace std;
//--------------------
class DNode{
  int an;
  DNode *next, *prev;
  DNode(int a):an(a),next(0),prev(0){}
  friend class DList;
};//------------------
class DList{  //双向链表类
  DNode *first;
public:
  DList():first(0){}
 
  void add(int x){     // 创建值为x的结点,插入链首
    DNode* p = new DNode(x);
    if(first)  //若非空链
      first->prev = p;
    p->next = first;
    first = p;
  }//-----------------
 
  void remove(int a){  //若找到该结点,则移除,找不到则拉倒
    DNode* p=find(a);
    if(!p) return;
    if(p->next)  //p指向的结点非链尾
      p->next->prev = p->prev;
    if(p->prev)  //p指向的结点非链首
      p->prev->next = p->next;
    else         //p指向链首
      first = p->next;
    delete p;
  }//-----------------
 
 DNode* find(int a)const{  //若找不到,返回空指针
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

#include<iostream>
using namespace std;
struct Node{
	int data; //每个结点的data唯一 
	Node * next;
	Node(const int &d):data(d),next(0){}
};
class List{
    Node* head;
    Node* last;
    unsigned int listsize;
public:
	List():head(0),last(0),listsize(0){};
	List(int *arr, int n);
 	List(const List& a);
	unsigned size() const { return listsize;}
	int data(Node* post){return post->data;}
	Node *begin()const{return head;}
	bool empty()const{if(!listsize)return true;return false;}
	void push_front(const int &d);
	void push_back(const int &d);
	void insert(Node* post,const int &d);
	void pop_front();
	void pop_back();
	Node* find (const int &d)const;
	bool erase_first(const int &c);
	bool erase_all(const int &c);
	List& operator+=(const List&a);
	friend List operator +(const List&a,const List &b);
	void clear();
	void print ()const;
    ~List();
};
List::List(int *arr,int n){
	if(n==0){List();}
	else{
	Node* p;
	head = last = new Node(arr[0]);
	for(int i=1;i<n;i++){
		p=new Node(arr[i]);
		last->next=p;
		last=p;
	}
	listsize=n;
	}
}
List::List(const List&a){
   if(a.head==0){
   	List();
   	return ;
   }
   Node* p2=new Node((a.head)->data);
   last=head=p2;
   listsize=a.listsize;
   for(Node* p=(a.head)->next;p;p->next){
   	Node*p2=new Node(p->data);
   	last->next=p2;
   	last=p2;
   }
}
void List::push_front(const int &d){
	Node* p=new Node(d);
	p->next=head;
	head=p;
	if(!last)last=p;
	listsize++;
}
void List::push_back(const int &d){
	Node* p=new Node(d);
	//p->next=0;
	if(last)last->next=p;
	else head=p;
	last = p;
	listsize++;
} 
void List::insert(Node* post,const int &d){
	Node* p =new Node(d);
	p->next=post->next;
	post->next=p;
	if(post==last)last=p;
	listsize++;
}
void List::pop_front(){
	if(head){
		Node* p = head;
		head = head->next;
		listsize--;
		delete p;
	}
	if(!head) last =0;
}
void List::pop_back(){
	Node* p=head;
	if(last==0) return;
	if(head==last){
		head = last =0;
		listsize = 0;
		delete p;
		return ;
	}
	while(p->next!=last) p=p->next;
	last=p; p=p->next;
	last->next=0;
	listsize--;
	delete p;
	return ;
}
Node* List::find(const int &d)const{
	for(Node* p=head;p;p=p->next){
			if(p->data==d)return p;
		}
		return 0; 
} 
bool List::erase_first(const int &c){
	if(!head)return false;
	Node *q=head;
	if(head->data==c){
	head=head->next;
	listsize--;			
	delete q;		
	return true;
	}
    Node* p=q;q=q->next;//p是伴随指针，指向q的上一个节点 
    while(q!=0){
	 if(q->data==c){
	 	p->next=q->next;
	 	if(q==last)last=p;
	 	listsize--;
	 	delete q;
	 	return true; 
	 } 
	 else{
	 	p=q;q=q->next ;
	 }
	}
	return false; 
}
bool List::erase_all(const int &c){
	if(!head)return false;
	int s=listsize;
	Node *q=head;
	while(head->data==c){
		head=head->next;
		listsize--;
		delete q;
		q=head; 
	}
	Node *p=q;
	q=q->next;
	while(q){
		if(q->data==c){
			p->next=q->next;
			if(q=last)last=p;
			listsize--;
			delete q;
			q=p->next; 
		}
		else {
			p=q;
			q=q->next;
		}
	}
	if(listsize!=s)return true;
	return false;
}  
List& List::operator +=(const List &a){
	if(this == &a){
		List b=a;
		for(Node* p=b.head;p;p->next){
			push_back(p->data);
		}
		return *this;
	}
	for(Node *p= a.head;p;p->next){
		push_back(p->data);
	}
	return *this;
}
List operator +(const List &a,const List&b){
	List t=a;
	for(Node* p=b.head;p;p = p->next){
		t.push_back(p->data);
	}
	return t;
}
void List::clear(){
	(*this).~List();
	head=last=0;
	listsize=0; 
}
void List::print()const{
		for(Node* p=head;p!=last;p=p->next){
			cout<<p->data<<" ";
		}
		cout<<last->data<<endl;
}
List::~List(){
	for(Node* p=head;head!=0;p=head){
		head = head->next;
		delete p;
	}
}
int main(){
	return 0;
}

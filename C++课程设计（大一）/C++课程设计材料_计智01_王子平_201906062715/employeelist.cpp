#include"employeelist.h"
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;
employeelist::employeelist() {
	size = 0;
	head = 0;
	tail = 0;
}
void employeelist::add(employee& a) {
	employee* p = new employee(a);
	if (!head) {
		head = p;
	}
	else {
		tail->next = p;
	}
	tail = p;
	size++;

}
void employeelist::check_by_eNo(string No) {
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	employee* s = head;
	for (; s ; s = s->next) {
		if (s->geteNo() == No) {
			s->employeedisplay();
			break;
		}
		
	}
	if (!s) { cout << "系统中无该教职工信息" << endl; }
}
void employeelist::check_by_ename(string name) {
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	employee* s = head;
	for (;s ; s = s->next) {
		if (s->getename() == name) {
			s->employeedisplay();
			break;
		}
	}
	if (!s) { cout << "系统中无该教职工信息" << endl; }
}
void employeelist::check_by_Ins(string In) {
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	employee* s = head;
	int a = 0;
	for (; s; s = s->next) {
		if (s->getIns() == In) {
			s->employeedisplay();
			a = 1;
		}
		
	}
	if (!a) { cout << "系统中无该教职工信息" << endl; }
	else { cout << "查找结果如上" << endl; }
}
void employeelist::check_by_Dep(string De) {
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	employee* s = head;
	int a = 0;
	for (;s ; s = s->next) {
		if (s->getDep() == De) {
			s->employeedisplay();
			a = 1;
		}
	}
	if (!a) { cout << "系统中无该教职工信息" << endl; }
	else { cout << "查找结果如上" << endl; }
}
void employeelist::check_by_edu(string ed) {
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	employee* s = head;
	int a = 0;
	for (;s ; s = s->next) {
		if (s->getedu() == ed) {
			s->employeedisplay();
			a = 1;
		}
		
	}
	if (!a) { cout << "系统中无该教职工信息" << endl; }
	else { cout << "查找结果如上" << endl; }
}
void employeelist::check_by_tele(string tel) {
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	employee* s = head;
	int a = 0;
	for (;s ; s = s->next) {
		if (s->gettele() == tel) {
			s->employeedisplay();
			a = 1;
		}
		
	}
	if (!a) { cout << "系统中无该教职工信息" << endl; }
	else { cout << "查找结果如上" << endl; }
}
void employeelist::count_edu_by_Dep(string De) {
	employee* s = head;
	if (!head) { cout << "该系统中无任何教职工信息" << endl; }
	else {
		int undergraduate = 0;
		int graduate = 0;
		int Doctor = 0;
		int post_doctoral = 0;
		for (; s; s = s->next) {
			if (s->getDep() == De) {
				if (s->getedu() == "本科生") {
					undergraduate++;
				}
				else if (s->getedu() == "研究生") {
					graduate++;
				}
				else if (s->getedu() == "博士") {
					Doctor++;
				}
				else if (s->getedu() == "博士后") {
					post_doctoral++;
				}
			}
		}
		cout << "————————————————————" << endl;
		cout << De << "教职工学历统计结果为：" << endl;
		cout << "***本科生：" << setw(5) << undergraduate << "人" << endl;
		cout << "***研究生：" << setw(5) << graduate      << "人" << endl;
		cout << "***博士  ：" << setw(5) << Doctor        << "人" << endl;
		cout << "***博士后：" << setw(5) << post_doctoral << "人" << endl;
		cout << "————————————————————" << endl;
	}
}
void employeelist::sort_by_edu() {
	employee* p = head;
	employee* q = head->next;
	for (int i = 1; i < size; i++) {
        employee* p = head;
		employee* q = head->next;
		for (int j = 1; j < size - i + 1; j++) {
			if (p->getedu() > q->getedu()) {
				swap(p->ename, q->ename);
				swap(p->sex, q->sex);
				swap(p->Ins, q->Ins);
				swap(p->Dep, q->Dep);
				swap(p->edu, q->edu);
				swap(p->eNo, q->eNo);
				swap(p->tele, q->tele);
			}
			p = p->next; q = q->next;
		}
	}
    for (employee* s = head; s; s = s->next) {
		s->employeedisplay();
	}
}
void employeelist::remove_by_eNo(string No) {
	employee* p = head;
	employee* q = head;//伴随指针，当p指针指向第二个节点后始终指向p指针指向的节点的上一个节点
	int a = 0;//用于判断是否删除了教职工信息
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	else {
		if (p->geteNo() == No) {
			head = p->next;
			delete p;
			a = 1;
		}
		else {
			p = p->next;
			for (; p; p = p->next, q = q->next) {
			    if (p->geteNo() == No) {
					if (p == tail) { tail = q; delete p; a = 1; }
					else { q->next = p->next; delete p; a = 1; }
					break;
				}
		    }
		}
		if (!a) { cout << "系统中无该工号的教职工信息" << endl; }
		else { cout << "————该教职工信息已删除！————" << endl; }
	}
}
void employeelist::change_by_eNo(string No) {
	employee* p = head;
	employee* q = head;//伴随指针，当p指针指向第二个节点后始终指向p指针指向的节点的上一个节点
	int a = 0;//用于判断是否删除了教职工信息
	if (!head) {
		cout << "系统中无任何教职工信息" << endl;
	}
	else {
		if(p->geteNo()==No){
			cout << "请按下列顺序重新输入该教职工信息：" << endl;//直接将新信息覆盖该教职工原有信息
			cout << "姓名/性别/学院/系/学历/工号/电话：" << endl;
			a = 1;
			string a, b, c, d, e, f, g;
			cin >> a >> b >> c >> d >> e >> f >> g;
			employee e0(a, b, c, d, e, f, g);
			employee* s = new employee(e0);
			s->next = p->next;
			head = s;
			delete p;
			
		}
		else {
			p = p->next;
			for (; p; p = p->next, q = q->next) {
				if (p->geteNo() == No) {
					break;
				}
			}
			if (p) {
				cout << "请按下列顺序重新输入该教职工信息：" << endl;//直接将新信息覆盖该教职工原有信息
				cout << "姓名/性别/学院/系/学历/工号/电话：" << endl;
				a = 1;
				string a, b, c, d, e, f, g;
				cin >> a >> b >> c >> d >> e >> f >> g;
				employee e1(a, b, c, d, e, f, g);
				employee* s = new employee(e1);
				q->next = s;
				s->next = p->next;
				delete p;
				
			}
			else {
				cout << "该系统中无该工号的教职工" << endl;
			}
		}
		if (a) { cout << "————已成功修改教职工信息！————" << endl;  }
	}
}
void employeelist::write() {
	ofstream outemployee("employee.txt");
	employee* p = head;
	for (; p->next; p = p->next) {
		outemployee << left;
		outemployee << setw(11) << p->getename() << " " << setw(11) << p->getsex() << " " << setw(11) << p->getIns() << " " << setw(11) << p->getDep() << " ";
		outemployee << setw(11) << p->getedu() << " " << setw(11) << p->geteNo() << " " << setw(11) << p->gettele();
		outemployee << endl;
	}
	outemployee << left;
	outemployee << setw(11) << p->getename() << " " << setw(11) << p->getsex() << " " << setw(11) << p->getIns() << " " << setw(11) << p->getDep() << " ";
	outemployee << setw(11) << p->getedu() << " " << setw(11) << p->geteNo() << " " << setw(11) << p->gettele();
}
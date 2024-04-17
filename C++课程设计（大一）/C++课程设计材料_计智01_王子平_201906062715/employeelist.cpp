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
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	employee* s = head;
	for (; s ; s = s->next) {
		if (s->geteNo() == No) {
			s->employeedisplay();
			break;
		}
		
	}
	if (!s) { cout << "ϵͳ���޸ý�ְ����Ϣ" << endl; }
}
void employeelist::check_by_ename(string name) {
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	employee* s = head;
	for (;s ; s = s->next) {
		if (s->getename() == name) {
			s->employeedisplay();
			break;
		}
	}
	if (!s) { cout << "ϵͳ���޸ý�ְ����Ϣ" << endl; }
}
void employeelist::check_by_Ins(string In) {
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	employee* s = head;
	int a = 0;
	for (; s; s = s->next) {
		if (s->getIns() == In) {
			s->employeedisplay();
			a = 1;
		}
		
	}
	if (!a) { cout << "ϵͳ���޸ý�ְ����Ϣ" << endl; }
	else { cout << "���ҽ������" << endl; }
}
void employeelist::check_by_Dep(string De) {
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	employee* s = head;
	int a = 0;
	for (;s ; s = s->next) {
		if (s->getDep() == De) {
			s->employeedisplay();
			a = 1;
		}
	}
	if (!a) { cout << "ϵͳ���޸ý�ְ����Ϣ" << endl; }
	else { cout << "���ҽ������" << endl; }
}
void employeelist::check_by_edu(string ed) {
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	employee* s = head;
	int a = 0;
	for (;s ; s = s->next) {
		if (s->getedu() == ed) {
			s->employeedisplay();
			a = 1;
		}
		
	}
	if (!a) { cout << "ϵͳ���޸ý�ְ����Ϣ" << endl; }
	else { cout << "���ҽ������" << endl; }
}
void employeelist::check_by_tele(string tel) {
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	employee* s = head;
	int a = 0;
	for (;s ; s = s->next) {
		if (s->gettele() == tel) {
			s->employeedisplay();
			a = 1;
		}
		
	}
	if (!a) { cout << "ϵͳ���޸ý�ְ����Ϣ" << endl; }
	else { cout << "���ҽ������" << endl; }
}
void employeelist::count_edu_by_Dep(string De) {
	employee* s = head;
	if (!head) { cout << "��ϵͳ�����κν�ְ����Ϣ" << endl; }
	else {
		int undergraduate = 0;
		int graduate = 0;
		int Doctor = 0;
		int post_doctoral = 0;
		for (; s; s = s->next) {
			if (s->getDep() == De) {
				if (s->getedu() == "������") {
					undergraduate++;
				}
				else if (s->getedu() == "�о���") {
					graduate++;
				}
				else if (s->getedu() == "��ʿ") {
					Doctor++;
				}
				else if (s->getedu() == "��ʿ��") {
					post_doctoral++;
				}
			}
		}
		cout << "����������������������������������������" << endl;
		cout << De << "��ְ��ѧ��ͳ�ƽ��Ϊ��" << endl;
		cout << "***��������" << setw(5) << undergraduate << "��" << endl;
		cout << "***�о�����" << setw(5) << graduate      << "��" << endl;
		cout << "***��ʿ  ��" << setw(5) << Doctor        << "��" << endl;
		cout << "***��ʿ��" << setw(5) << post_doctoral << "��" << endl;
		cout << "����������������������������������������" << endl;
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
	employee* q = head;//����ָ�룬��pָ��ָ��ڶ����ڵ��ʼ��ָ��pָ��ָ��Ľڵ����һ���ڵ�
	int a = 0;//�����ж��Ƿ�ɾ���˽�ְ����Ϣ
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
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
		if (!a) { cout << "ϵͳ���޸ù��ŵĽ�ְ����Ϣ" << endl; }
		else { cout << "���������ý�ְ����Ϣ��ɾ������������" << endl; }
	}
}
void employeelist::change_by_eNo(string No) {
	employee* p = head;
	employee* q = head;//����ָ�룬��pָ��ָ��ڶ����ڵ��ʼ��ָ��pָ��ָ��Ľڵ����һ���ڵ�
	int a = 0;//�����ж��Ƿ�ɾ���˽�ְ����Ϣ
	if (!head) {
		cout << "ϵͳ�����κν�ְ����Ϣ" << endl;
	}
	else {
		if(p->geteNo()==No){
			cout << "�밴����˳����������ý�ְ����Ϣ��" << endl;//ֱ�ӽ�����Ϣ���Ǹý�ְ��ԭ����Ϣ
			cout << "����/�Ա�/ѧԺ/ϵ/ѧ��/����/�绰��" << endl;
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
				cout << "�밴����˳����������ý�ְ����Ϣ��" << endl;//ֱ�ӽ�����Ϣ���Ǹý�ְ��ԭ����Ϣ
				cout << "����/�Ա�/ѧԺ/ϵ/ѧ��/����/�绰��" << endl;
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
				cout << "��ϵͳ���޸ù��ŵĽ�ְ��" << endl;
			}
		}
		if (a) { cout << "���������ѳɹ��޸Ľ�ְ����Ϣ����������" << endl;  }
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
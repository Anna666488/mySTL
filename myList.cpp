#include <vector>
#include <iostream>
using namespace std;


class List
{
private:
	int data;	// �洢Ԫ��
	List *link;	// ��һԪ�ؽṹ��ָ��
public:
	List();
	List(vector<int> &a);	
	void append(int val);	// ��β����һ��Ԫ��
	void insertElement(int pos, int val);	// ��ָ��λ�����һ��Ԫ��
	void deleteElement(int val);	// ɾ��Ԫ��
	void travalList()const;	// ��ͷ�ڵ�����������
	int getLength();
	List(const List& lst);
	bool isEqual(const List &lst);
	void connect(const List &dv);
};

//10 8 12 20 100
//10 8 20 12 100

List::List(vector<int>& a)//����Ĺ���
{
	List* p1;
	p1 = this;
	int sum, i = 0;
	sum = a.size();
	while (i < sum) {
		List* p2 = new List;
		p2->data = a[i];
		p1->link = p2;
		p1 = p1->link;
		i++;
	}
	if (i == sum) {
		p1->link = NULL;
	}
}


bool List::isEqual(const List& lst)//�ж����������Ƿ����
{
	List* p1, * p2;
	p1 = this->link;
	p2 = lst->link;
	if (p1 == NULL && p2 == NULL) {
		return true;
	}
	while (p1 != NULL && p2->link != NULL && p1->data == p2->data) {
		p1 = p1->link;
		p2 = p2->link;
	}
	if (p1 == NULL && p2 == NULL) {
		return true;
	}
	return false;
}


void List::connect(const List& dv) {//������������

	List* p1, * k;
	p1 = this->link;
	k = dv.link;//first
	while (p1 != NULL) {
		p1 = p1->link;
	}
	p1->link = k;
}

int List::getLength() {//��ȡ����ĳ���
	List* pre = this->link;
	int sum = 1;
	while (pre->link != NULL) {
		pre = pre->link;
		sum++; //ѭ�������Ϊ�� 
	}
	cout << "The length of this List is " << sum << "." << endl;
	return 0;
}

List::List(const List& lst) {//������ֵ

	link = NULL;
	List* pre, * next, * p;
	pre = this;
	p = lst.link;
	next = new List;
	while (p != NULL) {
		next->link = new List;
		next->data = p->data;
		pre->link = next->link;
		pre = pre->link;
		pre->data = next->data;
		p = p->link;
	}
}

List::List() {
	data = 0;
	this->link = NULL;
}

void List::append(int val) {//����Ԫ�ص�׷��
	List* pre = this;      //ָ��pָ������� 
	while (pre->link != NULL)
	{   //������Ϊ�� 
		pre = pre->link;    //ѭ�������Ϊ�� 
	}
	List* mylist = new List;
	mylist->data = val;
	pre->link = mylist;
	mylist->link = NULL;
}

void List::insertElement(int pos, int val) {//��ĳһλ�ò���Ԫ��

	List* a = new List;
	a->data = val;
	List* pre = this->link;
	int count = 0;   //��һ����Ϊ��0�� 
	for (; pre->link != NULL; pre = pre->link) {   //������Ϊ�� 
		if (count == pos) {
			a->link = pre->link;
			pre->link = a;
			break;
		}
		count++;
	}
}

void List::deleteElement(int val) {//ɾ��Ԫ��

	List* pre = this;
	int sum = -1;
	for (; pre->link != NULL; pre = pre->link) {
		sum++;
		List* t = pre->link;
		if (sum == val)
		{     //��һ������Ҫɾ������ 	
			pre->link = t->link;
			delete t;
			break;
		}
	}
	if (pre->link == NULL) {
		cout << "\nElement " << val << " not Found." << endl;
	}
}

void List::travalList() {//����ı���
	List* pre = this->link;
	for (; pre != NULL; pre = pre->link) {
		cout << pre->data << " ";
	}
	cout << endl;
}


int main() {
	int N, i = 0, j = 0, x, M, s;
	vector<int> in1, in2;
	cin >> N;
	while (i < N) {
		cin >> x;
		in1.push_back(x);
		i++;
	}
	List listA(in1);
	cin >> M;
	while (j < M) {
		cin >> s;
		listA.deleteElement(s);
		listA.travalList();
		j++;
	}
	return 0;
}



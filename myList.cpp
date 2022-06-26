#include <vector>
#include <iostream>
using namespace std;


class List
{
private:
	int data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
	List(vector<int> &a);	
	void append(int val);	// 链尾增加一个元素
	void insertElement(int pos, int val);	// 在指定位置添加一个元素
	void deleteElement(int val);	// 删除元素
	void travalList()const;	// 从头节点遍历输出链表
	int getLength();
	List(const List& lst);
	bool isEqual(const List &lst);
	void connect(const List &dv);
};

//10 8 12 20 100
//10 8 20 12 100

List::List(vector<int>& a)//链表的构造
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


bool List::isEqual(const List& lst)//判断两个链表是否相等
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


void List::connect(const List& dv) {//连接两个链表

	List* p1, * k;
	p1 = this->link;
	k = dv.link;//first
	while (p1 != NULL) {
		p1 = p1->link;
	}
	p1->link = k;
}

int List::getLength() {//获取链表的长度
	List* pre = this->link;
	int sum = 1;
	while (pre->link != NULL) {
		pre = pre->link;
		sum++; //循环到最后为空 
	}
	cout << "The length of this List is " << sum << "." << endl;
	return 0;
}

List::List(const List& lst) {//拷贝赋值

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

void List::append(int val) {//链表元素的追加
	List* pre = this;      //指针p指向该链表 
	while (pre->link != NULL)
	{   //当链表不为空 
		pre = pre->link;    //循环到最后为空 
	}
	List* mylist = new List;
	mylist->data = val;
	pre->link = mylist;
	mylist->link = NULL;
}

void List::insertElement(int pos, int val) {//在某一位置插入元素

	List* a = new List;
	a->data = val;
	List* pre = this->link;
	int count = 0;   //第一个数为第0个 
	for (; pre->link != NULL; pre = pre->link) {   //当链表不为空 
		if (count == pos) {
			a->link = pre->link;
			pre->link = a;
			break;
		}
		count++;
	}
}

void List::deleteElement(int val) {//删除元素

	List* pre = this;
	int sum = -1;
	for (; pre->link != NULL; pre = pre->link) {
		sum++;
		List* t = pre->link;
		if (sum == val)
		{     //下一个数是要删除的数 	
			pre->link = t->link;
			delete t;
			break;
		}
	}
	if (pre->link == NULL) {
		cout << "\nElement " << val << " not Found." << endl;
	}
}

void List::travalList() {//链表的遍历
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



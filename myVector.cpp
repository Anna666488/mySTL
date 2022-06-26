#include<iostream>
using namespace std;
template <class T>
class DynamicVector
{
private:
	T* array; //pointer to the items ָ�����ռ��ָ��
	unsigned mallocSize; //number of allocated spaces ����ռ�Ĵ�С
	unsigned numofItems; //number of items �������Ѿ��洢��Ԫ������
	int virtualZero; //virtual zero ������ʼ�±꣬C������ͨ�������±��Ǵ�0��ʼ�� ����������Կ�����������±��-10��2�ȵ�������ʼ �������������
public:
	DynamicVector(int);
	~DynamicVector();
	inline void push_back(const T&);
	T& operator[] (int Vindex);
	unsigned length() const;
	unsigned capacity() const;
	int firstIndex() const;
	//void push_back (const T& newItem);
};


/*
a�����numofItems < mallocSizeʱ����ô�����ռ��С���䣬���Ѵ�Ԫ�ص�������һ��newItemԪ�أ�����numofItems++��
b�����numofItems == mallocSizeʱ����ô�����ռ��С���ӵ���2 * mallocSize +1����ԭ��Ԫ�����ݲ��䣬��ԭ��Ԫ�غ������һ��newItemԪ�أ�����numofItems++��
ע��黹�ڴ档
*/
template <class T>
inline void DynamicVector<T>::push_back(const T& newItem) {//����һ��Ԫ��
	if (numofItems < mallocSize) {
		array[numofItems++] = newItem;
	}
	else if (numofItems == mallocSize) {//����
		mallocSize = 2 * mallocSize + 1;
		if (array != NULL) {
			T* array2 = new T[mallocSize];
			for (int i = 0; i < numofItems; i++)
			{
				array2[i] = array[i];
			}
			array2[numofItems++] = newItem;

			delete[] array;
			array = array2;
		}
		else {
			array = new T[mallocSize];
			array[numofItems++] = newItem;
		}
	}
}

template <class T>
DynamicVector<T>::~DynamicVector() {

	delete[] array;
}

template <class T>
DynamicVector<T>::DynamicVector(int Vindex) {
	/ virtual zero ������ʼ�±꣬

		array = NULL;
	numofItems = 0;
	mallocSize = 0;
	virtualZero = Vindex;
}
template <class T>
T& DynamicVector<T>::operator[] (int Vindex) {
	/ []Ԫ�ط��ʵ�����
		int _entry = Vindex - virtualZero;
	if (_entry < 0 || _entry >= numofItems){
		cout << endl << "Out Of Range";
		exit(1);
	}
	return array[_entry];
}
template <class T>
unsigned DynamicVector<T>::length() const {
	return numofItems;
}
template <class T>
unsigned DynamicVector<T>::capacity() const {
	return this->mallocSize;
}
template <class T>
int DynamicVector<T>::firstIndex() const {

	return this->virtualZero;
}

int main(){
	int i, n;
	DynamicVector<int> ra(-2);

	cin >> n;
	ra.push_back(-3);
	ra.push_back(-2);
	ra.push_back(-1);
	for (i = 0; i < n; i++)
	{
		ra.push_back(i);
	}
	cout << "\n malloSize is " << ra.capacity();
	cout << "\n numofItems is " << ra.length();
	cout << "\n StartIndex is " << ra.firstIndex() << endl;
	for (i = -2; i < n + 3; i++)
	{
		cout << ra[i] << " ";
	}
	return 0;
}
#include<iostream>
using namespace std;
template <class T>
class DynamicVector
{
private:
	T* array; //pointer to the items 指向分配空间的指针
	unsigned mallocSize; //number of allocated spaces 分配空间的大小
	unsigned numofItems; //number of items 向量内已经存储的元素数量
	int virtualZero; //virtual zero 数组起始下标，C语言中通常数组下标是从0开始， 这个数据属性可以让数组的下标从-10或2等等整数开始 ，让数组更加灵活。
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
a、如果numofItems < mallocSize时，那么向量空间大小不变，在已存元素的最后，添加一个newItem元素，并且numofItems++；
b、如果numofItems == mallocSize时，那么向量空间大小增加到（2 * mallocSize +1），原有元素内容不变，在原有元素后面添加一个newItem元素，并且numofItems++；
注意归还内存。
*/
template <class T>
inline void DynamicVector<T>::push_back(const T& newItem) {//新增一个元素
	if (numofItems < mallocSize) {
		array[numofItems++] = newItem;
	}
	else if (numofItems == mallocSize) {//扩容
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
	/ virtual zero 数组起始下标，

		array = NULL;
	numofItems = 0;
	mallocSize = 0;
	virtualZero = Vindex;
}
template <class T>
T& DynamicVector<T>::operator[] (int Vindex) {
	/ []元素访问的重载
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
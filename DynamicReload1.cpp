#include <iostream>
#include<malloc.h>
using namespace std;
template <typename T>
class DynamicArray
{
private:
	T* array; //pointer  ，一个T类型的指针
	unsigned int mallocSize; //分配空间的大小。

public:
	//Constructors 
	DynamicArray(unsigned length, const T& content); // mallocSize=length; 设置每个元素的初始内容是 content；

   //Copy Constructor 
	DynamicArray(const DynamicArray<T>& anotherDA);

	// Destructors
	~DynamicArray();

	//return the this->mallocSize
	unsigned int capacity() const;

	// for the array[i]=someT.
	T& operator[](unsigned int i);
	T& operator[](unsigned int i) const;
	DynamicArray<T>& operator= (const DynamicArray<T>& anotherDA);
};

template <typename T>   //析构函数  
DynamicArray<T>::~DynamicArray() {
	cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
	delete[] array;
}

template <typename T>
unsigned int DynamicArray<T>::capacity() const {//动态数组的容量大小
	return mallocSize;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& anotherDA) {//拷贝构造
	cout << endl << "Copy Constructor is called";
	array = new T[anotherDA.mallocSize];
	for (int i = 0; i < anotherDA.mallocSize; i++) {
		array[i] = anotherDA.array[i];
	}
	mallocSize = anotherDA.mallocSize;
}

template <typename T>  //构造函数 
DynamicArray<T>::DynamicArray(unsigned length, const T& content) {
	mallocSize = length;
	cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";

	array = new T[mallocSize];
	for (int i = 0; i < mallocSize; i++) {
		array[i] = content;
	}
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int i) {//[]的重载
	if (i > mallocSize || i <= 0) {
		return  array[0];
	}
	return array[i];
}

template <typename T>
T& DynamicArray<T>::operator[] (unsigned int i) const {//[]的重载 常量不允许修改
	if (i > mallocSize || i <= 0) {
		return  array[0];
	}
	return array[i];
}

/*
new T[3] malloc 3*4=12 bytes memory in heap
Copy Constructor is called
Copy Constructor is called
-1 -1 -1
operator = is called
operator = is called
0 1 2
delete[] array free 3*4=12 bytes memory in heap
delete[] array free 3*4=12 bytes memory in heap
delete[] array free 3*4=12 bytes memory in heap
*/
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& anotherDA) {//=的重载
	cout << endl << "operator = is called";
	mallocSize = anotherDA.mallocSize;
	array = new T[anotherDA.mallocSize];
	for (int i = 0; i < mallocSize; i++) {
		array[i] = anotherDA.array[i];
	}
	return *this;
}


int main()
{
	int length, i;
	cin >> length;

	DynamicArray<int> iarray(length, -1);

	DynamicArray<int> iarray2(iarray), iarray3(iarray2);

	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray3[i] << " ";
		iarray[i] = i * 1.1;
	}
	iarray3 = iarray2 = iarray;
	cout << endl;
	for (i = 0; i < length; i++) {
		cout << iarray3[i] << " ";
	}
	return 0;
}
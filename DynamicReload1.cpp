#include <iostream>
#include<malloc.h>
using namespace std;
template <typename T>
class DynamicArray
{
private:
	T* array; //pointer  ��һ��T���͵�ָ��
	unsigned int mallocSize; //����ռ�Ĵ�С��

public:
	//Constructors 
	DynamicArray(unsigned length, const T& content); // mallocSize=length; ����ÿ��Ԫ�صĳ�ʼ������ content��

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

template <typename T>   //��������  
DynamicArray<T>::~DynamicArray() {
	cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
	delete[] array;
}

template <typename T>
unsigned int DynamicArray<T>::capacity() const {//��̬�����������С
	return mallocSize;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& anotherDA) {//��������
	cout << endl << "Copy Constructor is called";
	array = new T[anotherDA.mallocSize];
	for (int i = 0; i < anotherDA.mallocSize; i++) {
		array[i] = anotherDA.array[i];
	}
	mallocSize = anotherDA.mallocSize;
}

template <typename T>  //���캯�� 
DynamicArray<T>::DynamicArray(unsigned length, const T& content) {
	mallocSize = length;
	cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";

	array = new T[mallocSize];
	for (int i = 0; i < mallocSize; i++) {
		array[i] = content;
	}
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int i) {//[]������
	if (i > mallocSize || i <= 0) {
		return  array[0];
	}
	return array[i];
}

template <typename T>
T& DynamicArray<T>::operator[] (unsigned int i) const {//[]������ �����������޸�
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
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& anotherDA) {//=������
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
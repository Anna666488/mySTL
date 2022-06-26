#include <iostream>
#include<malloc.h>
using namespace std;

class Point
{
	int x, y;
public:
	//���캯������� cout<<"\nPoint is called!";  �����˽�г�Ա�ĳ�ʼ��
	Point()
	{
	}
	Point(int xx)
	{
		x = xx;
		y = 0;
		cout << "Point is called!";
	}
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
		cout << "\nPoint is called!";
	}

	//�������������    cout<<"\n~Point is called!";
	~Point()
	{
		cout << "\n~Point is called!";
	}

	//��Ԫ������������   "("<<p.x<<","<<p.y<<")";
	//friend class DynamicArray;   
	friend ostream& operator<<(ostream& out, Point& p)
	{
		out << "(" << p.x << "," << p.y << ")";
		return out;
	}
	Point& operator=(const Point& z)
	{
		x = z.x;
		y = z.y;
		return *this;
	}
};
template <class T>
class DynamicArray
{
	class Point;
private:
	T* array; //pointer  ��һ��T���͵�ָ��
	unsigned int mallocSize; //����ռ�Ĵ�С��

public:
	//Constructors 
	// cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	//DynamicArray(const DynamicArray<T> & anotherDA ) ;����ÿ��Ԫ�صĳ�ʼ������ content��

   //Copy Constructor 
   // cout<<endl<< "Copy Constructor is called";
	DynamicArray(const DynamicArray<T>& anotherDA);

	// Destructors
	 // cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap"; 
	~DynamicArray();
	//return the this->mallocSize
	unsigned int capacity() const;
	// for the array[i]=someT.
	T& operator[](unsigned int i);
	T& operator[](unsigned int i) const;
	DynamicArray(unsigned length, const T& content);
	int resize(unsigned int newSize, const T& ValOfNewItems);
	/*������һ����䣺cout<<"\nresize is called";
	1�����newSize > ԭ����mallocSize, ��ô��newSize ��С��������ռ䣬����Ԫ�ص�ֵ��ValOfNewItems�� ���� ������1��
	2�����newSize ==ԭ����mallocSize, ��ô�����С�����ݶ����䣻���� ������0��
	3�����newSize <ԭ����mallocSize, ��ô�൱�ڽض����飬����newSize ��С��������ռ䣬������newSize��ԭ�����ݣ����� ������-1��
	*/
};

template <typename T>
int DynamicArray<T>::resize(unsigned int newSize, const T& ValOfNewItems)
{
	int i, m;
	m = this->mallocSize;

	cout << "\nresize is called";
	//cout<<endl;
	if (newSize > m)
	{
		T* array2 = new T[newSize];
		for (int j = 0; j < newSize; j++)
		{
			cout << "\nPoint is called!";
		}
		for (i = 0; i < m; i++)
		{
			array2[i] = array[i];
		}
		for (i = m; i < newSize; i++)
		{
			array2[i] = ValOfNewItems;
		}
		delete[] array;
		mallocSize = newSize;
		array = array2;

		return 1;
	}

	else if (newSize == m)
	{
		// array=new T(newSize);	
		return 0;
	}

	else if (newSize < m)
	{
		T* array2 = new T[newSize];
		for (int j = 0; j < newSize; j++)
		{
			cout << "\nPoint is called!";
		}
		for (i = 0; i < newSize; i++)
		{
			array2[i] = array[i];
		}
		delete[] array;
		mallocSize = newSize;
		array = array2;
		return -1;
	}

}

template <typename T>  //��������  
DynamicArray<T>::~DynamicArray()
{
	cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
	//for(int i=0;i<mallocSize;i++)
	delete[] array;
}

template <typename T>
unsigned int DynamicArray<T>::capacity() const
{
	return mallocSize;
}

template <typename T>  //���캯��    DynamicArray<Point> iarray(length,Point(3));
DynamicArray<T>::DynamicArray(unsigned length, const T& content)

{
	mallocSize = length;
	cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
	for (int i = 0; i < mallocSize; i++)
	{
		cout << "\nPoint is called!";
	}
	array = new T[mallocSize];
	for (int i = 0; i < mallocSize; i++)
	{
		array[i] = content;
	}
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int i)
{
	if (i > mallocSize || i <= 0)
	{
		return  array[0];
	}
	return array[i];
}

template <typename T>
T& DynamicArray<T>::operator[] (unsigned int i) const
{
	if (i > mallocSize || i <= 0)
	{
		return  array[0];
	}
	return array[i];
}

/*1 3
�������
Point is called!
new T[1] malloc 1*8=8 bytes memory in heap
Point is called!
~Point is called!
Point is called!
resize is called
Point is called!
Point is called!
Point is called!
~Point is called!
1
~Point is called!
(3,0) (1,2) (1,2)
delete[] array free 3*8=24 bytes memory in heap
~Point is called!
~Point is called!
~Point is called!*/

int main()
{
	int length, i;
	cin >> length;
	DynamicArray<Point> iarray(length, Point(3));
	cin >> length;
	cout << endl << iarray.resize(length, Point(1, 2));
	cout << endl;
	for (i = 0; i < length; i++)
	{
		cout << iarray[i] << " ";
	}
	return 0;
}



#include <iostream>
#include <string>
using namespace std;
#define max 20
class MyQueue//  MyQueue
{
private:	
int *array;	
int ff,ll,size;	

public:
MyQueue()//���캯��
{
	size=0;
	ff=0;//ͷָ��
	ll=0;//βָ��
	array=new int[max];
}
void push(int val)//��β����Ԫ��
{
	array[size]=val;
	size++;
}
void pop()//��ͷ����Ԫ��
{
	int* array2=new int[max];
	ll=array[size];//����βָ��
	for(int i=0;i<size-1;i++)
	{
		array2[i]=array[i+1]; 
	}
	delete[] array;
	size--;
	array=array2;
	ff=array2[0];//����ͷָ��
}	
int first()
{
    return array[0];
} 

int last()
{
	return array[size-1];
}

int Mysize()
{
	return size;
}
bool isempty()
{
	if(size==0)
	return true;
	return false;
}


};


int main(void)
{
    using std::cin;
    using std::cout;
    using std::string;
    using std::endl;
    int N,value;
    string action;
    MyQueue A;
    cin>>N;
    for (int i=0;i<N;i++) {
        cin>>action;
        if (action=="push") {
            cin>>value;
            A.push(value);
        } else {
            if (action=="pop") A.pop();
            else
            if (action=="first") {
                cout<<A.first()<<endl;
            }
            else if (action=="last") {
                cout<<A.last()<<endl;
            }
        }
    }
    cout<<"size: "<<A.Mysize()<<endl;
    while (!A.isempty()) {
        cout<<A.first()<<" ";
        A.pop();
    }
    cout<<endl;
    return 0;
}



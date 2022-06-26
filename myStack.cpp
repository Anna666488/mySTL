#include <iostream>
#include <string>

#define MAX 20
class Mystack
{
private:		
		int *arr;
		int size;
public:    
	Mystack()//���캯��
	{
		size=0;
		arr=new int[MAX]; 
	} 
	int top()//��ȡջ����ֵ
	{
		return arr[size-1];
	} 
bool isempty()//ջ�Ƿ�Ϊ��
{
	if(size==0)
	{
		return true;
	}
	else
	{
		return false; 
	} 
 }  

void pop() //����ջ��Ԫ��
{
	int* arr2=new int[MAX];
	for(int i=0;i<size-1;i++)
	{
		arr2[i]=arr[i]; 
	}
	delete[] arr;
	size--;
	arr=arr2; 	
 }

void push(int val)//��ջ����
{
	arr[size]=val;
	size++;
}
	
int Mysize()//ջ�Ĵ�С
{    
	return size;
}	
};

int main(void) {
    using std::cin;
    using std::cout;
    using std::string;
    using std::endl;
    int N,i,j,value;
    string action;
    Mystack A;
    cin>>N;
    for (i=0;i<N;i++) {
        cin>>action;
        if (action=="push") {
            cin>>value;
            A.push(value);
        } else {
            if (action=="pop") A.pop();
            else
            if (action=="top") {
                cout<<A.top()<<endl;
            }
        }
    }
    cout<<"size: "<<A.Mysize()<<endl;
    while (!A.isempty()) {
        cout<<A.top()<<" ";
        A.pop();
    }
    cout<<endl;
    return 0;
}




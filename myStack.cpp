#include <iostream>
#include <string>

#define MAX 20
class Mystack
{
private:		
		int *arr;
		int size;
public:    
	Mystack()//构造函数
	{
		size=0;
		arr=new int[MAX]; 
	} 
	int top()//获取栈顶的值
	{
		return arr[size-1];
	} 
bool isempty()//栈是否为空
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

void pop() //弹出栈顶元素
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

void push(int val)//入栈操作
{
	arr[size]=val;
	size++;
}
	
int Mysize()//栈的大小
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




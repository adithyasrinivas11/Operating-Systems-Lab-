#include <iostream> 
using namespace std; 

template <typename T> 
class Stack { 
private: 
	T a[100]; 
	int top; 
public: 
	Stack(T a[], int top); 
	void push(T n);
	int pop();
	void print(); 
}; 

template <typename T> 
Stack<T>::Stack(T a[], int ) 
{ 
	top=-1;	
} 

template <typename T> 
void Stack<T>::print() { 
	for (int i = top; i>=0; i--) 
		cout<<" "<<a[i]; 
	cout<<endl; 
} 

template <typename T> 
void Stack<T>::push(T n) 
{ 
	if(top==99)
		printf("Stack is full");
	else
	{
		top=top+1;
		a[top]=n;
	}		
} 

template <typename T> 
int Stack<T>::pop() 
{ 
	int x=-1;
	if(top==-1)
		printf("Stack is empty \n");
	else
	{
		x=a[top];
		top=top-1;
	}
	return (x);		
} 

int main() { 
	int a[5]; 
	Stack<int> s(a, 5); 
	s.push(3);
	s.push(15);
	s.print(); 
	s.pop();
	s.print(); 
	return 0; 
} 


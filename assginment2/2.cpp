#include<iostream>
#include<string.h>
using namespace std;

template <typename T>

void sort(T a[100],int n)
{
	T t;
	int i,j;
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}	
		}
	}
}

int main()
{
	
	int n,a[100],i;
	float b[100];
	char c[100];
	cout<<"enter the number!"<<endl;
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	sort(a,n);
	
	for(i=0;i<n;i++)
		cout<<" "<<a[i];
	cout<<endl;
	
	cout<<"float"<<endl;
		
	for(i=0;i<n;i++)
		cin>>b[i];	
	
	sort(b,n);
	
	for(i=0;i<n;i++)
		cout<<" "<<b[i];
	cout<<endl;
	
	
		cout<<"string"<<endl;
	for(i=0;i<n;i++)
		cin>>c[i];	
	
	sort(c,n);
	
	for(i=0;i<n;i++)
		cout<<" "<<c[i];
	cout<<endl;
		
return 0;
}

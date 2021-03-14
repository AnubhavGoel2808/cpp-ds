#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;
class Heapsort
{
	int count;
	int *a;
	int size;
	public:
	Heapsort()
	{  count =1;
     	size=0;
	
	}
	void input()
	{
		cout<<"ENTER THE SIZE OF THE HEAP\n";
		cin>>size;
		a= new int[size];
		cout<<"ENTER THE ELEMENTS FOR THE HEAP\n";
		for(int i=0;i<size;i++)
		cin>>a[i];
	}


int left(int n)
{
   return (2*n+1);	
} 
int right (int n)
{
	return (2*n+2);
}

void max_heapify(int a[], int i, int n)
{   
    int l,r ,temp;
    int largest =i;
    temp = a[i];
    l= left(i);
    r=right(i);
      
        count++;
        if (l <= n && a[l] > a[i])
           largest =l;
        if(r<=n && a[r]>a[largest])
           largest =r;
    if(largest!=i)
    {
       int x= a[i];
       a[i]=a[largest];
       a[largest]=x;
   	max_heapify(a,largest,n);    
   }
}
void heapsort(int a[], int n)
{
    Build_max_heap(a,n);
	int i, temp;
    for (i = n-1; i >= 0; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        max_heapify(a, 0, i - 1);
    }
    cout<<"\nNo of comparisons="<<count<<endl;
}



void Build_max_heap(int a[], int n)
{    
    int i;
    for(i = floor(n/2 - 1); i >= 0; i--)
    {  
        max_heapify(a, i, n);
    }
}
void display()
{
	heapsort(a,size);
	
	for(int i=0;i<size;i++)
	cout<<a[i]<<" ";
}
};
int main()
{
    Heapsort A;
    A.input();
    A.display();
}

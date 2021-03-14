#include<iostream>
#include<math.h>
using namespace std;
class Radix_Sort
{
	 int *arr, *b;
	 int size;
	 public:
	 	Radix_sort()
	 	{
	 		size=0;
	}
		void input()
		{
			cout<<"ENTER THE NO OF ELEMENTS\n";
			cin>>size;
			arr= new int[size];
			b=new int[size];
			cout<<"ENTER THE ELEMENTS\n";
			for(int i=0;i<size;i++)
			 {
			    cin>>arr[i];
			    b[i]=0;
		   	}
	  	}

        int max(int arr[],int n)
        {
	       int large=arr[0];
	       for(int i=1;i<n;i++)
	    	if(large<arr[i])
		    	large=arr[i];
        	return large;
        }
		void count_sort(int a[],int b[],int n, int d)
   		{ 
   		
			int *c= new int[10];
			for (int i=0;i<10;i++)
			{    
				c[i]=0;
			}
		
			for(int j=0;j<n;j++)
			{    
				c[(a[j]/d)%10]=c[(a[j]/d)%10]+1;
			}
		
			for(int i=1;i<10;i++)
			{    
				c[i]=c[i]+c[i-1];
			}
			
			for(int j=n-1;j>=0;j--)
			{   
				b[(c[(a[j]/d)%10])-1]=a[j];
				c[(a[j]/d)%10]   = c[(a[j]/d)%10]-1;
			}
			
			for(int i=0;i<n;i++)
			a[i]=b[i];
			
	    }   
	    int digit_Calc()
	    {   int c=0;
		    int x= max(arr,size);
		  
		   	 while(x>0)
		   	  	{
		   	  	c++;
		   	  	x=x/10;
			  	}
		    return c;
		}
	    void radixsort(int arr[],int n)
        {
	        int d =digit_Calc();
	        
	        for(int i=0;i<d;i++)
	         { 
		       count_sort(arr,b,size,pow(10,i));
	         }
        }
        void display()
        {   
        radixsort(arr,size);
          
        for(int i=0;i<size;i++)
        {
           cout<<arr[i]<<"\n";
	    }
	   }
};
int main()
{
	Radix_Sort A;
	A.input();
	A.display();
}


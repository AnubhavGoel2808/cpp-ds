#include<iostream>
#include<conio.h>
using namespace std;
class queue
{
	int *q,f,l,size;
	public:
	queue()
	{
	 cout<<"Enter size of the queue : ";
	 cin>>size;                                                                 
	 q=new int[size];
	 f=l=-1;
    }
    void enQueue(int n)
    {
    	if(isfull())
    	{
		 cout<<"Overflow!"<<endl;
		 return ;
	    }
    	else if(l==-1)
    	{
		 ++f;
    	 q[++l]=n;
        }
        else
        {
         if(l<size-1)
          q[++l]=n;
         else
         {
         	l=0;
         	q[l]=n;
		 }
		}
    }
    int deQueue()
    {
    	if(f==l)
    	 cout<<"Underflow!"<<endl;
    	else
    	 return q[f++];
    }
    int isempty()
	{
		return (f==-1&&l==-1);
	}
    void clear()
	{
		f=-1;l=-1;
	}
	int isfull()
	{
	if(((l==size-1)&&(f==-1))||l==f-1)
    	 return 1;
    	return 0;
	}
	int frontel()
	{
		return q[f];
	}
	int lastel()
	{
		return q[l];
	}
	void show()
		{
			if(isempty())
			return;
			else
			cout<<"The queue contains: ";
			if(f<l)
			{
			for(int i=f;i<=size-1;i++)
			cout<<q[i];
			cout<<"\n";
		          }
		          else
		          if(l<f)
		          {
			for(int i=l+1;i<=size-1;i++)
			cout<<q[i];
			for(int i=0;i<=l;i++)
			cout<<q[l];
		          }
		          
		    
		}
};
int main()
{
	queue Q;
	int ch1,tmp;
	char ch2;
	do
	{
	cout<<"1-enqueue\n2-dequeue\n3-show\n4-isempty\n5-isfull\n6-clear\n7-frontel\n8-lastel"<<endl;
	cout<<"\nEnter your choice: ";
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			cout<<"Enter element : ";
			cin>>tmp;
			Q.enQueue(tmp);
			break;
		case 2:
			tmp=Q.deQueue();
			cout<<tmp<<" deleted!"<<endl;
			break;
		case 3:
			Q.show();
			break;
		case 4:
			tmp=Q.isempty();
			if(tmp==1)
			cout<<"The queue is empty";
			else 
			cout<<"The queue is not empty";
			break;
		case 5:
			tmp=Q.isfull();
			if(tmp==1)
			cout<<"The queue is full";
			else
			 cout<<"The queue is not full";
			break;
		case 6:
			Q.clear();
			cout<<"\nThe queue is cleared";
			break;
		case 7:
			cout<<Q.frontel();
			break;
		case 8:
			cout<<Q.lastel();
			break;
		default:
			cout<<"\nInvalid choice!"<<endl;
	}
	cout<<"\nDo you want to continue? ";
	cin>>ch2;
    }while(ch2=='y');
    getch();
    return 0;
}

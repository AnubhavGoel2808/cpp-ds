#include<iostream>
#include<conio.h>
using namespace std;
class sum_stack{
	int s1[10],s2[10],*res,l1,l2,l;
	public:
	sum_stack(){
		l1=l2=l=-1;
	}
	void enter()
	{
		int tmp;
	cout<<"Enter 1st number (enter -1 to exit) : "<<endl;
	do{
		
	    cin>>tmp;
		if(tmp!=-1)
		 s1[++l1]=tmp;
	}while(tmp!=-1);
	cout<<"Enter 2nd number (enter -1 to exit) : "<<endl;
	do{
		cin>>tmp;
		if(tmp!=-1)
		 s2[++l2]=tmp;
	}while(tmp!=-1);	
    }
	
	void cal()
	{
		int s,c1=0,c2=0,flag1=0,flag2=0;
	if(l1>l2)
	 res=new int[l1];
	else
	 res=new int[l2];
	
	while(1){
		if(flag1)
		 s=s2[l2--];
		else if(flag2)
		 s=s1[l1--];
		else
		 s=s1[l1--]+s2[l2--];
		if(s>9){
			c2+=s/10;
			s=s%10;
		}
		res[++l]=s+c1;
		c1=c2;
		c2=0;
		if(res[l]>9){
			c1=res[l]/10;
			res[l]=res[l]%10;
		}
		if(l1==-1)
		 flag1=1;
		if(l2==-1)
		 flag2=1;
		if(flag1&&flag2)
		 break;
	}
	}
	
	void display()
	{
		cout<<"Sum is : "<<endl;
	do{
		cout<<res[l--];
	}while(l!=-1);
	}
};

int main(){
	sum_stack s;
	s.enter();
	s.cal();
	s.display();
	getch();
	return 0;
}

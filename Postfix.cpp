#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class Postfix
{
          string s,t;
          int *a;
          int n,top,k,tmp,c=0;
	public:
		Postfix()
		{
			cout<<"Enter the expression: ";
			getline(cin,s);
			n=s.length();
			top=-1;
			tmp=0;
			k=-1;
			a=new int[n];
			seperate();
		}
		void seperate()
		{
			for(int i=0;s[i]!='\0';i++)
			{
				if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
				{
					t[++k]=s[i];
				     
			          }
			          else
			           a[++top]=s[i]-48;
				
                              }
                              for(int i=top;i>=0;i--)
                              cout<<a[i];
                              for(int i=0;i<=k;i++)
                              cout<<t[i];
			
		}
		void cal()
		{
			for(int i=0;i<=k;i++)
			{
				if(t[i]=='+')
				{
					pop(a[top-1],a[top]);
					tmp=a[top-1]+a[top];
				}
				else if(t[i]=='-')
				{
					pop(a[top-1],a[top]);
					tmp=a[top-1]-a[top];
				}
				else if(t[i]=='*')
				{
					pop(a[top-1],a[top]);
					tmp=a[top-1]*a[top];
				}
				else if(t[i]=='/')
				{
					pop(a[top-1],a[top]);
					tmp=a[top-1]/a[top];
				}
				top--;
				push(tmp,top);
				c++;
			}
			cout<<"counte: "<<c;
		}
		void pop(int b,int b1)
		{
			cout<<"\npopped "<<b<<" and "<<b1;
			
		}
		void push(int q,int z)
		{
			a[z]=q;
			cout<<"\npushed "<<a[top];
		}
		void show()
		{
			cout<<"\nans : "<<a[top];
		}
};
int main()
{
	Postfix p;
	p.cal();
	p.show();
	getch();
	return 0;
}

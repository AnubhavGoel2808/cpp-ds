#include<iostream>
#include"conio.h"
#include<ctype.h>
#include<string.h>
#include<stdio.h>
using namespace std;
template <typename T>
class Stack
{
	T *arr;
	int size;
	int top;
	public:
		Stack(int n)
		{   size=n;
			arr=new T[size];
			top=-1;
		}
		void push(T x)
		{
			if(top==size-1)
			{
				cout<<"stack overflow";
				return;
			}
			if(top==-1)
			top=0;
			else
			top++;
			arr[top]=x;
			
		}
		T pop()
		{
			if(top==-1)
			{
				cout<<"\nstacck underflow\n";
				return -1;
			}
			return arr[top--];
		}
		T cal(string ex)
		{
			int i=0;
			T op1,op2,value;
			while(i<size)
			{
				if(isdigit(ex[i]))
				push(ex[i]-'0');
				else
				{
					op2=pop();
					op1=pop();
					char ch;
					ch=ex[i];
					switch(ch)
					{
						case '+':value=op1+op2;
								break;
						case '-':value=op1-op2;break;
						case '*':value=op1*op2;break;
						case '/':value=op1/op2;break;		
					}
					push (value);
				}
				i++;
			}
			return (pop());
			}
			~Stack()
			{
				delete(arr);
			}
		};
		int main()
		{
			string ex;
			cout<<"enter the postix fix expression\t:";
			getline(cin,ex);
			int x=ex.length();
			Stack<float> s(x);
			cout<<"final ans of postfix expression is ::\t"<<s.cal(ex);	
		}
		
		

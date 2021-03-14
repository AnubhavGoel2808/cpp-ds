#include<iostream>
#include"conio.h"
using namespace std;
class node
{public:
	int info;
	node *next;
	node(int val,node *nxt=0)
	{
		info=val;
		next=nxt;
	}
};
class SLL
{
	node *head;
	public:
		SLL()
		{
			head=0;
		}
		void insertathead(int val)
		{
			head= new node(val,head);
		}
		void insertatend(int val)
		{
			node *newnode=new node(val);
			node *ptr=head;
			if(ptr==0)
			{
			head=newnode;
		    return;
			}
			while(ptr->next!=0)
			ptr=ptr->next;
			ptr->next=newnode;
		}
		void insertbefore(int val,int beforeno)
		{
			node *ptr,*preptr,*newnode;
			newnode=new node(val);
			ptr=head;
			if(ptr->info==beforeno)
			{
				newnode->next=ptr;
				head=newnode;
			    return;
			}
			while(ptr->info!=beforeno)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			preptr->next=newnode;
			newnode->next=ptr;
		}
		void insertafter(int val,int afterno)
		{
			node *ptr,*preptr,*newnode;
			newnode=new node(val);
			ptr=head;
			if(ptr->info==afterno)
			{preptr=ptr;
			ptr=ptr->next;
			preptr->next=newnode;
			newnode->next=ptr;
				
			    return;
			}
			preptr=ptr;
			while((preptr->info!=afterno)&&(ptr!=0))
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(ptr==0)
			return;
			preptr->next=newnode;
			newnode->next=ptr;
		}
		int deletefromhead()
		{	if(head==0)
			{
				cout<<"\nno linked list created\n";
				return -1;
			}
			node *ptr=head;
			head=head->next;
			int x=ptr->info;
			delete(ptr);
			return x;
		}
		int deletefromend()
		{	if(head==0)
			{
				cout<<"\nno linked list created\n";
				return -1;
			}
			node *ptr=head;node *preptr=ptr;
			while(ptr->next!=0)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			int x=ptr->info;
			preptr->next=0;
			delete(ptr);
			return x;
		}
		int deleteafter(int afterno)
		{	if(head==0)
			{
				cout<<"\nno linked list created\n";
				return -1;
			}
			node *ptr=head;node *preptr=ptr;
			while(preptr->info!=afterno)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			int x=ptr->info;
			preptr->next=ptr->next;
			delete(ptr);
			return x;
		}
		int deletespecific(int no)
		{	if(head==0)
			{
				cout<<"\nno linked list created\n";
				return -1;
			}
			node *ptr=head;
			if(ptr->info==no)
			{
				int x=ptr->info;
				head=head->next;
				delete(ptr);
				return x;
			}
			node *preptr;
			while(ptr->info!=no)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			int x=ptr->info;
			preptr->next=ptr->next;
			delete(ptr);
			return x;
		}
		void deletell()
		{
			node *ptr=head;
			while(ptr!=0)
			{
			cout<<deletefromhead()<<"\t";
			ptr=head;
		    }
		    cout<<"\nlinked list cleared\n";
		}
		void display()
		{
			node *ptr=head;
			while(ptr!=0)
			{
				cout<<ptr->info;
				ptr=ptr->next;
			}
		}
		void append(SLL s1)
		{
			node *ptr=s1.head;
			while(ptr!=0)
			{
				insertatend(ptr->info);
				ptr=ptr->next;
			}
		}
		void reverse()
		{node *ptr=head;
		while(ptr->next!=0)
		{
			ptr=ptr->next;
		}
			if(head){
				if(head->next!=0)
				{
					node *curr=head->next;
					node *next;
					node *prev =head;
					while(curr){
						next=curr->next;
						curr->next=prev;
						prev=curr;
						curr=next;
						
						}
						head->next=0;
						head=ptr;
				}
				
				
			}	
		}
		void search(int x){
			if(head==NULL){
				return;}
				else
				{node *temp=head;
				while(temp!=0){
					if (temp->info==x)
					{
						cout<<"\nelement found\t"<<temp->info;
						return;
					}
					else{temp=temp->next;
					}
					if(temp==0)
					cout<<"\nnot found\n";
				}
				}
			}
			
			
};
int main()
{
	SLL s,s1;
	int c,val,temp;
	char ch,t;
	do{
		cout<<"\n1.insert at head \n2.insert at tail \n3.insert before \n4.insert after \n5.delete from head\n6.delete from tail\n7.delete before\n8.delete specific\n9.clear linked list\n";
		cout<<"\n10.append two linked list\n11.reverse a linked list\n12.search a value in SLL\n";
		cout<<"\nenter the choice\n";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"\nenter the value to insert\t";
					cin>>val;
					s.insertathead(val);
					s.display();break;
			case 2:cout<<"\nenter the value to insert\t";
					cin>>val;
					s.insertatend(val);
					s.display();break;
			case 3:cout<<"\nenter the value to insert\t";
					cin>>val;
					cout<<"\nenter the value before which no. has t be inserted\t";
					cin>>temp;
					s.insertbefore(val,temp);
					s.display();break;	
			case 4:cout<<"\nenter the value to insert\t";
					cin>>val;
					cout<<"\nenter the value after which no. has t be inserted\t";
					cin>>temp;
					s.insertafter(val,temp);
					s.display();break;
			case 5:temp=s.deletefromhead();
			if(temp!=-1)
			cout<<"\ndeleted element\t"<<temp;
					s.display();break;
			case 6:temp=s.deletefromend();
			if(temp!=-1)
				cout<<"\ndeleted element\t"<<temp;
					s.display();break;		
			case 7:cout<<"\nenter the element after which element has to be deleted\t";
			cin>>val;
			temp=s.deleteafter(val);
			if(temp!=-1)
			cout<<"\ndeleted element\t"<<temp<<"\n";
					s.display();break;
			case 8:	cout<<"\nenter the element which element has to be deleted\t";
			cin>>val;
			temp=s.deletespecific(val);
			if(temp!=-1)
			cout<<"\ndeleted element\t"<<temp<<"\n";
					s.display();break;			
			case 9: s.deletell();break;
			case 10:cout<<"\nenter the elements of second linked list\n";
				  t='y';
				  while(t=='y')
				  {	cin>>val;
				  	s1.insertatend(val);
				  	cout<<"\nwant to add more\t";
				  	cin>>t;
				  }	
				   s1.display();
			        s.append(s1);
			        cout<<"\nappended list\n";
				  s.display();
				  break;		
			case 11: s.reverse();
					s.display();
					break;
			case 12: 
			int value;
			cout<<"\nenter the value to be searched for\t";
			cin>>value;
			s.search(value);
			break;			  
			default:cout<<"worng choice";break;								
		}
		cout<<"\nwant to cont\t";
		cin>>ch;
	  }while(ch=='y'||ch=='Y');
}

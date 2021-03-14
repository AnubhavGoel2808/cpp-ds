#include<iostream>
#include<conio.h>
using namespace std;
class node{
	public:
	int info;
	node* next;
	public:
		node(int value=0,node* p=0)
		{
			info=value;
			next=p;
		}
};
class SLL{
	public:
	
	node *tail;
	public:
		SLL(){
			tail=0;
		}
		void insertattail(int value){
			if(tail)
				{
				tail->next=new node(value,tail->next);
				tail=tail->next;}
			else
			{
				tail=new node(value);
				tail->next=tail;
			}
			}
		
		int Count(){
			if(tail==0)
			return 0;
			int count=1;
			node* current=tail->next->next;
			while(current!=tail->next)
			{
			current=current->next;
			count++;
			}
			
			return count;
		}
		
		void display(){
			if(tail==0)
		{cout<<"list is empty."<<endl;
			return;}
        else
			{node *current=tail->next;
			  cout<<current->info<<"\n";
			  current=current->next;
			while(current!=tail->next)
			{ cout<<current->info<<"\n";
			  current=current->next; 
			 
			
			}
        return ;}
		}
		
		    int search(int value){
		    	int h=Count();
		    	if(h==0){
				
		    		return -1;
				}
		    	if(tail)
		    		{node* curr=tail;
                     do{ if(curr->info==value)
                          return 1;
                          curr = curr->next;
					 }	while(curr!=tail);				
			} 
			  return 0;
		}
		
			 
			 int dft()
			 {  if(tail)
			    { int v=tail->info;
			       cout<<"deletd element is :"<<v;
			      if(tail==tail->next)
			       {delete tail;
			        tail=0;
			        
				   }
				   else
				   {node* current=tail->next;
				   for(    ;current->next!=tail;current=current->next);
				       
				
				    current->next=tail->next;
				        delete tail;
						  tail=current;}
				        
				        return v;
				   
				}  cout<<"list is empty "<<endl;
				  return -1;
		}
		
};

int main(){
	
	
	SLL ob; 
    
    

    int choice; 
    char ch='y'; 
    do{
    cout<<"1: Insert at Tail\n2: Search an element\n3: Count total no of nodes\n4: delete from Tail\n5:Display link list\n";
    cout<<endl<<"Enter your choice : ";
    cin>>choice;
   
    int d;
    switch(choice){
    
    	case 1: cout<<"enter element to be inserted at tail "<<endl;
    	int el;
    	cin>>el;
    	ob.insertattail(el);
    	break;
    	case 2:cout<<"enter element to be searched "<<endl;
    	   cin>>el;
    	   int q;
    	   q=ob.search(el);
    	   if(q==1)
    	   {
		   cout<<"Element found ";}
    	   else if(q==0) 
    	   {
		   cout<<"Element not found ";}
		   else
		   cout<<"list is empty ";
    	   break;
    	case 3:d=ob.Count();
		cout<<"total no of nodes are : "<<d<<endl;
    	    break;
    	   
		     case 4: 
			       ob.dft();
			       
		     break;
		     case 5: ob.display();
		     break;
		
		default: cout<<"Wrong choice";
		
	}
    	cout<<endl<<"If u want to continue press y :\n";
    	cin>>ch;
	}while(ch=='y');
    getch();
    return 0;
    
}

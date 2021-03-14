#include<iostream>
using namespace std;
class node 
{
	public:
	int data;
	char color;
	node *left,*right,*parent;
		node(int val=0)
		{data=val;
		color='b';
		parent=left=right=0;
		}
		
};
class rbt
{  node* root;
   node* nil;
    public:
	 rbt()
	 {
	 	nil=new node();
	  	nil->color='b';
	  	nil->data=-1;
	  	root=nil;
	 } 
	 void leftrotate(node* z)// left rotate
	   { 
	   	 node*y;
	     y=z->right;
	     z->right=y->left;
	     if(y->left!=nil)
	        y->left->parent=z;
	     y->parent=z->parent;
		 if(z->parent==nil)
			root=y;
		 else if(z==z->parent->left)
			z->parent->left=y;  
		 else
			z->parent->right=y;  
		 y->left=z;
		 z->parent=y;	  	     
	   }
	   
	
	   void rightrotate(node* z)// right rotate
	   { node*y;
	     y=z->left;
	     z->left=y->right;
	     if(y->right!=nil)
	        y->right->parent=z;
	     y->parent=z->parent;
		 if(z->parent==nil)
			root=y;
		 else if(z==z->parent->right)
			z->parent->right=y;  
		 else
			z->parent->left=y;  
		 y->right=z;
		 z->parent=y;	 
	   }
	   
	   void insertfixup(node* z)
	   { node *y;
	   while(z->parent->color=='r')
	       {
			   if(z->parent==z->parent->parent->left)
				{
				   y=z->parent->parent->right;
				   if(y->color=='r')//uncle is red-y
				    { z->parent->parent->color='r';
				      z->parent->color=y->color='b';
				      z=z->parent->parent;
				    }
				   else//uncle is black-y				    
				    { if(z==z->parent->right)
				         {
				         	z=z->parent;
				         	leftrotate(z);
						 }
				      //else
					     {
					     	z->parent->color='b';
						 	z->parent->parent->color='r';
						 	rightrotate(z->parent->parent);
						 	//z=root;
						 }   
					 }  
			    }   
	            else			
				{y=z->parent->parent->left;
				   if(y->color=='r')//uncle is red-y
				    { z->parent->parent->color='r';
				      z->parent->color=y->color='b';
				      z=z->parent->parent;
				    }
				   else//uncle is black-y				    
				    { if(z==z->parent->left)
				         {
				         	z=z->parent;
				         	rightrotate(z);
						 }
				      //else
					     {
					     	z->parent->color='b';
							z->parent->parent->color='r';
						 	leftrotate(z->parent->parent);
						 	//z=root;
						 }   
					}  
			    }
			}
				root->color='b';   
		} 
		
	   void insert (node *z)
	   { node* x,*y;
	     y=nil;
	     x=root;
	      while(x!=nil)  //position 
	      { y=x;
	        if(z->data<x->data)
		    x=x->left; 
			else
			x=x->right; 
  	      }
  	     z->parent=y;
		  if(y==nil)
		    root=z;  
		  else if(z->data<y->data)
		    y->left=z;
		  else
		    y->right=z;
		    
		  z->left=z->right=nil;
		  z->color='r';
		  insertfixup(z);
	   }
	   
	   /*int search(int n)  //this function is not working
	   {  
	   		node *temp=root;
	   		while(temp!=nil)
	   		{
	   			if(temp->data==n)
	   				return 0;
	   			else if(temp->data<n)
	   				temp=temp->left;
	   			 else
	   				temp=temp->right;
			}
			return -1;
	   }
	   */
	   	node* search(int el)
	{   int f=0;
		if(root)
		{   
			node *curr=root;
			while(curr)
			{
				if(el==curr->data)
				{
					
				
					return curr;
				}
				if(el<=curr->data)
					curr=curr->left;
				else curr=curr->right;
			}
		}
		
			return nil;
	}
	   node * tree_successor(node* z)  
	   { node* temp=z->right;
	    while(temp->left!=nil)
	     temp=temp->left;
	     return temp;
	   }
//	   node * tree_successor(node* z)  
//	   { node* temp=z;
//	    while(temp->left!=nil)
//	     temp=temp->left;
//	     return temp;
//	   }
	
	   void delete_fixup(node *x)
	   {
	   		while(x!=root&&x->color=='b')
	   		{
	   			node *y;
	   		if(x==x->parent->left)
	   		{
	   			y=x->parent->right;//sibling
	   			if(y->color=='r')
	   			{
	   				y->color='b';
	   				x->parent->color='r';
	   				leftrotate(x->parent);
	   				y=x->parent->right;
				}
				if(y->left->color=='b'&&y->right->color=='b')
				{
					y->color='r';
					x=x->parent;
				}
				else 
				{
					if(y->right->color=='b')
					{
						y->left->color='b';
						y->color='r';
						rightrotate(y);
						y=x->parent->right;
					}
					y->color=x->parent->color;
					x->parent->color='b';
					y->right->color='b';
					leftrotate(x->parent);
					x=root;
				}
			}
			else
			{
				y=x->parent->left;
	   			if(y->color=='r')
	   			{
	   				y->color='b';
	   				x->parent->color='r';
	   				rightrotate(x->parent);
	   				y=x->parent->left;
				}
				if(y->left->color=='b'&&y->right->color=='b')
				{
					y->color='r';
					x=x->parent;
				}
				else 
				{
					if(y->left->color=='b')
					{
						y->right->color='b';
						y->color='r';
						leftrotate(y);
						y=x->parent->left;
					}
					y->color=x->parent->color;
					x->parent->color='b';
					y->left->color='b';
					rightrotate(x->parent);
					x=root;
				}
			}
			}
			x->color='b';
	   }
	   
	   void rb_delete(int del)
	   { 	node *z=search(del);
	   		node *y,*x;
	   	 if(z->left==nil || z->right==nil)
	       y=z;
	     else
		   y=tree_successor(z);
		 if(z->left!=nil)
		   x=y->left;
		 else
		   x=y->right;
		 x->parent=y->parent;
		 if(y->parent==nil)
		   root=x;//initially root=x was written here
		 else if(y==y->parent->left)
		   y->parent->left=x;
		 else
		   y->parent->right=x;
		 if(y!=z)
		   z->data=y->data;
		   cout<<"\n\n\n\n";
		   
		 if(y->color=='b')
		   delete_fixup(x);                 
	   }
	  
	   	 
	   
	   void display(node *ptr,int space=0)
	   {
	   	if(!ptr)
	   	return;
	   	space++;
	   	display(ptr->right,space);
	   	for(int i=1;i<space;i++)
	   	cout<<" 		";
	   	cout<<ptr->color<<" "<<ptr->data<<"\n";
	   	display(ptr->left,space);
	   }
	   void root_cover()
	   {
	   	display(root);
	   }
};
int main()
{rbt ob;
 cout<<"enter the number of elements:";
 int n,val,choice;
 cin>>n;
 for(int i=0;i<n;i++)
 {
 	cout<<"enter the value:";
 	cin>>val;
 	node *a= new node(val);	
 	ob.insert(a);
  }
  cout<<"red-black tree\n";
  ob.root_cover();
  cout<<"\n---------------MAIN MENU------------------\n "
  	  <<"1) SEARCH A NODE       "
  	  <<"2) DELETE A NODE\n"
  	  <<"ENTER YOUR CHOICE";
  cin>>choice;
  switch(choice)
  {
  	case 1:{
  				cout<<"\nenter the number to be searched\n";
				cin>>val;
				/*
				if(ob.search(val)==0)
  				cout<<"found!!";
  				else
  				cout<<"not found!!";
  				*/
  				node *check=ob.search(val);
  				if(check->data!=-1)
  				cout<<"found";
  				else 
  				cout<<"not found";
		break;
	  }
	case 2:{
			cout<<"ENTER THE NODE TO BE DELETED: ";
			cin>>val;
			ob.rb_delete(val);
			cout<<endl;
			ob.root_cover();
		break;
	}
  }
  return 0;
}

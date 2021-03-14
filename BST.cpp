#include<iostream>
#include<conio.h>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
	
	public:
		node(int data1=0,node* l=0,node* r=0){
			data=data1;
			left=l;
			right=r;
		}
};
class Bst{
	public:
	node *root;
	public:
		Bst(){
			root=0;
		}
		
	void Insert(int val){
		node *curr,*prev=0;
		curr=root;
		while(curr)
		{
			prev=curr;
			if(val<=curr->data)
			curr=curr->left;
			else
			curr=curr->right;
		}
		if(prev){
			if(val<=prev->data)
			prev->left=new node(val);
			else
			prev->right=new node(val);
		}
		else
		root=new node(val);
		}
	
	bool search(int val){
		node* curr;
		curr=root;
		while(curr){
			if(val==curr->data)
			return true;
			else
			{
				if(val<curr->data)
				curr=curr->left;
				else
				curr=curr->right;
			}
		}
		return false;
	}
	void visit(node *p){
		cout<<p->data;
	}
	void inorder(node *p){
		if(p)
		{
			inorder(p->left);
			visit(p);
			inorder(p->right);
		}
	}
	
	
	void Preorder(node *p){
		if(p)
		{   visit(p);
			preorder(p->left);
			preorder(p->right);
		}
	}
	
	void Postorder(node *p){
		if(p)
		{   
			postorder(p->left);
			postorder(p->right);
			visit(p);
		}
	}

};
int main()
{   Bst ob;
    int n,i,s,s1;
	char ch='y';
	do{
	cout<<"*****BST*****\n";
	cout<<"1 : Insert element \n";
	cout<<"2 : Search an element \n";
	cout<<"3 : Inorder \n";
	cout<<"4 : Preorder \n";
	cout<<"5 : Postorder \n";
	
	cin>>n;
	switch(n){
		case 1:cout<<"Enter a number : ";
		       cin>>i;
			   ob.Insert(i);
		       break;
		case 2:cout<<"Enter a number that you search : ";
		cin>>s1;
		s=ob.search(s1);
		if(s==1)
		cout<<"Found\n";
		else
		cout<<"Not found\n";
		       break;
		
		case 3:ob.inorder(ob.root);
		      break;
		case 4:ob.Preorder(ob.root);
		      break;
		case 5:ob.Postorder(ob.root);
		      break;	        
		default: cout<<"Wrong choice";
	}
	
		cout<<"you want to enter more choice (y : yes / n : no)\n";
		cin>>ch;
	}while(ch=='y');
}

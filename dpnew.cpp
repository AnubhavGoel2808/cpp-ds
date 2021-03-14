#include<iostream>
using namespace std;
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;	
} 
int isSum(int set[], int n, int sum) 
{ 
	int opt[n+1][sum+1]; 
	for (int i = 0; i <= n; i++) 
	opt[i][0] = 0; 
	for (int i = 1; i <= sum; i++) 
	opt[0][i] = 0;
	for (int i = 1; i <= n; i++)     
	{ 
	for (int j = 1; j <= sum; j++) 
	{ 
		if(j<set[i-1]) 
		opt[i][j] = opt[i-1][j]; 
		if (j >= set[i-1]) 
		opt[i][j] = max(opt[i-1][j],(set[i-1]+opt[i - 1][j-set[i-1]])); 
	} 
	} 
	for (int i = 0; i <= n; i++) 
	{ 
	for (int j = 0; j <= sum; j++) 
		cout<<opt[i][j]<<"		"; 
	cout<<"\n"; 
	}
	return opt[n][sum]; 
}      

 
int main() 
{ 
int *set; 
int sum ; 
int n ;
cout<<"ENTER THE NUMBER OF ELEMENTS\t";
cin>>n;
set=new int[n];
cout<<"enter elements\n";
for(int i=0;i<n;i++){
	cin>>set[i];
}
cout<<"\nenter desired sum";
cin>>sum;
if (isSum(set, n, sum)==sum) 
	cout<<"Found a subset with given sum"; 
else
	cout<<"No subset with given sum"; 
return 0; 
} 

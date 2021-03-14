#include<iostream>
using namespace std;

bool calc(int arr[],int n,int sum){
	bool dp[n+1][sum+1];
	for(int i=0;i<n+1;i++)
		dp[i][0]=true;
	for(int i=1;i<sum+1;i++)
		dp[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<arr[i-1])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
		}
	}
	return dp[n][sum];
}

int main(){
	int n;
	cout<<"Enter number of elements  : ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements :\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the sum you want to search for : ";
	int sum;
	cin>>sum;
	if(calc(arr,n,sum))
		cout<<"Yes"<<calc(arr,n,sum);
		
	else
		cout<<"No";
	return 0;
}

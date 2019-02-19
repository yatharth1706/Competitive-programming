/*
	Problem:----------------------------
	You are given a  N*M matrix. You need to print the sum of 
	all the numbers in the rectangle which has (1,1) as the top left corner and  (x,y) as the bottom right corner.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int arr[n][m],dp[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	// dp solution
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=arr[0][0];
	for(int i=1;i<n;i++){
		dp[i][0]=arr[i][0]+dp[i-1][0];
	}
	
	for(int j=1;j<m;j++){
		dp[0][j]=arr[0][j]+dp[0][j-1];
	}
	

//	final step
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])+arr[i][j];	
		}			
	}
	
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x-1][y-1]<<'\n';
	}	 	   
    
    return 0;
}

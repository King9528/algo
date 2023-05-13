#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int KnapSack(int dp[][9],int wt[],int val[],int W,int n)
{
	
	if(n<0){
		return 0;
	}
    if(dp[n][W]!=-1)
	{
		return dp[n][W];
	}
    if(wt[n-1]>W)
	{
		dp[n][W]=KnapSack(dp,wt,val,W,n-1);
		return dp[n][W];
	}
	else 
	{
		dp[n][W]=max(val[n-1]+KnapSack(dp,wt,val,W-wt[n-1],n-1),KnapSack(dp,wt,val,W,n-1));
		return dp[n][W];
	}
}
int main()
{
	int n,W;
	cout<<"Enter the number of elements:";
	cout<<endl;
	cin>>n;
	cout<<"Enter the Weight of the Knapsack:";
	cin>>W;
	cout<<"Enter the Weight:"<<endl;
	int wt[n],val[n];
	int dp[4][9];
	//dp=new int *[n+1];
	//for(int i=0;i<=n;i++)
	//dp[i]=new int[W+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"Enter the value:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int result=KnapSack(dp,wt,val,W,n);
	cout<<"the max Profit is:"<<result<<endl;
	return 0;
}

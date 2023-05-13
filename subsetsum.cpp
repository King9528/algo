#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int subset(int dp[][9],int wt[],int W,int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;++j)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else if(wt[i-1]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else if (wt[i-1]<=j)
			{
				dp[i][j]=max(dp[i-1][j],wt[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	}
	return dp[n][W];
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
	int wt[n];
	int dp[5][9];
	//dp=new int *[n+1];
	//for(int i=0;i<=n;i++)
	//dp[i]=new int[W+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	int result=subset(dp,wt,W,n);
	cout<<"the max sum is:"<<result<<endl;
	return 0;
}

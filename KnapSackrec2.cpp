#include <iostream>
using namespace std;

int knapSackRec(int W, int wt[], int val[], int i, int** dp)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		// Store value in a table before return
		dp[i][W] = max(val[i]+ knapSackRec(W - wt[i], wt, val,i - 1, dp),knapSackRec(W, wt, val, i - 1, dp));

		return dp[i][W];
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	int** dp;
	dp = new int*[n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}


int main()
{
	int profit[] = { 5,10,2 };
	int weight[] = { 100,50,80};
	int W = 8;
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(W, weight, profit, n);
	return 0;
}

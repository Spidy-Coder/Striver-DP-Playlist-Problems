//APPROACH:-2:-Memoization

#include<bits/stdc++.h>
int f(int i, int prev, int arr[], int n, vector<vector<int>> &dp){
    if(i == n) return 0;
    if(dp[i][prev]);
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    int len = 0 + f(i+1, prev, arr,n,dp);
    if(prev == -1 || arr[i] > arr[prev]){
        len = max(len, 1 + f(i+1,i,arr,n,dp));
    }
    return dp[i][prev+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}

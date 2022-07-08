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

//APPROACH:-3:- TABULATION

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
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int prev=i-1;prev>=-1;prev--){
            //copy the recurrence part
            int len = 0 + dp[i+1][prev+1];
            if(prev == -1 || arr[i] > arr[prev]){
                len = max(len, 1 + dp[i+1][i+1]);
            }
            dp[i][prev+1] = len;
        }
    }
    return dp[0][-1+1];
}

//---------------------------------------------------------------------------------

//APPROACH:-4:- BINARY SEARCH

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i=1;i<n;i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp;
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

//------------------------------------------------------

//APPROACH:-5:- ALGORITHM

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], 1+dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}





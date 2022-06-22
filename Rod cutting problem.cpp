//APPROACH:-1:- Memoization

int f(int i,int n, vector<int>&price, vector<vector<int>>&dp){
    if(i==0){
        return n*price[0];
    }
    if(dp[i][n] != -1) return dp[i][n];
    int notTake = 0 + f(i-1,n,price,dp);
    int take = INT_MIN;
    int rodlength = i+1;
    if(rodlength <= n) take = price[i] + f(i,n-rodlength,price,dp);
    return dp[i][n] = max(notTake,take);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(n-1,n,price,dp);
}

//-----------------------------------------------------------------------------

//APPROACH:-2:- Tabulation


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,0));
    for(int N = 0;N<=n;N++) dp[0][N] = N*price[0];
    
    for(int i=1;i<n;i++){
        for(int N=0;N<=n;N++){
            int notTake = 0 + dp[i-1][N];
            int take = INT_MIN;
            int rodlength = i+1;
            if(rodlength <= N) take = price[i] + dp[i][N-rodlength];
            dp[i][N] = max(notTake,take);
        }
    }
    
    return dp[n-1][n];
}


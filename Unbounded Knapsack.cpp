//APPROACH:-1:- Memoization

int f(int i, int w, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
    if(i==0){
        return ((w/wt[0])*val[0]);
    }
    if(dp[i][w] != -1) return dp[i][w];
    int notTake = f(i-1,w,val,wt,dp);
    int take = 0;
    if(wt[i] <= w) take = val[i] + f(i,w-wt[i],val,wt,dp);
    return dp[i][w]=max(notTake,take);
}



int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return f(n-1,w,val,wt,dp);
}

//-----------------------------------------------------------------------------------

//APPROACH:-2:- Tabulation

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i] = ((int)(i/wt[0])) * val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int W = 0; W<=w ; W++){
            int notTake = 0+dp[i-1][W];
            int take = 0;
            if(wt[i] <= W)take = val[i] + dp[i][W-wt[i]];
            dp[i][W] = max(take, notTake);
        }
    }
    
    return dp[n-1][w];
}

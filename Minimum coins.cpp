//Approach :-1 Memoization

int f(int i, int t, vector<int>&nums, vector<vector<int>>&dp){
    if(i == 0){
        if(t%nums[i] == 0) return t/nums[i];
        return 1e9;
    }
    if(dp[i][t] != -1) return dp[i][t];
    int notTake = 0 + f(i-1,t,nums,dp);
    int take = INT_MAX;
    if(nums[i] <= t){
        take = 1 + f(i,t-nums[i],nums,dp);
    }
    return dp[i][t] = min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1,-1));
    int ans = f(n-1,x,num,dp);
    if(ans >= 1e9) return -1;
    return ans;
}

//------------------------------------------------------

//Approach:- 2:- Tabulation

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1,0));
    for(int t=0; t<=x;t++){
        if(t%num[0] == 0) dp[0][t] = t/num[0];
        else dp[0][t] = 1e9; 
    }
    
    for(int i=1;i<n;i++){
        for(int t=0;t<=x;t++){
            int notTake = 0 + dp[i-1][t];
            int take = INT_MAX;
            if(num[i] <= t){
                take = 1 + dp[i][t-num[i]];
            }
            dp[i][t] = min(take, notTake);
        }
    }
                
    int ans = dp[n-1][x];
    if(ans >= 1e9) return -1;
    return ans;
}

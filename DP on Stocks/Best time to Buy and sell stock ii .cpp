//APPROACH:-3:- Tabulation

#include<bits/stdc++.h>

//Memoization approach here
/*long f(int i, int buy, long *values, int n, vector<vector<long>> &dp){
    if(i == n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    long profit = 0;
    if(buy){
        profit = max(-values[i] + f(i+1,0,values,n,dp),
                    0 + f(i+1,1,values,n,dp));
    }
    
    else{
        profit = max(values[i] + f(i+1,1,values,n,dp),
                    0 + f(i+1,0,values,n,dp));
    }
    
    return dp[i][buy] = profit;
}*/

//Tabulation Approach here
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n+1, vector<long>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            //copy the recurrence part
            long profit = 0;
            if(buy){
                profit = max(-values[i] + dp[i+1][0],
                            0 + dp[i+1][1]);
            }

            else{
                profit = max(values[i] + dp[i+1][1],
                            0 + dp[i+1][0]);
            }

            dp[i][buy] = profit;
            
        }
    }
    
    return dp[0][1];
}

//--------------------------------------------------------------

//APPROACH:-4:- Space Optimization

long getMaximumProfit(long *values, int n)
{
    vector<long> ahead(2,0), cur(2,0);
    ahead[0] = ahead[1] = 0;
    
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            //copy the recurrence part
            long profit = 0;
            if(buy){
                profit = max(-values[i] + ahead[0],
                            0 + ahead[1]);
            }

            else{
                profit = max(values[i] + ahead[1],
                            0 + ahead[0]);
            }

            cur[buy] = profit;
            
        }
        
        ahead = cur;
    }
    
    return ahead[1];
}

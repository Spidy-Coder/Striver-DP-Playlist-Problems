//Approach:-1:- Memoization

int f(vector<int> &a, int s, vector<vector<int>>&dp,int i )
{
	//Base Cases
	if(s == 0) return 1;
	if(i == 0) return (a[0]==s);
	if(dp[i][s] != -1) return dp[i][s];
	
	//Explore all possible cases of recurrence
	int not_pick = f(a,s,dp,i-1);
	int pick = 0;
	if(a[i] <= s) pick=f(a,s-a[i],dp,i-1);
	
	//return count
	return dp[i][s] = pick + not_pick;
}

int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(tar+1,-1));
	return f(num,tar,dp,n-1);
    
}

//Approach:-2:- Tabulation

int findWays(vector<int> &num, int tar)
{
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(tar+1,0));
	for(int i=0;i<n;i++) dp[i][0] = 1; 
	if(num[0]<=tar) dp[0][num[0]] = 1;
	for(int i=1;i<n;i++){
		for(int sum=0;sum<=tar;sum++){
			int not_pick = dp[i-1][sum];
			int pick = 0;
			if(num[i] <= tar) pick=dp[i-1][sum - num[i]];
			dp[i][sum] = pick+not_pick;
		}
	}
	
	return dp[n-1][tar];
    
}

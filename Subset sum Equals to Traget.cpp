//Approach:-1 Recursion

//Approach:-2 Memoization --->
bool f(int n, int k, vector<int>&a, int i,vector<vector<int>>&dp){
	//base cases
	if(i == 0){
		return (a[i] == k);
	}
	if(a[i] == k) return true;
	if(k == 0) return true;
	if(dp[i][k] != -1) return dp[i][k];
	//recurrence part
	bool not_pick = f(n,k,a,i-1,dp);
	bool pick = false;
	if(k >= a[i]){
		pick = f(n,k-a[i],a,i-1,dp);
	}
	
	return dp[i][k] = pick | not_pick ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n, vector<int>(k+1,-1));
	return f(n,k,arr,n-1,dp);
	
}

//Approach:-3 Tabulation --->


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n, vector<bool>(k+1,0));
	for(int i=0;i<n;i++) dp[i][0] = true;
	dp[0][arr[0]] = true;
	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=k;target++){
			bool not_take = dp[ind-1][target];
			bool take = false;
			if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
			dp[ind][target] = take | not_take;
				
		}
	}
	
	return dp[n-1][k];
	
}



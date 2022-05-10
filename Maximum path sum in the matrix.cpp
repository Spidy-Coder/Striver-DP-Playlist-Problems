//Recursion :- Approach 1

int f(int i,int j, vector<vector<int>> &matrix){
	if(j<0 || j>=matrix[0].size()) return -1e8; //base cases
	if(i==0) return matrix[0][j];
	
	int s = matrix[i][j] + f(i-1,j,matrix);
	int ld = matrix[i][j] + f(i-1,j-1,matrix);
	int rd = matrix[i][j] + f(i-1,j+1,matrix); //since we are doing (n-1) -> 0 in indexing of i
	return max(s,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //size of rows
	int m = matrix[0].size(); //size of columns
	int maxi = -1e8;
	for(int j=0;j<m;j++){
		maxi = max(maxi,f(n-1,j,matrix)); //for loop is used here for the maximum of all the matrix condition given in the problem statement
	}
	
	return maxi;
	
	
}

//Approach :- 2:- Memoizzation

int f(int i,int j, vector<vector<int>> &matrix,vector<vector<int>> &dp){
	if(j<0 || j>=matrix[0].size()) return -1e8; //base cases
	if(i==0) return matrix[0][j];
	if(dp[i][j] != -1) return dp[i][j];
	int s = matrix[i][j] + f(i-1,j,matrix,dp);
	int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
	int rd = matrix[i][j] + f(i-1,j+1,matrix,dp); //since we are doing (n-1) -> 0 in indexing of i
	return dp[i][j] = max(s,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //size of rows
	int m = matrix[0].size(); //size of columns
	vector<vector<int>>dp(n, vector<int>(m,-1));
	int maxi = -1e8;
	for(int j=0;j<m;j++){
		maxi = max(maxi,f(n-1,j,matrix,dp)); //for loop is used here for the maximum of all the matrix condition given in the problem statement
	}
	
	return maxi;
	
	
}

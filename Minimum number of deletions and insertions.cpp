// Memoization
class Solution{
	public:
// 	int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
// 	{
// 	    // base case
// 	    if(i<0 and j<0)
// 	    return 0;
	    
// 	    if(i<0)
// 	    return j+1;
	    
// 	    if(j<0)
// 	    return i+1;
	    
// 	    // memo check
// 	    if(memo[i][j]!=-1)
// 	    return memo[i][j];
	    
// 	    // recursive calls
// 	    // and small calculation
// 	    if(s1[i]==s2[j])
// 	    return memo[i][j]=help(s1,s2,i-1,j-1,memo);
	    
// 	    int a=1+help(s1,s2,i-1,j,memo);
// 	    int b=2+help(s1,s2,i-1,j-1,memo);

// 	    return memo[i][j]=min({a,b});
// 	}
	int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &memo) {
        
        // base case
        if(i<0 or j<0)
        return 0;
        
        // memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        // recusive calls
        // and small calculation
        if(s1[i]==s2[j])
        return memo[i][j]=1+lcs(s1,s2,i-1,j-1,memo);
        
        int a=lcs(s1,s2,i-1,j,memo);
        int b=lcs(s1,s2,i,j-1,memo);
        
        return memo[i][j]=max(a,b);
    }
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.length();
	    int m=str2.length();
	    
	    vector<vector<int>> memo(n,vector<int>(m,-1));
	    int len=lcs(str1,str2,n-1,m-1,memo);
	    
	    int lenLCS = lcs(str1, str2, n-1, m-1, memo);
        return (n - lenLCS) + (m - lenLCS);
	} 
};

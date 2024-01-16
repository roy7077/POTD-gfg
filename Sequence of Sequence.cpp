MEMOIZATION
class Solution{
    public:
    int help(int n,int m,int i,vector<vector<int>>& memo)
    {
        //base case
        if(n==0)
        return 1;
        
        if(i>m)
        return 0;
        
        //memo check
        if(memo[n][i]!=-1)
        return memo[n][i];
        
        //recursive calls
        //small calculation
        int cnt=0;
        for(int j=i;j<=m;j++)
        cnt+=help(n-1,m,j*2,memo);
        
        return memo[n][i]=cnt;
    }
    int numberSequence(int m, int n){
        
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int ans=help(n,m,1,memo);
        return ans;
    }
};
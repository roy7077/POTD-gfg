class Solution {
    public:
    bool help(string& pattern,string& str,int i,int j,vector<vector<int>>& memo)
    {
        // base case
        if(i>=pattern.length() and j>=str.length())
        return 1;
        
        if(i>=pattern.length())
        return 0;
        
        if(j>=str.length() and (pattern[i]=='?' or (pattern[i]>='a' and pattern[i]<='z')))
        return 0;
        
        // memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        // recursive calls
        // and small calculation
        if(pattern[i]=='*')
        {
            bool notTake=help(pattern,str,i+1,j,memo);
            if(notTake)
            return memo[i][j]=1;
            
            for(int k=j;k<str.length();k++)
            {
                bool fnCall=help(pattern,str,i+1,k+1,memo);
                if(fnCall)
                return memo[i][j]=1;
            }
            return memo[i][j]=0;
        }
        
        if(pattern[i]==str[j] or pattern[i]=='?')
        return memo[i][j]=int(help(pattern,str,i+1,j+1,memo));
        
        return memo[i][j]=0;
    }
    
    int wildCard(string pattern, string str) {
        int n=pattern.length();
        int m=str.length();
        
        vector<vector<int>> memo(n+5,vector<int>(m+5,-1));
        return help(pattern,str,0,0,memo);
    }
};


// hyfmh*fm*y*
// hyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmhyfmv

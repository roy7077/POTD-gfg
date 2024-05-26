// Memoization
class Solution {
    public:
    int help(string& s1,string& s2,int i,int j,int& costX,int& costY,vector<vector<int>>& memo)
    {
        //base case
        if(i==s1.length() and j==s2.length())
        return 0;
       
        // memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        if(s1[i]==s2[j])
        return memo[i][j]=help(s1,s2,i+1,j+1,costX,costY,memo);
        
        int a=1e9;
        int b=1e9;
        
        if(i<s1.length())
        a=costX+help(s1,s2,i+1,j,costX,costY,memo);
        
        if(j<s2.length())
        b=costY+help(s1,s2,i,j+1,costX,costY,memo);
        
        return memo[i][j]=min(a,b);
    }
    int findMinCost(string x, string y, int costX, int costY) {
        vector<vector<int>> memo(x.length()+1,vector<int>(y.length()+1,-1));
        return help(x,y,0,0,costX,costY,memo);
    }
};
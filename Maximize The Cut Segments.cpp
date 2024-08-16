// memoization
class Solution
{
    public:
    int help(int n,vector<int>& v,vector<int>& memo)
    {
        // base case
        if(n==0)
        return -1e9;
        
        if(n<0)
        return -1e9;
        
        // memo check
        if(memo[n]!=-1)
        return memo[n];
        
        // recursive calls
        // and small calculation
        int maxi=-1e9;
        for(auto& it:v)
        {
            if(it==n)
            maxi=max(maxi,1);
            else if(it<n)
            {
                int a=help(it,v,memo);
                int b=help(n-it,v,memo);
                maxi=max(maxi,a+b);
            }
        }
        return memo[n]=maxi;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> memo(n+1,-1);
        vector<int> v={x,y,z};
        int ans=help(n,v,memo);
        
        return ans<=-1 ? 0:ans;
    }
};

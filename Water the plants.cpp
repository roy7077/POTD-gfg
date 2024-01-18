/*---DP  &&  ITERATIVE  APPROACHES-----*/

//RECURSION (TLE)
class Solution{
    public:
    int help(int* g,int i,int& n,int cnt)
    {
        //base case
        if(i>=n)
        {
            if(cnt>=1)
            return 1e9;
            else
            return 0;
        }
        
        //recursive calls
        //small calculation
        if(g[i]==-1)
        return help(g,i+1,n,cnt+1);
        
        int a,b;
        a=b=1e9;
        
        a=help(g,i+1,n,cnt+1);
        
        if(g[i]>=cnt)
        b=1+help(g,i+g[i]+1,n,0);
        
        return min(a,b);
    }
    int min_sprinklers(int gallery[], int n)
    {
        int ans=help(gallery,0,n,0);
        if(ans>=1e9)
        return -1;
        else
        return ans;
    }
};

//MEMOIZATION (TLE)
class Solution{
    public:
    int help(int* g,int i,int& n,int cnt,vector<vector<int>>& memo)
    {
        //base case
        if(i>=n)
        {
            if(cnt>=1)
            return 1e9;
            else
            return 0;
        }
        
        //memo check
        if(memo[i][cnt]!=-1)
        return memo[i][cnt];
        
        //recursive calls
        //small calculation
        if(g[i]==-1)
        return memo[i][cnt]=help(g,i+1,n,cnt+1,memo);
        
        int a,b;
        a=b=1e9;
        
        a=help(g,i+1,n,cnt+1,memo);
        
        if(g[i]>=cnt)
        b=1+help(g,i+g[i]+1,n,0,memo);
        
        return memo[i][cnt]=min(a,b);
    }
    int min_sprinklers(int gallery[], int n)
    {
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        int ans=help(gallery,0,n,0,memo);
        
        return ans>=1e9 ? -1:ans;
    }
};

//TABULATION (TLE)
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=n;j++)
            {
                if(gallery[i]==-1)
                {
                    if(i+1<n)
                    dp[i][j]=dp[i+1][j+1];
                    else
                    dp[i][j]=1e9;
                    
                    continue;
                }
                int a,b;
                a=b=1e9;
                
                if(i+1<n)
                a=dp[i+1][j+1];
                
                if(gallery[i]>=j)
                {
                    if((i+gallery[i]+1)<n)
                    b=1+dp[i+gallery[i]+1][0];
                    else
                    b=1;
                }
                
                dp[i][j]=min(a,b);
            }
        }
        
        return dp[0][0]>=1e9 ? -1:dp[0][0];
    }
};

//ITERATIVE (ACCEPTED)
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> spk;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            spk.push_back({ max(0, i-gallery[i]), min(n-1, i+gallery[i])});
        }
        
        sort(spk.begin(),spk.end());
        
        
        int start=0;
        int i=0;
        int ans=0;
        
        while(start<n)
        {
            int maxr=-1e9;
            while(i<spk.size())
            {
                if(spk[i].first>start)
                break;
                
                maxr=max(maxr,spk[i].second);
                i++;
            }
            
            if(maxr<start)
            return -1;
            
            ans++;
            start=maxr+1;
        }
        
        return ans;
    }
};
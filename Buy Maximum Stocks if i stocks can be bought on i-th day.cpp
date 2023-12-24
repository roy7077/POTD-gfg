/*-----------ALL  POSSIBLE  AAPROACHES-----------*/

/*-----------SORTING - 1------------*/
// Time complexity - O(NlogN)
// Space complexity- O(N*2)
class Solution {
    public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first<b.first)
        return 1;
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        else
        return 0;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({price[i],i+1});
        
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(auto it:v)
        {
            int p=it.first;
            int num=it.second;
            
            int xx=k/p;
            if(xx>num)
            {
                ans+=num;
                k-=(num*p);
            }
            else
            {
                ans+=xx;
                k-=(xx*p);
            }
        }
        return ans;
    }
};

/*---------------SORTING - 2---------------*/
// Time complexity - O(N^2)
// Space complexity- O(N*2)

class Solution {
    public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first<b.first)
        return 1;
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        else
        return 0;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({price[i],i+1});
        
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(auto it:v)
        {
            int p=it.first;
            int num=it.second;
            while(k>0 and num)
            {
                if(k<p)
                break;
                
                ans++;
                k-=p;
                num--;
            }
        }
        return ans;
    }
};

/*------------DYNAMMIC PROGRAMMING---------------*/

/*-------------RECURSION (TLE)------------*/
class Solution {
    public:
    int help(int* price,int n,int i,int k)
    {
        //base case
        if(i>=n)
        return 0;
        
        //recursive calls
        //small calculation
        int maxi=0;
        for(int j=0;j<=(i+1);j++)
        {
            int ans=0;
            if(k>=(j*price[i]))
            {
                ans=j+help(price,n,i+1,k-(j*price[i]));
                maxi=max(maxi,ans);
            }
            else
            return maxi;
            
        }
        return maxi;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        int ans=help(price,n,0,k);
        return ans;
    }
};

/*-------------MEMOIZATION (TLE)--------------*/
class Solution {
    public:
    int help(int* price,int n,int i,int k,vector<vector<int>>& memo)
    {
        //base case
        if(i>=n)
        return 0;
        
        //memo check
        if(memo[i][k]!=-1)
        return memo[i][k];
        
        //recursive calls
        //small calculation
        int maxi=0;
        for(int j=0;j<=(i+1);j++)
        {
            int ans=0;
            if(k>=(j*price[i]))
            {
                ans=j+help(price,n,i+1,k-(j*price[i]),memo);
                maxi=max(maxi,ans);
            }
            else
            return memo[i][k]=maxi;
        }
        return memo[i][k]=maxi;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        
        vector<vector<int>> memo(n,vector<int>(k+1,-1));
        int ans=help(price,n,0,k,memo);
        return ans;
    }
};

/*------------------TABULATION (TLE)-------------*/
class Solution {
    public:
    int buyMaximumProducts(int n, int k, int price[]){
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                int maxi=0;
                for(int l=0;l<=(i+1);l++)
                {
                    if(j>=(l*price[i]))
                    {
                        int ans=l+dp[i+1][j-(l*price[i])];
                        maxi=max(maxi,ans);
                    }
                }
                dp[i][j]=maxi;
            }
        }
        return dp[0][k];
    }
};

/*--------------SPACE OPTIMIZED (TLE)--------------*/
class Solution {
    public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<int> next(k+1,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(k+1,0);
            for(int j=0;j<=k;j++)
            {
                int maxi=0;
                for(int l=0;l<=(i+1);l++)
                {
                    if(j>=(l*price[i]))
                    {
                        int ans=l+next[j-(l*price[i])];
                        maxi=max(maxi,ans);
                    }
                }
                curr[j]=maxi;
            }
            next=curr;
        }
        return next[k];
    }
};
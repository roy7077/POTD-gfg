// Memoization 
class Solution {
    public:
    int help(vector<vector<int>>& books,int i,int& shelfWidth,vector<int>& memo)
    {
        // base case
        if(i>=books.size())
        return 0;
        
        // memo check
        if(memo[i]!=-1)
        return memo[i];
        
        // recursive calls
        // and small calculation
        int ans=1e9;
        int width=0;
        int maxHeight=0;
        for(int j=i;j<books.size();j++)
        {
            if(width+books[j][0]<=shelfWidth)
            {
                width+=books[j][0];
                maxHeight=max(maxHeight,books[j][1]);
                int temp=help(books,j+1,shelfWidth,memo);
                ans=min(ans,temp+maxHeight);
            }
            else
            break;
        }
        
        return memo[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> memo(books.size(),-1);
        return help(books,0,shelfWidth,memo);
    }
};



// Tabulation 
class Solution {
    public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int ans=1e9;
            int width=0;
            int maxHeight=0;
            for(int j=i;j<n;j++)
            {
                if(width+books[j][0]<=shelfWidth)
                {
                    width+=books[j][0];
                    maxHeight=max(maxHeight,books[j][1]);

                    if(j+1>n)
                    break;

                    int temp=dp[j+1];
                    ans=min(ans,temp+maxHeight);
                }
                else
                break;
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};

/*Can we solve this with greedy approach ?

At first glance, it might seem plausible. However, 
upon examining a specific test case, we can see that 
greediness doesn't always lead to the optimal solution.

Consider the test case where n=4 and the array is {8, 15, 3, 7}:

In the first case:

• The first person selects numbers 8 and 7, totaling 15.
• Then, the second person picks 15 and 3, which adds up to 18.

In the second case:

• The first person opts for 7 and 15, resulting in a total of 22.
• Meanwhile, the second person chooses 8 and 3, giving a total of 11.

hence , we can't solve it greedy
*/

// Recursion - TLE
// Time complexity - O(2^n)
#define ll long long
class Solution{
    public:
    ll help(int* arr,int i,int j)
    {
        //base case
        if(i>j)
        return 0;
    
        //recursive calls
        //and small calculation
        ll a=arr[i]+min(help(arr,i+2,j),help(arr,i+1,j-1));
        ll b=arr[j]+min(help(arr,i,j-2),help(arr,i+1,j-1));
        
        return max(a,b);
    }
    long long maximumAmount(int n, int arr[]){
        return help(arr,0,n-1);
    }
    
};

// Memoization
#define ll long long
class Solution{
    public:
    ll help(int* arr,int i,int j,vector<vector<ll>>& memo)
    {
        //base case
        if(i>j)
        return 0;
    
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        ll a=arr[i]+min(help(arr,i+2,j,memo),help(arr,i+1,j-1,memo));
        ll b=arr[j]+min(help(arr,i,j-2,memo),help(arr,i+1,j-1,memo));
        
        return memo[i][j]=max(a,b);
    }
    long long maximumAmount(int n, int arr[]){
        vector<vector<ll>> memo(n,vector<ll>(n,-1));
        return help(arr,0,n-1,memo);
    }
    
};


// Tabulation
#define ll long long
class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        vector<vector<ll>> dp(n,vector<ll>(n,0));
        
        //base case is - i>j mark all boxes equal to 0
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                //if i>j , it's a base case , make it 0
                if(i>j)
                {
                    dp[i][j]=0;
                    continue;
                }
                
                ll a=arr[i];
                ll b=arr[j];
                
                //1st case
                ll c=i+2<n? dp[i+2][j] : 0;
                ll d=(i+1<n) and (j-1>=0) ? dp[i+1][j-1] : 0;
            
                //2nd case
                ll e=j-2>=0 ? dp[i][j-2] : 0;
                ll f=(i+1<n) and (j-1>=0) ? dp[i+1][j-1] : 0;
        
                a+=min(c,d);
                b+=min(e,f);
                
                dp[i][j]=max(a,b);
            }
        }
        return dp[0][n-1];
    }
    
};
/*
Can we optimize Space ?

Yes, it's absolutely possible to optimize space usage 
for this problem. By ensuring we have access to two rows 
below the current row, we can efficiently compute values 
for dp[i+2][j] and dp[i+1][j-1]. This might sound a bit 
intricate to implement, but it's definitely achievable.

Here's the simplified idea: We need to keep track of 
information from the next row (dp[i+1]) and the row 
after that (dp[i+2]). By organizing our data in this way, 
we can streamline our computations.

Once we implement this approach, the time complexity will reduce 
to O(N*N), which is quite efficient. Additionally, the space complexity 
will be optimized to O(3*N), ensuring that we're using memory resources 
more effectively. So, while it may require a bit of effort to set up, 
the payoff in terms of performance and resource utilization makes it well 
worth the investment.
*/
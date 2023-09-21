// 😎 ALL  FOUR  APPROACHES  🔥
// RECURSION

// class Solution
// {
//     public:
//     int help(int* arr,int n,int i)
//     {
//         //base case
//         if(i<0)
//         return 0;
        
//         if(i==0)
//         return arr[0];
        
//         //recursive calls
//         int a=help(arr,n,i-1);
//         int b=arr[i]+help(arr,n,i-2);
        
//         return max(a,b);
//     }
//     int FindMaxSum(int arr[], int n)
//     {
//         return help(arr,n,n-1);
//     }
// };
// MEMOIZATION

// class Solution
// {
//     public:
//     int help(int* arr,int n,int i,vector<int>& memo)
//     {
//         //base case
//         if(i<0)
//         return 0;
        
//         if(i==0)
//         return arr[0];
        
//         //memo check
//         if(memo[i]!=-1)
//         return memo[i];
        
//         //recursive calls
//         int a=help(arr,n,i-1,memo);
//         int b=arr[i]+help(arr,n,i-2,memo);
        
//         return memo[i]=max(a,b);
//     }
//     int FindMaxSum(int arr[], int n)
//     {
//         vector<int> memo(n,-1);
//         return help(arr,n,n-1,memo);
//     }
// };
// TABULATION

// class Solution
// {
//     public:
//     int FindMaxSum(int arr[], int n)
//     {
//         vector<int> dp(n,0);
//         dp[0]=arr[0];
        
//         for(int i=1;i<n;i++)
//         {
//             int a,b;
//             a=b=0;
            
//             b=arr[i];
//             a=dp[i-1];
//             if(i-2>=0)
//             b+=dp[i-2];
            
//             dp[i]=max(a,b);
//         }
        
//         return dp[n-1];
//     }
// };
// SPACE OPTIMIZED

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if(n==1)
        return arr[0];
        
        int first;
        int second=arr[0];
        
        for(int i=1;i<n;i++)
        {
            int a,b;
            a=b=0;
            
            a=second;
            b=arr[i];
            if(i-2>=0)
            b+=first;
            
            int curr=max(a,b);
            first=second;
            second=curr;
        }
        
        return second;
    }
};
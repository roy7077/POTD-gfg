// ALL  POSSIBLE  APPROACHES || RESURSION || MEMOIZATION || TABULATION || OPTIMIZED


// RECURSION
class Solution{   
    public:
    
    int help(int i,int n)
    {
        //base case
        if(i>n)
        return 1e9;
        
        if(i==n)
        return 0;
        
        //recursive calls 
        //small calculation
        int a=help(i*3,n)+1;
        int b=help(i+1,n)+1;
        
        return min(a,b);
    }
    
    int minimumStep(int n){
        int ans=help(1,n);
        if(ans>=1e9)
        return 0;
        else
        return ans;
    }
};

// MEMOIZATION 
// Time complexity - O(N)
// Space complexity- O(N)
class Solution{   
    public:
    int help(int i,int n,vector<int>& memo)
    {
        //base case
        if(i>n)
        return 1e9;
        
        if(i==n)
        return 0;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls 
        //small calculation
        int a=help(i*3,n,memo)+1;
        int b=help(i+1,n,memo)+1;
        
        return memo[i]=min(a,b);
    }
    
    int minimumStep(int n){
        
        vector<int> memo(n+1,-1);
        int ans=help(1,n,memo);
        if(ans>=1e9)
        return 0;
        else
        return ans;
    }
};

// TABULATION
// Time complexity - O(N)
// Space complexity- O(N)
class Solution{   
    public:
    int minimumStep(int n){
        
        vector<int> memo(n+1,-1);
        memo[0]=memo[1]=0;
        memo[2]=memo[3]=1;
        
        for(int i=4;i<=n;i++)
        {
            if(i%3==0)
            memo[i]=memo[i/3]+1;
            else
            memo[i]=memo[i-1]+1;
        }
        
        return memo[n];
    }
};

// OPTIMIZED APPROACH
// Time complexity - O(logN)
// Space complexity- O(1)
class Solution{   
    public:
    int minimumStep(int n){
        
        int cnt=0;
        while(n!=1)
        {
            if(!(n%3))
            {
                cnt++;
                n/=3;
            }
            else
            {
                cnt++;
                n--;
            }
        }
        return cnt;
    }
};
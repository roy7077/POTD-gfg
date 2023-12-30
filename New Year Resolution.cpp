/*-----------RECURSION || MEMOIZATION-------------*/
//RECURSION
class Solution {
    public:
    bool help(int* coins,int i,int sum)
    {
        //base case
        if(i<0)
        {
            if(sum!=0 and (sum%20==0 or sum%24==0 or sum==2024))
            return 1;
            else
            return 0;
        }
        
        if(sum!=0 and (sum%20==0 or sum%24==0 or sum==2024))
        return 1;
        
        //recursive calls
        //small calculation
        bool a=help(coins,i-1,sum);
        if(a)
        return 1;
        
        bool b=help(coins,i-1,sum+coins[i]);
        return b;
    }
    
    int isPossible(int N , int coins[]) 
    {
        return help(coins,N-1,0);
    }
    
};

//MEMOIZATION
class Solution {
    public:
    bool help(int* coins,int i,int sum,vector<vector<int>>& memo)
    {
        //base case
        if(i<0)
        {
            if(sum!=0 and (sum%20==0 or sum%24==0 or sum==2024))
            return 1;
            else
            return 0;
        }
        
        //memo check
        if(memo[i][sum]!=-1)
        return memo[i][sum];
        
        if(sum!=0 and (sum%20==0 or sum%24==0 or sum==2024))
        return memo[i][sum]=1;
        
        //recursive calls
        //small calculation
        bool a=help(coins,i-1,sum,memo);
        if(a)
        return memo[i][sum]=1;
        
        bool b=help(coins,i-1,sum+coins[i],memo);
        return memo[i][sum]=int(b);
    }
    
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> memo(N,vector<int>(2025,-1));
        return help(coins,N-1,0,memo);
    }
    
};


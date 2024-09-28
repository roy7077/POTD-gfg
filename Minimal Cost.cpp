// Memoization
class Solution {
    public:
    int help(vector<int>& arr,int i,int k,vector<int>& memo)
    {
        // base case
        if(i==arr.size()-1)
        return 0;
        
        if(i>=arr.size())
        return 0;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        // recursive calls
        // and small calculation
        int mini=1e9;
        for(int j=i+1;j<=(i+k) and j<arr.size();j++)
        {
            int temp=abs(arr[i]-arr[j])+help(arr,j,k,memo);
            mini=min(temp,mini);
        }
        return memo[i]=mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int> memo(n,-1);
        return help(arr,0,k,memo);
    }
};

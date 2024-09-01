class Solution {
    public:
    int help(unordered_map<int,int>& mp1,unordered_map<int,int>& mp2,int i,int flag,vector<int>& arr1,vector<int>& arr2,vector<vector<int>>& memo)
    {
        // base case
        //cout<<"flag -> "<<flag<<" ind -> "<<i<<endl;
        if(flag and i>=mp1.size())
        return 0;
        
        if(!flag and i>=mp2.size())
        return 0;
        
        // memo check
        if(memo[i][flag]!=-1)
        return memo[i][flag];
        
        // recursive calls
        // and small calculation
        if(flag)
        {
            int a=arr1[i]+help(mp1,mp2,i+1,1,arr1,arr2,memo);
            int b=0;
            if(mp2.count(arr1[i]))
            b=arr1[i]+help(mp1,mp2,mp2[arr1[i]],0,arr1,arr2,memo);
            
            return memo[i][flag]=max(a,b);
        }
        else
        {
            int a=arr2[i]+help(mp1,mp2,i+1,0,arr1,arr2,memo);
            int b=0;
            if(mp1.count(arr2[i]))
            b=arr2[i]+help(mp1,mp2,mp1[arr2[i]],1,arr1,arr2,memo);
            
            return memo[i][flag]=max(a,b);
        }
    }

    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        
        for(int i=0;i<arr1.size();i++)
        mp1[arr1[i]]=i+1;
        
        for(int i=0;i<arr2.size();i++)
        mp2[arr2[i]]=i+1;
        
        // cout<<mp1.size()<<endl;
        // cout<<mp2.size()<<endl;
        int size=max(arr1.size(),arr2.size());
        vector<vector<int>> memo(size,vector<int>(2,-1));
        int a=help(mp1,mp2,0,1,arr1,arr2,memo);
        int b=help(mp1,mp2,0,0,arr1,arr2,memo);
        return max(a,b);
    }
};

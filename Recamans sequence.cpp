
/*  Method - 1
    Iterative
    Time complexity - O(N)
    Space complexity- O(N+N)
*/
class Solution{
    public:
    vector<int> recamanSequence(int n){
        int pre=0;
        if(n==0)
        return {0};
        
        vector<int> ans;
        unordered_map<int,int> mp;
        ans.push_back(0);
        mp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int curr=pre-i;
            if(curr<0 or mp.count(curr))
            curr+=(2*i);
            
            ans.push_back(curr);
            mp[curr]=1;
            pre=curr;
        }
        return ans;
    }
};

/*  Method - 2
    Recursion
    Time complexity - O(N)
    Space complexity- O(N+N+N)
*/
class Solution{
    public:
    void help(int& n,int pre,int i,unordered_map<int,int>& mp,vector<int>& ans)
    {
        //base case
        if(i>n)
        return ;
        
        //recursive calls
        //and small calculation
        int curr=pre-i;
        if(curr<0 or mp.count(curr))
        curr+=(2*i);
        
        mp[curr]=1;
        ans.push_back(curr);
        
        help(n,curr,i+1,mp,ans);
    }
    vector<int> recamanSequence(int n){
        unordered_map<int,int> mp;
        vector<int> ans;
        int pre=0;
        mp[0]=1;
        ans.push_back(0);
        
        help(n,0,1,mp,ans);
        return ans;
    }
};
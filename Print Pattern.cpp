// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
    void help(int n,vector<int>& ans)
    {
        ans.push_back(n);
        if(n<=0)
        return ;
        
        help(n-5,ans);
        ans.push_back(n);
    }
    vector<int> pattern(int N){
        vector<int> ans;
        help(N,ans);
        return ans;
    }
};

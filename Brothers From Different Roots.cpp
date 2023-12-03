// Time complexity - O(N)
// Space complexity- O(N+N)
class Solution
{
    public:
    void dfs(Node* root,unordered_map<int,int>& mp,int& x,int& cnt,bool flag)
    {
        if(!root)
        return ;
        
        if(flag)
        cnt+=mp[x-root->data];
        
        if(!flag)
        mp[root->data]++;
        dfs(root->left,mp,x,cnt,flag);
        dfs(root->right,mp,x,cnt,flag);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,int> mp;
        int cnt=0;
        dfs(root1,mp,x,cnt,0);
        dfs(root2,mp,x,cnt,1);
        
        return cnt;
    }
};

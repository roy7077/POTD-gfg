// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution
{
    public:
    void help(Node* root,int sum,vector<vector<int>>& ans,vector<int>& v)
    {
        //base case
        if(!root)
        return ;
        
        if(sum==root->key)
        {
            v.push_back(root->key);
            ans.push_back(v);
            v.pop_back();
        }
        
        //recursive calls
        //and small calculation
        v.push_back(root->key);
        help(root->left,sum-root->key,ans,v);
        help(root->right,sum-root->key,ans,v);
        
        v.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<int> v;
        vector<vector<int>> ans;
        help(root,sum,ans,v);
        
        return ans;
    }
};

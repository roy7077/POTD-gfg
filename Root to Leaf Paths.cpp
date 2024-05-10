// Time complexity - O(N)
// Space complexity- O(H)
class Solution {
    public:
    void help(Node* root,vector<int>& tempPath,vector<vector<int>>& ans)
    {
        //base case
        if(!root)
        return ;
        
        if(!(root->left) and !(root->right))
        {
            tempPath.push_back(root->data);
            ans.push_back(tempPath);
            tempPath.pop_back();
            return ;
        }
        
        //recursive calls
        //and small calculation
        tempPath.push_back(root->data);
        help(root->left,tempPath,ans);
        help(root->right,tempPath,ans);
        tempPath.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> tempPath;
        help(root,tempPath,ans);
        return ans;
    }
};

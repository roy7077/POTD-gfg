// Time complexity - O(N)
// Space complexity- O(H+H)
class Solution {
  public:
    // Function should return all the ancestor of the target node
    bool help(Node* root,int& target,vector<int>& ans)
    {
        //base case
        if(!root)
        return 0;
        
        if(root->data==target)
        return 1;
        
        //recursive calls
        //and small calculation
        bool left=help(root->left,target,ans);
        if(left)
        {
            ans.push_back(root->data);
            return 1;
        }
        
        bool right=help(root->right,target,ans);
        if(right)
        {
            ans.push_back(root->data);
            return 1;
        }
        
        return 0;
    }
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        help(root,target,ans);
        return ans;
    }
};
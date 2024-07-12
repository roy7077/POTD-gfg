// Time complexity - O(N)
// Space complexity- O(H)
class Solution {
    public:
    bool help(Node* root,int target)
    {
        //base case
        if(!root)
        return 0;
        
        if(!(root->left) and !(root->right))
        return target==root->data;
        
        if(target<0)
        return 0;
        
        //recursive calls
        //small calculation
        int a=help(root->left,target-root->data);
        
        if(a)
        return 1;
        
        int b=help(root->right,target-root->data);
        
        return b;
    }
    bool hasPathSum(Node *root, int target) {
        return help(root,target);
    }
};

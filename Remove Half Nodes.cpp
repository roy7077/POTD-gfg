// Time complexity - O(N)
// Space complexity- O(H)
class Solution {
    public:
    Node* help(Node* root)
    {
        //base case
        if(!root)
        return NULL;
        
        if(!(root->left) and !(root->right))
        return root;
        
        //recursive calls
        //and small calculation
        root->left=help(root->left);
        root->right=help(root->right);
        
        if(!(root->left) and root->right)
        {
            delete root;
            return root->right;
        }
        
        if(!(root->right) and root->left)
        {
            delete root;
            return root->left;
        }
        
        return root;
    }
    Node *RemoveHalfNodes(Node *root) {
        return help(root);
    }
};


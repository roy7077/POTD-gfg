// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool help(Node* root1,Node* root2)
    {
        //base case
        if((!root1 and root2) or (root1 and !root2))
        return 0;
        
        if(!root1 and !root2)
        return 1;
        
        if(root1->data!=root2->data)
        return 0;
        
        //recursive calls
        //small calculation
        bool l=help(root1->left,root2->right);
        if(!l)
        return 0;
        
        bool r=help(root1->right,root2->left);
        return r;
    }
    bool isSymmetric(struct Node* root)
    {
	    return help(root,root);
    }
};


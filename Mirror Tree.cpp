// Time complexity - O(N)
// Space complexity- O(Hieght of a tree)
class Solution {
    public:
    Node* help(Node* root)
    {
        // base case
        if(!root)
        return NULL;
        
        // recursive calls
        // and small calculation
        Node* tempNode=root->left;
        root->left=help(root->right);
        root->right=help(tempNode);
        
        return root;
    }
    void mirror(Node* node) {
        help(node);
    }
};

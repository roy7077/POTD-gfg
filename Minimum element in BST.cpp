// Method - 1
// Time complexity - O(N)
// Space complexity- O(Height of the tree)
class Solution {
    public:   
    int help(Node* root)
    {
        //base cases
        if(!root)
        return 1e9;
        
        if(root->left==NULL)
        return root->data;
        
        //recursive calls
        if(root->left)
        return help(root->left);
    }
    int minValue(Node* root) {
        return help(root);
    }
};


// Method - 2
// Iterative
// Time complexity - O(Height of the tree)
// Space complexity- O(1)
class Solution {
    public:   
    int minValue(Node* root) {
        while(root->left)
        root=root->left;
        
        return root->data;
    }
};
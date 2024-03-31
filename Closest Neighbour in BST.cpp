//Recursion - 1.0
// Recursion
// Time complexity - O(Height of the tree)
// Space complexity- O(Height of thre tree)
class Solution {
    public:
    int help(Node* root,int& x)
    {
        //base case
        if(!root)
        return 0;
        
        //recursive calls
        //and small calculation
        if(root->key==x)
        return x;
        
        int a;
        if(root->key<x)
        a=help(root->right,x);
        else
        a=help(root->left,x);
        
        if(max(root->key,a)<=x)
        return max(root->key,a);
        else
        return min(root->key,a);
    }
    int findMaxForN(Node* root, int n) {
        int ans=help(root,n);
        return ans==0 ? -1:ans;
    }
};

// Recursion - 1.1
// Recursion 
// Time complexity - O(Height of the tree)
// Space complexity- O(Height of thre tree)
class Solution {
    public:
    void help(Node* root,int& x,int& ans)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //and small calculation
        if(root->key<=x)
        {
            ans=root->key;
            help(root->right,x,ans);
        }
        else
        help(root->left,x,ans);
    }
    int findMaxForN(Node* root, int n) {
        int ans=0;
        help(root,n,ans);
        return ans==0 ? -1:ans;
    }
};

// Iterative
// Time complexity - O(Height of the tree)
// Space complexity- O(1)
class Solution {
    public:
    int findMaxForN(Node* root, int n) {
        int ans=0;
        while(root)
        {
            if(root->key<=n)
            {
                ans=root->key;
                root=root->right;
            }
            else
            root=root->left;
        }
        return ans==0 ? -1:ans;
    }
};
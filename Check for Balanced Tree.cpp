class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<int,bool> help(Node* root)
    {
        //base case
        if(!root)
        return {0,1};
        
        //recursive calls
        auto l=help(root->left);
        if(!l.second)
        return {0,0};
        
        auto r=help(root->right);
        if(!r.second)
        return {0,0};
        
        bool bal=1;
        if(abs(l.first-r.first)>1)
        bal=0;
        
        int height=max(l.first,r.first)+1;
        return {height,bal};
        
    }
    bool isBalanced(Node *root)
    {
        auto ans=help(root);
        return ans.second;
    }
};
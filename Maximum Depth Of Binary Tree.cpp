class Solution{
  public:
    int depth(Node* root)
    {
        if(root==NULL)
        return 0;
        
        int h1=depth(root->left);
        int h2=depth(root->right);
        
        return max(h1,h2)+1;
    }
    int maxDepth(Node *root) {
        
        return depth(root);
    }
};
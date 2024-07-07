class Solution {
    public:
    Node* pre=NULL;
    void inorder(Node* root)
    {
        //base case
        if(!root)
        return;
        
        //recursive calls
        //and small calculation
        inorder(root->left);
        
        if(pre)
        pre->next=root;
        
        pre=root;
        inorder(root->right);
    }
    void populateNext(Node *root) {
        inorder(root);
    }
};
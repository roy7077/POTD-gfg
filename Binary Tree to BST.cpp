class Solution
{
    public:
    void inorder(vector<int>& v,Node* root)
    {
        if(!root)
        return ;
        
        inorder(v,root->left);
        v.push_back(root->data);
        inorder(v,root->right);
    }
    
    void MakeBst(Node* root,vector<int>& v,int& i)
    {
        if(!root)
        return ;
        
        MakeBst(root->left,v,i);
        root->data=v[i++];
        MakeBst(root->right,v,i);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
        inorder(v,root);
        
        sort(v.begin(),v.end());
        int i=0;
        MakeBst(root,v,i);
        return root;
    }
};
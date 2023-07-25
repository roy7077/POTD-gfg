int help(Node* root,int node,int k,int& ans)
{
    //base case
    if(root==NULL)
    return -1;
    
    
    if(root->data==node)
    return 1;
    
    //recursive calls
    int a=help(root->left,node,k,ans);
    if(a==k)
    {
        ans=root->data;
        return k+1;
    }
    if(a!=-1)
    return a+1;
    
    int b=help(root->right,node,k,ans);
    if(b==k)
    {
        ans=root->data;
        return k+1;
    }
    if(b!=-1)
    return b+1;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    int a=help(root,node,k,ans);
    
    return ans;
}
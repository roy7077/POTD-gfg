class Solution
{
    public:
    
    void help(Node* root,int& k,int& ans)
    {
        //base case
        if(!root)
        return ;
        
        help(root->right,k,ans);
        
        if(ans!=-1)
        return ;
        if(k==1)
        {
            ans=root->data;
            return ;
        }
        
        k--;
        help(root->left,k,ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans=-1;
        help(root,K,ans);
        
        return ans;
    }
};
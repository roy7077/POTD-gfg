class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void help(Node* root,vector<int>& ans,int& cnt,int level)
    {
        //base case
        if(root==NULL)
        return ;
        
        //small calculation
        if(level>cnt)
        {
            ans.push_back(root->data);
            cnt=level;
        }
        
        //recursive calls
        help(root->right,ans,cnt,level+1);
        help(root->left,ans,cnt,level+1);
        
        return ;
    }
    
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       int cnt=0;
       int level=1;
       help(root,ans,cnt,level);
       return ans;
    }
};
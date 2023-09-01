class Solution
{
   public:
    
    void help(Node* root,vector<int>& ans,int level)
    {
        //base case
        if(!root)
        return ;
        
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(level);
            return ;
        }
        
        //recursive calls
        help(root->left,ans,level+1);
        help(root->right,ans,level+1);
    }
    
    int getCount(Node *root, int k)
    {
        vector<int> ans;
        help(root,ans,1);
        sort(ans.begin(),ans.end());
        
        int cnt=0;
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            if(sum+ans[i]<=k)
            sum+=ans[i];
            else
            return cnt;
            
            cnt++;
        }
        
        return cnt;
    }
};
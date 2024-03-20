// Method - 1
// Time complexity - O(N)
// Space complexity- O(H)
class Solution
{
    public:
    void help(Node* root,int sum,int& ans,int& maxH,int curH)
    {
        //base case
        if(!root)
        return ;
        
        if(!(root->left) and !(root->right))
        {
            sum+=root->data;
            if(curH>maxH)
            {
                maxH=curH;
                ans=sum;
            }
            else if(curH==maxH)
            ans=max(ans,sum);
            
            return ;
        }
        
        //recurisve call
        //and small calculation
        help(root->left,sum+root->data,ans,maxH,curH+1);
        help(root->right,sum+root->data,ans,maxH,curH+1);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int ans=0;
        int maxH=0;
        help(root,0,ans,maxH,0);
        return ans;
    }
};

// Method - 2
// Time complexity - O(N)
// Space complexity- O(H)
// a.first -> height
// a.second-> sum
class Solution
{
    public:
    pair<int,int> help(Node* root)
    {
        //base case
        if(!root)
        return {0,0};
        
        //recurisve calls
        //ans small calculation
        pair<int,int> a=help(root->left);
        pair<int,int> b=help(root->right);
        
        if(a.first>b.first)
        return {a.first+1,a.second+root->data};
        else if(b.first>a.first)
        return {b.first+1,b.second+root->data};

        return {a.first+1,max(a.second,b.second)+root->data};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int,int> ans=help(root);
        return ans.second;
    }
};
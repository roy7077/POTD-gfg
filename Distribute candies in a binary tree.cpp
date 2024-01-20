/*---------TWO  APPROACHES----------*/

//METHOD - 1
// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution
{
    public:
    int help(Node* root,int& ans)
    {
        //base case
        if(!root)
        return 0;
        
        //recursive callls
        //and small calculation
        int left=help(root->left,ans);
        int right=help(root->right,ans);
        
        ans+=abs(left)+abs(right);
        
        return root->key+left+right-1;
    }
    int distributeCandy(Node* root)
    {
        int ans=0;
        int call=help(root,ans);
        return ans;
    }
};

//METHOD - 2
// Time complexity - O(N)
// Space complexity- O(height of tree)
typedef pair<int,int> pi;
class Solution
{
    public:
    pi help(Node* root)
    {
        //base case
        if(!root)
        return {0,0};
        
        //recursive callls
        //and small calculation
        pi left=help(root->left);
        pi right=help(root->right);
        
        pi temp;
        temp.first=abs(left.second)+abs(right.second)+left.first+right.first;
        temp.second=root->key+left.second+right.second-1;
        
        return temp;
    }
    int distributeCandy(Node* root)
    {
        pi ans=help(root);
        return ans.first;
    }
};
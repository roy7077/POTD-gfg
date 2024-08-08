// Method 1
// Time complexity - O(N)
// Space complexity- O(height of tree)
typedef pair<bool,int> pi;
class Solution
{
    public:
    pi help(Node* root)
    {
        //base case
        if(!root)
        return {1,0};
        
        if(root->left==NULL and root->right==NULL)
        return {1,root->data};
        
        //recursive calls
        //small calculation
        pi a=help(root->left);
        pi b=help(root->right);
        
        if(a.first==0 or b.first==0)
        return {0,0};
        
        if((a.second+b.second)==root->data)
        return {1,a.second+b.second+root->data};
        else
        return {0,0};
    }
    bool isSumTree(Node* root)
    {
        return help(root).first;
    }
};

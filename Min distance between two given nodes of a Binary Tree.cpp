// Time complexity - O(N)
// Space complexity- O(height of tree)
typedef pair<int,int> pi;
class Solution{
    public:
    pi help(Node* root,int& a,int& b,int& mini)
    {
        //base case
        if(!root)
        return {0,0};
        
        //recursive calls
        //and small calculation
        pi left=help(root->left,a,b,mini);
        pi right=help(root->right,a,b,mini);
        
        if(left.first and right.first)
        {
            mini=min(mini,left.second+right.second);
            return {0,0};
        }
        
        if(left.first)
        {
            if(root->data==a or root->data==b)
            mini=min(mini,left.second);
            else
            return {1,left.second+1};
        }
        
        if(right.first)
        {
            if(root->data==a or root->data==b)
            mini=min(mini,right.second);
            else
            return {1,right.second+1};
        }
        
        if(root->data==a or root->data==b)
        return {1,1};
        
        return {0,0};
    }
    int findDist(Node* root, int a, int b) {
        int mini=1e9;
        pi ans=help(root,a,b,mini);
        return mini>=1e9 ? 0:mini;
    }
};
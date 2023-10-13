//Time complexity - O(Number of node)
//Space complexity -O(height of tree)
class Solution{

    public:
    void help(Node* root,int x,int& ans)
    {
        //base case
        if(!root)
        return ;
        
        //small calculation
        if(root->data==x)
        {
            ans=x;
            return ;
        }
        else if(root->data<x and ans<root->data)
        ans=root->data;
        
        //recursive calls
        help(root->left,x,ans);
        help(root->right,x,ans);
        
    }
    int floor(Node* root, int x) {
        
        int ans=-1;
        help(root,x,ans);
        
        return ans;
    }
};
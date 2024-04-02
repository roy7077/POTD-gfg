// Time complexity - O(N)
// Space complexity- O(Height of the tree)
typedef pair<int,int> pi;
// first -> maximum
// second-> minimum
class Solution
{
    public:
    pi help(Node* root,int& ans)
    {
        //base case
        if(!(root->left) and !(root->right))
        return {root->data,root->data};
        
        //recursive calls
        //and small calculation
        pi a={-1e9,1e9};
        pi b={-1e9,1e9};
        
        if(root->left)
        a=help(root->left,ans);
        
        if(root->right)
        b=help(root->right,ans);
        
        if(a.first!=-1e9)
        ans=min(ans,root->data-a.first);
        
        if(b.second!=1e9)
        ans=min(ans,b.second-root->data);
        
        return {max({a.first,b.first,root->data}), // minimum element of the current subtree
                min({a.second,b.second,root->data})};// maximum element of the current subtree
    }
    int absolute_diff(Node *root)
    {
        int ans=1e9;
        help(root,ans);
        return ans;
    }
};
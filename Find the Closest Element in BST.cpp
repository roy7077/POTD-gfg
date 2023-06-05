
#include <algorithm>
class Solution
{
    public:
    int help(Node* root,int k)
    {
        if(root==NULL)
        return 1e9;
        
        int left=help(root->left,k);
        int right=help(root->right,k);
        int node=abs(k-root->data);
        
        return min({left,right,node});
    }
    int minDiff(Node *root, int K)
    {
        return help(root,K);
    }
};
//time complexity - O(number of nodes)
//space complexity - O(height of a tree)

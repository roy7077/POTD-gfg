/* pair and recursion
   Time complexity - O(N)
   Space complexity- O(height of the tree)
*/
typedef pair<Node*,Node*> pi;
class Solution
{
    public:
    pi help(Node* root)
    {
        //base case
        if(!root)
        return {NULL,NULL};
        
        if(root->left==NULL and root->right==NULL)
        return {root,root};
        
        //recursive calls
        //and Small calculation
        pi left=help(root->left);
        pi right=help(root->right);
        
        if(left.second)
        {
            left.second->right=root;
            root->right=right.first;
            root->left=NULL;
            
            if(right.second)
            return {left.first,right.second};
            else
            return {left.first,root};
        }
        
        root->right=right.first;
        root->left=NULL;
        return {root,right.second};
    }
    Node *flattenBST(Node *root)
    {
        return help(root).first;
    }
};


class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL and root2==NULL)
        return true;
        else if(root1==NULL or root2==NULL)
        return false;
        
        if(root1->data != root2->data)
        return false;
    
        bool a=isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left);
        bool b=isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right);
        
        return (a or b);
    }
};

class Solution{
  public:
    Node* help(Node* root,Node* x)
    {
        //base case
        if(root==NULL)
        return NULL;
        
        //recursive calls
        Node* ans1=help(root->left,x);
        if(ans1)
        return ans1;
        
        if(root->data>x->data)
        return root;
        
        Node* ans2=help(root->right,x);
        if(ans2)
        return ans2;
    }
    
    Node* inOrderSuccessor(Node *root, Node *x)
    {
       return help(root,x);
    }
};

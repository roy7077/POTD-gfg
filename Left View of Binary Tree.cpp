
void help(Node* root,vector<int>& v,int depth,int& lvl)
{
    // base case
    if(!root)
    return ;
    
    // recursive calls
    // and small calculation
    
    if(depth>lvl)
    {
        v.push_back(root->data);
        lvl=depth;
    }
    
    help(root->left,v,depth+1,lvl);
    help(root->right,v,depth+1,lvl);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   int lvl=-1;
   help(root,ans,0,lvl);
   return ans;
}


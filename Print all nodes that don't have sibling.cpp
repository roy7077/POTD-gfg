// Time complexity - O(N)
// Space complexity- O(H)
void help(Node* root,vector<int>& ans)
{
    //base case
    if(!root)
    return ;
    
    //recursive calls
    //and small calculation
    if(!(root->left) and root->right)
    ans.push_back(root->right->data);
    else if(!(root->right) and root->left)
    ans.push_back(root->left->data);

    help(root->left,ans);
    help(root->right,ans);
}
vector<int> noSibling(Node* node)
{
    vector<int> ans;
    help(node,ans);
    if(ans.size()==0)
    ans.push_back(-1);
    else
    sort(ans.begin(),ans.end());
    
    return ans;
}
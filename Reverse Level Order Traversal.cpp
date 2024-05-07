/* 
   Method - 1
   BFS
   Time complexity - O(N)
   Space complexity- O(N+N)
*/
vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            Node* node=q.front();
            q.pop();
            
            if(ans.size())
            ans.insert(ans.begin(),node->data);
            else
            ans.push_back(node->data);
            
            if(node->right)
            q.push(node->right);
            
            if(node->left)
            q.push(node->left);
        }
    }
    return ans;
}


/* 
   Method - 2
   DFS
   Time complexity - O(NlogN)
   Space complexity- O(N+Height of the tree)
*/

void help(Node* root,int lev,map<int,vector<int>>& mp)
{
    //base case
    if(!root)
    return ;
    
    //recursive calls
    //and small calculation
    if(mp[lev].size())
    mp[lev].insert(mp[lev].begin(),root->data);
    else
    mp[lev].push_back(root->data);
    
    help(root->left,lev+1,mp);
    help(root->right,lev+1,mp);
}
vector<int> reverseLevelOrder(Node *root)
{
    map<int,vector<int>> mp;
    help(root,0,mp);
    
    vector<int> ans;
    for(auto& it:mp)
    {
        for(auto& x:it.second)
        {
            if(ans.size())
            ans.insert(ans.begin(),x);
            else
            ans.push_back(x);
        }
    }
    return ans;
}
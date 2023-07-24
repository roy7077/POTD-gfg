vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    bool flag=0;
    
    while(!q.empty())
    {
        int size=q.size();
        vector<int> v;
        for(int i=0;i<size;i++)
        {
            Node* n=q.front();
            q.pop();
            
            v.push_back(n->data);
            
            if(n->left)
            q.push(n->left);
            
            if(n->right)
            q.push(n->right);
        }
        
        if(flag&1)
        {
            for(auto it:v)
            ans.push_back(it);
        }
        else
        {
            for(int i=v.size()-1;i>=0;i--)
            ans.push_back(v[i]);
        }
        
        flag=(!flag);
    }
    
    return ans;
}
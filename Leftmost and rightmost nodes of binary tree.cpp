// Time complexity  - O(Number of nodes)
// Space complexity - O(Number of nodes)
void printCorner(Node *root)
{
    if(!root)
    return ;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    bool first=1;
    bool last=1;
    int cnt=0;
    while(!q.empty())
    {
        Node* it=q.front();
        q.pop();
        
        //for left child
        if(it->left)
        q.push(it->left);
        
        //for right child
        if(it->right)
        q.push(it->right);
        
        if(first)
        {
            cout<<it->data<<" ";
            first=0;
        }
        
        cnt++;
        Node* next=q.front();
        if(next==NULL)
        {
            q.pop();
            if(cnt!=1)
            {
                cout<<it->data<<" ";
            }
            
            cnt=0;
            
            first=1;
            
            if(q.size()==0)
            break;
            else
            q.push(NULL);
        }
        
    }
}
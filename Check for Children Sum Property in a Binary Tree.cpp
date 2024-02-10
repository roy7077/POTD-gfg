
/* Method - 1
   DFS - recursion
   Time complexity - O(N)
   Space complexity- O(height of tree)
*/

class Solution{
    public:
    bool help(Node* root)
    {
        //base case
        if(!root)
        return 1;
        
        if(root->left==NULL and root->right==NULL)
        return 1;
        
        //recursive calls
        //and small calculation
        int sum=0;
        if(root->left)
        sum+=root->left->data;
        
        if(root->right)
        sum+=root->right->data;
        
        if(sum!=root->data)
        return 0;
        
        bool a=help(root->left);
        if(!a)
        return 0;
        
        bool b=help(root->right);
        return b;
    }
    int isSumProperty(Node *root)
    {
        return int(help(root));
    }
};

/* Method - 2
   BFS - queue
   Time complexity - O(N)
   Space complexity- O(N)
*/

class Solution{
    public:
    int isSumProperty(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();
            
            if(node->left==NULL and node->right==NULL)
            continue;
            
            int sum=0;
            if(node->left)
            {
                sum+=node->left->data;
                q.push(node->left);
            }
            
            if(node->right)
            {
                sum+=node->right->data;
                q.push(node->right);
            }
            
            if(sum!=(node->data))
            return 0;
        }
        return 1;
    }
};
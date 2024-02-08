// THREE APPROACHES

/* Method - 1
   BFS
   Time complexity - O(N)
   Space complexity- O(N)
*/
class Solution{
    public:
    bool check(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        
        bool flag=0;
        while(!q.empty())
        {
            if(flag)
            return 0;
            
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
            
                if(node->left==NULL and node->right==NULL)
                {
                    flag=1;
                    continue;
                }
                
                if(node->left)
                {
                    if(flag)
                    return 0;
                    
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    if(flag)
                    return 0;
                    
                    q.push(node->right);
                }
            }
        }
        return 1;
    }
};

/* Method - 2
   DFS
   Time complexity - O(N)
   Space complexity- O(Height of tree)
*/
typedef pair<int,int> pi;
class Solution{
    public:
    pi help(Node* root)
    {
        //base case
        if(!root)
        return {0,0};
        
        if(root->left==NULL and root->right==NULL)
        return {1,1};
        
        //recursive calls
        //and small calculation
        pi left,right;
        left={-1e9,1e9};
        right={-1e9,1e9};
        
        if(root->left)
        left=help(root->left);
        
        if(root->right)
        right=help(root->right);
        
        return {max(left.first,right.first)+1,min(left.second,right.second)+1};
    }
    bool check(Node *root)
    {
        pi ans=help(root);
        return ans.first==ans.second;
    }
};

/* Method - 3
   DFS
   Time complexity - O(N)
   Space complexity- O(Height of tree)
*/
typedef pair<int,int> pi;
class Solution{
    public:
    int help(Node* root,int& ans)
    {
        //base case
        if(!root)
        return 0;
        
        if(root->left==NULL and root->right==NULL)
        return 1;
        
        //recursive calls
        //and small calculation
        int left,right;
        left=right=0;
        
        if(root->left)
        {
            left=help(root->left,ans);
            if(!ans)
            return 1;
        }
        
        if(root->right)
        {
            right=help(root->right,ans);
            if(!ans)
            return 1;
        }
        
        if(left!=0 and right!=0 and left!=right)
        {
            ans=0;
            return 1;
        }
        
        return max(left,right)+1;
    }
    bool check(Node *root)
    {
        int ans=1;
        int call=help(root,ans);
        return ans;
    }
};
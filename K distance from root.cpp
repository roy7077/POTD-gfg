/*
  Method - 1
  DFS
  Time complexity - O(N)
  Space complexity- O(K)
*/
class Solution
{
    public:
    void help(Node* root,int k,vector<int>& ans)
    {
        //base case
        if(!root)
        return ;
        
        if(k==0)
        {
            ans.push_back(root->data);
            return ;
        }
        
        //recursive calls
        //and small calculation
        help(root->left,k-1,ans);
        help(root->right,k-1,ans);
    }
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> ans;
        help(root,k,ans);
        return ans;
    }
};


/*
  Method - 2
  BFS
  Time complexity - O(N)
  Space complexity- O(2*Width of tree)
*/
class Solution
{
    public:
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Node* node=q.front();
                q.pop();
                
                if(k==0)
                {
                    ans.push_back(node->data);
                    continue;
                }
                
                if(node->left)
                q.push(node->left);
                
                if(node->right)
                q.push(node->right);
            }
            k--;
        }
        return ans;
    }
};
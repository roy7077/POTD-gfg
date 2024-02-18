Depth First Search
/* Depth first search
   Time complexity - O(N)
   Space complexity- O(H)
*/
class Solution
{
    public:
    int help(Node* root)
    {
        //base case
        if(!root)
        return 0;
        
        if(root->left==NULL and root->right==NULL)
        return root->data;
        
        //recursive calls
        //and small calculation
        int a=help(root->left);
        int b=help(root->right);
        
        return (a+b);
    }
    int sumOfLeafNodes(Node *root ){
        return help(root);
    }
};
Breadth First Search
/* Breadth First Search
   Time complexity - O(N)
   Space complexity- O(N)
*/
#include <queue>
class Solution
{
    public:
    int sumOfLeafNodes(Node *root ){
        int sum=0;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();
            
            if(node->left==NULL and node->right==NULL)
            sum+=node->data;
            
            if(node->left)
            q.push(node->left);
            
            if(node->right)
            q.push(node->right);
        }
        return sum;
    }
};
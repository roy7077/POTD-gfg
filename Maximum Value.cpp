//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        
        vector<int> ans;
        queue<Node*> q;

        q.push(node);
        q.push(NULL);
        
        int maxi=node->data;
        while(!q.empty())
        {
            Node* root=q.front();
            q.pop();
            
            if(root==NULL and q.size()==0)
            {
                ans.push_back(maxi);
                break;
            }
            
            if(root==NULL)
            {
                ans.push_back(maxi);
                maxi=-1e9;
                q.push(NULL);
            }
            else
            {
                maxi=max(root->data,maxi);
                
                if(root->left!=NULL)
                q.push(root->left);
                
                if(root->right!=NULL)
                q.push(root->right);
            }
        }
        
        return ans;
    }
};
// time complexity - O(N->number of nodes)
// space complexity - O(height of tree)

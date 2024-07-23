/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Method - 1
// Time complexity - O(NlogN)
// Space complexity- O(N+N+H)
class Solution {
    public:
    void help(Node* root,vector<int>& ans)
    {
        //base case
        if(!root)
        return ;
        
        //recursive call
        //and small calculation
        help(root->left,ans);
        ans.push_back(root->data);
        help(root->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        help(root1,ans);
        help(root2,ans);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

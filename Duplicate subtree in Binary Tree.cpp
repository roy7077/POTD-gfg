class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    map <string, pair<string, int>> mp;
    bool flag = false;
    
    vector<string> func(Node *root) {
        if(root == NULL) return {"", ""};
        if(root->left == NULL && root->right == NULL) return {to_string(root->data), to_string(root->data)};
        vector<string> left = func(root->left);
        vector<string> right = func(root->right);
        string inOrder = left[0] + to_string(root->data) + right[0];
        string postOrder = left[1] + right[1] + to_string(root->data);
        if(mp.find(inOrder) != mp.end() && mp[inOrder].first == postOrder) flag = true;
        mp[inOrder] = {postOrder, 1};
        return {inOrder, postOrder};
    }
    
    int dupSub(Node *root) {
         // code here
         func(root);
         return flag;
    }
};
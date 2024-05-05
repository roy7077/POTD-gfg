/*
 Map & Recursion
 Time complexity- O(NlogN)
 Space complexity- O(Width of a tree + Height of a tree)
*/
class Solution{
    public:
    void help(Node* root,int ind,map<int,int>& mp)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //and small calculation
        mp[ind]+=root->data;
        help(root->left,ind-1,mp);
        help(root->right,ind+1,mp);
    }
    vector<int> verticalSum(Node *root) {
        map<int,int> mp;
        help(root,0,mp);
        
        vector<int> ans;
        for(auto& it:mp)
        ans.push_back(it.second);
        
        return ans;
    }
};
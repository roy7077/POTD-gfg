/*-----------chutiya banaya 😂😂😂😂😂 ----------*/

class Solution {
public:
    
    void helper(Node* root,vector<int>& v)
    {
        //base case
        if(root==NULL)
        return ;
        
        //recursive calls
        //small calculation
        v.push_back(root->data);
        helper(root->next,v);
        helper(root->bottom,v);
        
        return ;
        
    }
    Node *flatten(Node *root)
    {
        vector<int> v;
        helper(root,v);
        
        sort(v.begin(),v.end());
        for(auto it:v)
        cout<<it<<" ";
        
        return NULL;
    }
};

//time complexity -  O(number of nodes)
//space complexity - O(number of nodes)

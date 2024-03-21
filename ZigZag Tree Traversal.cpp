// BFS
// Time complexity - O(N)
// Space complexity- O(N+N)
class Solution{
    public:
    vector<int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	
    	bool flag=1;
    	while(!q.empty())
    	{
    	    vector<int> temp;
    	    int size=q.size();
    	    while(size--)
    	    {
    	        Node* node=q.front();
    	        q.pop();
    	        
    	        temp.push_back(node->data);
    	        
    	        if(node->left)
    	        q.push(node->left);
    	        
    	        if(node->right)
    	        q.push(node->right);
    	    }
    	    
    	    if(flag)
    	    for(auto it:temp)
    	    ans.push_back(it);
    	    
    	    if(!flag)
    	    {
    	        for(int i=temp.size()-1;i>=0;i--)
    	        ans.push_back(temp[i]);
    	    }
    	    
    	    flag=(!flag);
    	}
    	return ans;
    }
};

// dfs
// Time complexity - O(NlogN)
// Space complexity- O(N+N+H)
class Solution{
    public:
    void help(Node* root,map<int,vector<int>>& mp,int h)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        mp[h].push_back(root->data);
        help(root->left,mp,h+1);
        help(root->right,mp,h+1);
    }
    vector<int> zigZagTraversal(Node* root)
    {
    	map<int,vector<int>> mp;
    	help(root,mp,0);
    	
    	vector<int> ans;
    	bool flag=1;
    	for(auto it:mp)
    	{
    	    if(flag)
    	    for(auto x:it.second)
    	    ans.push_back(x);
    	    
    	    if(!flag)
    	    {
    	        for(int i=it.second.size()-1;i>=0;i--)
    	        ans.push_back(it.second[i]);
    	    }
    	    
    	    flag=(!flag);
    	}
    	return ans;
    }
};
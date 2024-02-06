/* Method - 1
   Time complexity - O(N*(N/2))
   Space complexity- O(height of tree + N/2)
*/
class Solution
{
    public:
    vector<int> help(Node* root,int& k,int& cnt)
    {
        // Base cases
        if(!root)
        return {0};
        
        if(root->left==NULL and root->right==NULL)
        {
            if(k==0)
            cnt++;
            
            return {1};
        }
        
        //recursive calls
        //and small calculation
        vector<int> a;
        vector<int> b;
        
        if(root->left)
        a=help(root->left,k,cnt);
        
        if(root->right)
        b=help(root->right,k,cnt);
        
        vector<int> ans;
        for(auto it:a)
        ans.push_back(it);
        
        for(auto it:b)
        ans.push_back(it);
        
        bool flag=0;
        for(auto& it:ans)
        {
            if(!flag and it==k)
            {
                cnt++;
                flag=1;
            }
            
            it++;
        }
        
        return ans;
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	int cnt=0;
    	vector<int> ans=help(root,k,cnt);
    	return cnt;
    }
};
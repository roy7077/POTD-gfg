/* 
  Method - 1
  Recursion + Linear Search
  Time complexity - O(N^2)
  Space complexity- O(H)
*/
class Solution
{
    public:
    Node* help(int* in,int* post,int inStart,int inEnd,int postStart,int postEnd)
    {
        //base case
        if(inStart>inEnd)
        return NULL;
        
        //recursive calls
        //and small calculation
        Node* root=new Node(post[postEnd]);
        
        int ind=-1;
        for(int i=inStart;i<=inEnd;i++)
        {
            if(in[i]==post[postEnd])
            {
                ind=i;
                break;
            }
        }
        
        int leftSize=ind-inStart;
        int rightSize=inEnd-ind;
        
        root->left=help(in,post,inStart,ind-1,postStart,postStart+leftSize-1);
        root->right=help(in,post,ind+1,inEnd,postEnd-rightSize,postEnd-1);
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        return help(in,post,0,n-1,0,n-1);
    }
};


/* 
  Method - 2
  Recursion + Unordered_map
  Time complexity - O(N)
  Space complexity- O(N+H)
*/
class Solution
{
    public:
    Node* help(int* in,int* post,unordered_map<int,int>& mp,int inStart,int inEnd,int postStart,int postEnd)
    {
        //base case
        if(inStart>inEnd)
        return NULL;
        
        //recursive calls
        //and small calculation
        Node* root=new Node(post[postEnd]);
        
        int ind=mp[post[postEnd]];
        int leftSize=ind-inStart;
        int rightSize=inEnd-ind;
        
        root->left=help(in,post,mp,inStart,ind-1,postStart,postStart+leftSize-1);
        root->right=help(in,post,mp,ind+1,inEnd,postEnd-rightSize,postEnd-1);
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[in[i]]=i;
        
        return help(in,post,mp,0,n-1,0,n-1);
    }
};
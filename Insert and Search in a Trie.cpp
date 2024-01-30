/* Method - 1
 Iterative Approach
 
 //for inserting
 Time complexity - O(length of string)
 Space complexity- O(length of string*26)
 
 //for searching
 Time complexity - O(length of string)
 Space complexity- O(1)
 
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            TrieNode* temproot=root;
            for(int i=0;i<key.length();i++)
            {
                if(temproot->children[key[i]-'a']==NULL)
                temproot->children[key[i]-'a'] = new TrieNode();
                
                temproot=temproot->children[key[i]-'a'];
            }
            temproot->isLeaf=1;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            TrieNode* temproot=root;
            for(int i=0;i<key.length();i++)
            {
                if(temproot->children[key[i]-'a']==NULL)
                return 0;
                
                temproot=temproot->children[key[i]-'a'];
            }
            return temproot->isLeaf;
        }
};

/* Method - 2
 Recursive Approach
 
 //for inserting
 Time complexity - O(length of string)
 Space complexity- O(length of string+length of string*26)
 
 //for searching
 Time complexity - O(length of string)
 Space complexity- O(length of string)
 
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        void insertHelper(TrieNode* root,string& key,int i)
        {
            //base case
            if(i==key.length())
            {
                root->isLeaf=1;
                return ;
            }
            
            //recursive calls
            if(root->children[key[i]-'a'])
            insertHelper(root->children[key[i]-'a'],key,i+1);
            else
            {
                root->children[key[i]-'a']=new TrieNode();
                insertHelper(root->children[key[i]-'a'],key,i+1);
            }
        }
        void insert(struct TrieNode *root, string key)
        {
            return insertHelper(root,key,0);
        }
        
        //Function to use TRIE data structure and search the given string.
        bool searchHelper(TrieNode* root,string& key,int i)
        {
            //base case
            if(i==key.length())
            return root->isLeaf;
            
            //recursive calls
            if(root->children[key[i]-'a']==NULL)
            return 0;
            
            return searchHelper(root->children[key[i]-'a'],key,i+1);
        }
        bool search(struct TrieNode *root, string key) 
        {
            return searchHelper(root,key,0);
        }
};
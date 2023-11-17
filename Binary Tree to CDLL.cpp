/*---------------THREE  APPROACHES-------------*/


/*---1. Vector || T - O(N) || T - S(N+N+height of tree)----*/
class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void inorder(Node* root,vector<int>& a)
    {
        if(!root)
        return ;
        
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
    
    Node *bTreeToCList(Node *root)
    {
        vector<int> a;
        inorder(root,a);
        
        Node* head=NULL;
        Node* tail=NULL;
        
        for(auto it:a)
        {
            Node* newnode=newNode(it);
            if(!head)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                newnode->left=tail;
                tail->right=newnode;
                tail=newnode;
            }
        }
        
        head->left=tail;
        tail->right=head;
        
        return head;
    }
};

/*---2. Inorder || T - O(N) || S - O(N+height of the tree)----*/
class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void inorder(Node* root,Node* &head,Node* &tail)
    {
        if(!root)
        return ;
        
        inorder(root->left,head,tail);
        if(head==NULL)
        {
            Node* newnode=newNode(root->data);
            head=newnode;
            tail=newnode;
        }
        else
        {
            Node* newnode=newNode(root->data);
            newnode->left=tail;
            tail->right=newnode;
            tail=newnode;
        }
        
        inorder(root->right,head,tail);
    }
    
    Node *bTreeToCList(Node *root)
    {
        Node* head=NULL;
        Node* tail=NULL;
        
        inorder(root,head,tail);
        head->left=tail;
        tail->right=head;
        return head;
    }
};

/*-----------3. Inplace || T - O(N) || S - O(height of tree)------*/
class Solution 
{
    Node *prev = NULL;
    Node *head = NULL;
    void inorder(Node *root) 
    {
        if(!root) 
        return;
        
        inorder(root->left);
        if(!head) 
        head = prev = root;
        else 
        {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        inorder(root->right);
    }
    public:
    Node *bTreeToCList(Node *root) {
        inorder(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};
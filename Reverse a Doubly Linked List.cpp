/*-----------TWO  APPROACHES--------*/

/*---------1. Recursive Approach-----------*/
// Time complexity - O(N)
// Space complexity- O(N - recursion call stack space)
class Solution
{
    public:
    Node* reverse(Node* root)
    {
        //base case
        if(!(root->next))
        {
            root->next=root->prev;
            root->prev=NULL;
            return root;
        }
        
        //recursive calls
        Node* temp=reverse(root->next);
        Node* temp2=root->next;
        root->next=root->prev;
        root->prev=temp2;
        return temp;
    }
    
    Node* reverseDLL(Node * head)
    {
        if(!head or head->next==NULL)
        return head;
        
        Node* ans=reverse(head);
        return ans;
    }
};


/*----------2. Iterative Approach------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(!head or head->next==NULL)
        return head;
        
        Node* previous=NULL;
        while(head)
        {
            Node* temp=head->next;
            head->next=head->prev;
            head->prev=temp;
            previous=head;
            head=temp;
        }
        return previous;
    }
};
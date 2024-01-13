// TWO APPROACHES
// RECURSION
// Time complexity - O(N^2)
// Space complexity- O(N)
class Solution
{
    public:
    Node* help(Node* pre,Node* root)
    {
        //base case
        if(!root)
        return root;
        
        //recurisve calls
        //small calculation
        Node* temp=help(root,root->next);
        root->next=temp;
        
        Node* next_node=root->next;
        Node* root2=root;
        Node* pre_2=NULL;
        root=root->next;
        bool flag=0;
        while(root and root2->data>(root->data))
        {
            flag=1;
            pre_2=root;
            root=root->next;
        }
        
        if(flag)
        {
            if(pre==NULL)
            {
                
            }
            root2->next=root;
            pre_2->next=root2;
            
            if(pre)
            pre->next=next_node;
              
            return next_node;
        }
        
        return root2;
    }
    Node* insertionSort(struct Node* head_ref)
    {
        if(!head_ref)
        return NULL;
        
        Node* head=help(NULL,head_ref);
    }
    
};

//ITERATIVE
// Time complexity - O(N^2)
// Space complexity- O(1)
class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        if(!head_ref)
        return NULL;
        
        Node* res = new Node(-1);
        Node* temp = res;
        Node* curr = head_ref;
        while(curr)
        {
            temp = res;
            while(temp->next and curr->data>=temp->next->data)
            {
                temp=temp->next;
            }
            
            Node* nextNode = temp->next;
            temp->next = curr;
            curr = curr->next;
            temp->next->next = nextNode;
        }
        
        return res->next;
    }
    
};
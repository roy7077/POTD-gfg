/* 
   Method - 1
   Recursion 
   Time complexity - O(N)
   Space complexity- O(N)
*/
class Solution{
    public:
    int node = 0;
    int count = 0;
    Node* deleteRecur(Node* head){
        if(!head)
        return NULL;

        count++;
        head->next=deleteRecur(head->next);
        
        node++;
        return node==(count%2 ? count/2 + 1 : count/2) ? head->next : head;
    }
    Node* deleteMid(Node* head)
    {
        return deleteRecur(head);
    }
};



/* 
   Method - 2
   Iterative 
   Time complexity - O(N/2)
   Space complexity- O(1)
*/
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        if (head == NULL or head->next == NULL)
        return NULL;
        
        Node* slow=head;
        Node* fast=head;
        Node* pre=NULL;
        while(fast->next and fast->next->next)
        {
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        
        if(fast and fast->next)
        {
            fast=fast->next;
            pre=slow;
            slow=slow->next;
        }
        
        Node* nextNode=slow->next;
        delete slow;
        pre->next=nextNode;
        return head;
    }
};

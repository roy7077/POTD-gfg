// Time complexity- O(N)
// Space complexity-O(1)
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(head==NULL or head->next==NULL)
        return head;
        
        Node *h1,*h2;
        h1=head;
        h2=head->next;
        Node* pre=NULL;
        Node* ans=head->next;
        
        while(h2)
        {
            h1->next=h2->next;
            h2->next=h1;
            
            if(pre)
            {
                pre->next=h2;
                pre=h1;
            }
            else
            pre=h1;
            
            if(h1->next==NULL)
            break;
            
            h1=h1->next;
            h2=h1->next;
        }
        
        return ans;
    }
};
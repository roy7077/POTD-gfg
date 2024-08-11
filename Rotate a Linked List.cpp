// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    Node* rotate(Node* head, int k) {
        Node* prev=NULL;
        Node* h=head;
        Node* ansHead=NULL;
        
        int cntNode=0;
        while(h)
        {
            cntNode++;
            if(cntNode==k)
            {
                if(!(h->next))
                return head;
                
                Node* nextNode=h->next;
                ansHead=nextNode;
                
                h->next=NULL;
                prev=h;
                h=nextNode;
                continue;
            }
            
            prev=h;
            h=h->next;
        }
        prev->next=head;
        return ansHead;
    }
};

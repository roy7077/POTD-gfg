class Solution {
    public:
    int countNodesinLoop(Node *head) {
        
        // find where the cycle begins
        Node* slow=head;
        Node* fast=head;
        bool flag=0;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                flag=1;
                break;
            }
        }
        
        if(!flag)
        return 0;
        
        while(head!=slow)
        {
            head=head->next;
            slow=slow->next;
        }
        
        // cnt the number of nodes
        // are there in linked list
        Node* startNode=head;
        head=head->next;
        int cnt=1;
        while(head!=startNode)
        {
            cnt++;
            head=head->next;
        }
        
        return cnt;
    }
};

// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    void deleteAlt(struct Node *head) {
        Node* prev=NULL;
        int i=0;
        while(head)
        {
            i++;
            if(!(i%2))
            {
                Node* nextNode=head->next;
                delete head;
                prev->next=nextNode;
                head=nextNode;
            }
            else
            {
                prev=head;
                head=head->next;
            }
        }
    }
};

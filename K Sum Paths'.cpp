// Time complexity - O(N)
// Space complexity- O(N+M)
class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int,int> mp;
        while(head1)
        {
            mp[head1->data]++;
            head1=head1->next;
        }
        
        Node* head(NULL);
        Node* tail(NULL);
        
        while(head2)
        {
            if(mp[head2->data]>=1)
            {
                if(!head)
                {
                    head=head2;
                    tail=head2;
                }
                else
                {
                    tail->next=head2;
                    tail=head2;
                }
                mp[head2->data]--;
            }
            head2=head2->next;
        }
        
        if(!head)
        return NULL;
        
        tail->next=NULL;
        return head;
    }
};
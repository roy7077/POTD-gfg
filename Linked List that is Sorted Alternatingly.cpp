// Time complexity - O(N)
// Space complexity- O(1)
class Solution
{
    public:
    //function to reverse the linked list
    Node* reverse(Node* head)
    {
        Node* h1=head;
        Node* pre=NULL;
        
        while(h1)
        {
            Node* next=h1->next;
            h1->next=pre;
            pre=h1;
            h1=next;
        }
        return pre;
    }
    void sort(Node **head)
    {
        Node* temp=*(head);
        Node* h1=NULL;
        Node* tail1=NULL;
        
        Node* h2=NULL;
        Node* tail2=NULL;
        
        int cnt=0;
        while(temp)
        {
            if(cnt&1)
            {
                if(!h2)
                {
                    h2=temp;
                    tail2=temp;
                }
                else
                {
                    tail2->next=temp;
                    tail2=temp;
                }
            }
            else
            {
                if(!h1)
                {
                    h1=temp;
                    tail1=temp;
                }
                else
                {
                    tail1->next=temp;
                    tail1=temp;
                }
            }
            temp=temp->next;
            cnt++;
        }
        
        if(tail1)
        tail1->next=NULL;
        
        if(tail2)
        tail2->next=NULL;
        
        Node* rev=reverse(h2);
        tail1->next=rev;
    }
};
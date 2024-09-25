// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    Node* reverse(Node* head)
    {
        Node* temp=head;
        Node* prev=NULL;

        while(temp)
        {
            Node* nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        
        return prev;
    }

    int length(Node* head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    bool isPalindrome(Node *head) {
        
        // edge cases
        if(!head)
        return 0;
        
        if(!(head->next))
        return 1;
        
        int len=length(head);
        Node* prev=NULL;
        Node* temp=head;
        int size=len/2;
        
        while(size--)
        {
            prev=temp;
            temp=temp->next;
        }
        
        prev->next=NULL;
        Node* rev=reverse(temp);
        
        temp=head;
        
        while(temp)
        {
            if(temp->data != rev->data)
            return 0;
            
            temp=temp->next;
            rev=rev->next;
        }
        
        return 1;
    }
};

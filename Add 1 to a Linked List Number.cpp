// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Time complexity - O(N)
// Space complexity- O(1) - constant
class Solution {
    public:
    Node* reverse(Node* head)
    {
        Node* pre=NULL;
        Node* h=head;
        
        while(h)
        {
            Node* nextNode=h->next;
            h->next=pre;
            pre=h;
            h=nextNode;
        }
        return pre;
    }
    Node* addOne(Node* head) {
        // reverse linked list
        Node* reverseHead=reverse(head);
        Node* h=reverseHead;
        Node* pre=NULL;
        int carry=1;
        while(h)
        {
            int add=h->data+carry;
            h->data=add%10;
            carry=add/10;
            pre=h;
            h=h->next;
        }
        
        if(carry)
        {
            Node* newNode=new Node(carry);
            pre->next=newNode;
            carry=0;
        }
        
        Node* ansHead=reverse(reverseHead);
        return ansHead;
    }
};



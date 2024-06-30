#include <iostream>
using namespace std;
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    Node* deleteNode(Node* head, int x) {
        int ind=x;
        Node* temp=head;
        while(x>1)
        {
            temp=temp->next;
            x--;
        }
        
        if(ind==1)
        {
            Node* ans=head->next;
            ans->prev=NULL;
            delete head;
            return ans;
        }
        
        
        Node* pre=temp->prev;
        pre->next=temp->next;
        
        if(temp->next)
        temp->next->prev=pre;
        
        delete temp;
        
        return head;
    }
};


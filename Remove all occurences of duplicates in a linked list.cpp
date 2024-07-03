// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        Node* h=head;
        Node* pre=NULL;
        
        while(h)
        {
            int cnt=0;
            while(h->next and h->next->data==h->data)
            {
                cnt++;
                if(pre==NULL)
                {
                    Node* temp=h;
                    h=h->next;
                    delete temp;
                    head=h;
                }
                else
                {
                    Node* temp=h;
                    h=h->next;
                    pre->next=h;
                    
                    delete temp;
                }
            }
            
            if(cnt)
            {
                if(!pre)
                {
                    Node* temp=h;
                    h=h->next;
                    head=h;
                    delete temp;
                }
                else
                {
                    Node* temp=h;
                    h=h->next;
                    pre->next=h;
                    
                    delete temp;
                }
            }
            else
            {
                pre=h;
                h=h->next;
            }
        }
        return head;
    }
};

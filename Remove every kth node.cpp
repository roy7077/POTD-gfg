
/*
 Method - 1
 Recursion
 Time complexity - O(N)
 Space complexity- O(N) - Recursion stack space
*/

class Solution {
    public:
    Node* help(Node* head,int cnt,int& k)
    {
        //base case
        if(!head)
        return NULL;
        
        //recursive calls
        //and small calculation
        Node* temp=help(head->next,cnt+1,k);
        head->next=temp;
        
        if(!(cnt%k))
        {
            Node* nextNode=head->next;
            delete head;
            return nextNode;
        }
        
        return head;
    }
    Node* deleteK(Node *head,int k){
      return help(head,1,k);
    }
};


/*
 Method - 2
 Iterative
 Time complexity - O(N)
 Space complexity- O(1)
*/

class Solution {
    public:
    Node* deleteK(Node *head,int k){
      
      if(k==1 or !head)
      return NULL;
      
      Node* pre=NULL;
      Node* h=head;
      
      int len=0;
      while(h)
      {
        len++;
        if(!(len%k))
        {
            Node* temp=h->next;
            delete h;
            pre->next=temp;
            h=temp;
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
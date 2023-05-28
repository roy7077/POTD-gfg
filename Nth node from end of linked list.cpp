/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#define ll long long

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:

    int getNthFromLast(Node *head, int n)
    {
           ll cnt=0;
           Node* temp=head;
           while(temp!=NULL)
           {
               cnt++;
               temp=temp->next;
           }
           
           if(cnt-n<0)
           return -1;
           
           n=cnt-n;
           while(1)
           {
               if(n==0)
               return head->data;
               
               n--;
               head=head->next;
           }
    }
    
    // time complexity - O(N)
    // space complexity - O(1)
};

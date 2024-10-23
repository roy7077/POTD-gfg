// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
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
    int sumOfLastN_Nodes(struct Node* head, int n) {
        int len=length(head);
        int i=len-n;
        int sum=0;
        while(head)
        {
            if(i<=0)
            sum+=head->data;
            
            head=head->next;
            i--;
        }
        return sum;
    }
};

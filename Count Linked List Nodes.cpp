// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int getCount(struct Node* head) {
        Node* temp=head;
        int cnt=0;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};

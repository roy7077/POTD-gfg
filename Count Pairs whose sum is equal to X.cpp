// Time complexity - O(max(N,M))
// Space complexity- (N)
class Solution{
    public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_map<int,int> mp;
        while(head1)
        {
            mp[head1->data]++;
            head1=head1->next;
        }
        
        int cnt=0;
        while(head2)
        {
            if(mp[x-(head2->data)])
            cnt++;
            
            head2=head2->next;
        }
        return cnt;
    }
};
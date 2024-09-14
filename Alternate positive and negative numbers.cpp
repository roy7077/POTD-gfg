// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    void rearrange(vector<int> &arr) {
        vector<int> pos;
        vector<int> neg;
        for(auto& it:arr)
        {
            if(it>=0)
            pos.push_back(it);
            else
            neg.push_back(it);
        }
        
        int n=arr.size();
        int i=0;
        int j=0;
        int k=0;
        bool turn=1;
        
        while(i<pos.size() and j<neg.size())
        {
            if(turn)
            arr[k++]=pos[i++];
            else
            arr[k++]=neg[j++];
            
            turn=(!turn);
        }
        
        while(i<pos.size())
        {
            arr[k]=pos[i];
            k++;
            i++;
        }
        
        while(j<neg.size())
        {
            arr[k]=neg[j];
            k++;
            j++;
        }
    }
};

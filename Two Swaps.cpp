class Solution {
    public:
    bool checkSorted(vector<int> &arr) {
        int ct=0;
        for(int i=0;i<arr.size();)
        {
            if(arr[i]==(i+1))
            {
                i++;
                continue;
            }
            else  
            {
                swap(arr[i],arr[arr[i]-1]);
                ct++;
            }
        }
        return ct==0 or ct==2;
    }
};

class Solution {
    public:
    void sort012(vector<int>& arr) {
        int i=0;
        int j=0;
        while(j<arr.size())
        {
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
            }
            
            j++;
        }
        
        j=i;
        while(j<arr.size())
        {
            if(arr[j]==1)
            {
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
    }
};

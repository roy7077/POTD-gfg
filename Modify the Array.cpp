class Solution {
    public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                arr[i]*=2;
                arr[i+1]=0;
                i++;
            }
        }
        
        int i=0;
        int j=0;
        while(j<arr.size())
        {
            if(arr[j])
            {
                arr[i]=arr[j];
                i++;
            }
            j++;
        }
        
        while(i<arr.size())
        {
            arr[i]=0;
            i++;
        }
        
        return arr;
    }
};

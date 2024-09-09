// Method - 1
class Solution {
    public:
    void sort012(vector<int>& arr) {
        // sort 0 
        int i=0;
        int j=0;
        while(j<arr.size())
        {
            if(arr[j]==0)
            {
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
        
        // sort 1
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

// Method - 2
class Solution {
    public:
    void sort012(vector<int>& arr) {
        int one=0;
        int zero=0;
        int two=0;
        
        for(auto& it:arr)
        {
            one+=(it==1);
            zero+=(it==0);
            two+=(it==2);
        }
        
        for(auto& it:arr)
        {
            if(zero)
            {
                it=0;
                zero--;
            }
            else if(one)
            {
                it=1;
                one--;
            }
            else
            {
                it=2;
                two--;
            }
        }
    }
};

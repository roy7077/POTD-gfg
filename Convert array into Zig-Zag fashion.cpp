
class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int i=0;
        int j=ceil((double)n/2);
        
        vector<int> temp;
        bool flag=1;
        while(j<n)
        {
            if(flag)
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
            flag=(!flag);
        }
        
        //copy back
        i=0;
        for(auto& it:temp)
        {
            arr[i]=it;
            i++;
        }
        
        // 1 2 3 4 
        // 5 6 7
        // 1 5 2 6 3 7 4
        
        // 1 2 
        // 1 2 3
        
        // 1 4 2 5 3 6
        
        // 1 3 2 4 5
    }
};
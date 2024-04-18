// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> twoRepeated (int arr[], int n) {
        
        int x=-1;
        int y=-1;
        int maxi=1e5+7;
        
        for(int i=0;i<(n+2);i++)
        {
            int ind=arr[i]%maxi;
            int original=arr[ind-1]%maxi;
            int marked=arr[ind-1]/maxi;
            
            if(marked)
            {
                if(x==-1)
                x=ind;
                else if(y==-1)
                {
                    y=ind;
                    break;
                }
            }
            arr[ind-1]=(1*maxi)+original;
        }
        return {x,y};
    }
};



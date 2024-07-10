// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(),arr.end());
        
        int ans=-1;
        for(int i=0;i<arr.size();i++)
        {
            int j=i+1;
            int k=arr.size()-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==target)
                return sum;
                
                if(ans==-1 or abs(sum-target)<abs(ans-target))
                ans=sum;
                else if(abs(sum-target)==abs(ans-target))
                ans=max(ans,sum);
                
                if(sum<target)
                j++;
                else
                k--;
            }
        }
        return ans;
    }
};


// -9 -6 -6 3 4 7 8 8

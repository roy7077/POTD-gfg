
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        
        vector<int> suffix_max(n+1,0);
        for(int i=n-1;i>=0;i--)
        suffix_max[i]=max(suffix_max[i+1],arr[i]);
        
        int i=0;
        int j=0;
        int ans=0;
        
        while(i<n and j<n)
        {
            if(arr[i]<=suffix_max[j])
            j++;
            else
            i++;
            
            ans=max(ans,j-i-1);
        }
        
        return ans;
    }

};